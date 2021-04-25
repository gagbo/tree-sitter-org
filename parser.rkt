;; This is a copy of https://raw.githubusercontent.com/tgbugs/laundry/next/laundry/parser.rkt
;; included for reference. All rights belong to laundry copyright holders.
;; Commit used: 771f236911809d6949bfb26b2e76be22f431cb72
;; it is easier to navigate this file if you use `outline-minor-mode'
#lang brag

;test: /BOF no-headlines-hungry-no-src-end
;test : /BOF headline-content-2

;;; this grammar is newline first NOT newline last

;; even with this limitation you can implement a
;; single pass parser for org-mode if you have a
;; tokenizer that allows you to peek a single char
;; ahead to spot newlines

;;;; introduction

; There are two ways to approach the grammar for org. One is as a
; complete grammar that tries to account all the details in the spec
; and sections of the file the other is a simplified one that deals
; almost entirely with single lines and rarely (in the case of tables,
; comments, and drawers) with groups of multiple lines
;
; IF you can enumerate all the cases by which a paragraph line
; may NOT start, then the grammar can be defined in a way that
; is order free, namely, that there will be no lurking implementation
; details that will/would affect how an org file is parsed depending
; on the order of the rules in the grammar
;
; for the basic elements this is already the case, it cannot be the
; case for headline-node however because there is no finite way
; to not match an arbitrary number of asterisks followed by whitespace
;
; This grammar was implemented using a tokenizer that does not have
; a notion of unicode, much of the complexity of the exiting grammar
; comes from using negative definitions in the grammar to ensure that
; it is closed.
;
; One potential advantage of this is that only the set of charachters
; known and used by the grammar need to be recognized and all of them
; are a single byte.

;;; meta

; how to write a grammar
; identify everything that you will need to negate
; create a tokenizer pattern that recognizes only the negation of that set
; create a tokenizer pattern that recognizes the individual elements that
; you need will need unnegated to assembed (hopefully less than) the full
; combinatorial covering of the less than negated space
; basically, you have to cut out your hole, and then fill it back in for
; each shape that you need to match

;;;; structure

;;; file

org-file : org-node*

org-node : headline-node | org-node-basic

@org-node-basic : affiliated-keyword* ( org-node-basic-element
                                      | double-blank-line
                                      | newline
                                      | bof )

@org-node-basic-element : drawer
                        | blk-dyn
                        | org-nbe-less-d
                        | paragraph ;paragraph-line
                        ; | detached-block-node ; still causing too many issues for well formed blocks

@org-nbe-less-df : block-less-dyn
                 | block-begin-line
                 | block-end-line
                 | babel-call
                 | keyword ; lol yep you can affiliate keywords to keywords
                 | comment-element
                 | table
                 | plain-list-line

@org-nbe-less-d : @org-nbe-less-df
                | footnote-definition

@org-nbe-less-f : @org-nbe-less-df
                | paragraph ; FIXME paragraph-line doesn't know about footnotes yet

@org-nbe-f-in : @org-nbe-less-df
              | paragraph-f-in ; FIXME I'm pretty sure we need org-node-footnote just like org-node-dyn
              | comment-element ; XXX I think comments can be part of footnotes ...

;;;; everything else

;;; paragraph

; paragraphs can contain every type of object
; ended by empty lines and/or other elements
; this is hard because it is the catch all ... the "not anything else"

; a new element could always start on the next line so if we fall
; through we can only fall through for a single line, then we stitch
; it back together in post

paragraph : ( PARAGRAPH @not-newline? | hyperlink @not-newline? | @paragraph-line )+ ; we can actually do this now I think since we have successfully defined paragraphs as the negation of the other elements
paragraph-line : newline-or-bof ( parl-lines | end )
paragraph-line-d : newline ( parl-lines ) ; XXX unused ??
hyperlink : LINK

paragraph-f-in : @paragraph-line-f-in+
paragraph-line-f-in : newline ( parl-lines | misplaced-footnote-definition | end )

misplaced-footnote-definition : footnote-definition-line

parl-indent : @wsnn* ; XXX needed to determine alignment when reconstructing plain lists ; FIXME does this needs to be * not + so that zero indent is straight forward?
@parl-lines : parl-start not-newline?
            | parl-indent parl-se-wsnn
            | stars ; just stars with nothing else is a paragraph
            | wsnn* STARS wsnn*
            | wsnn+

; to prevent keywords this one cannot end with not-newline? has to go all the way to the end
@parl-se-wsnn : digits
              | alphas
              | COLON
              | HASH PLUS COLON not-colon-newline
              | HASH PLUS COLON ; yeah, I tested this, it can't be empty so this is ok
              | HASH PLUS not-colon-newline
              | HASH PLUS ; by itself
              | big-tokes-less-d-s-blk ; TODO the not-colon bits eg ak-key parl-ncn-bt-l-d
              | malformed-wsnn

parl-start : not-pl-start-whitespace1 ; no wsnn char and we're ok
           ; | alpha ; pretty sure this is wrong due to parl-start not-newline? above !? elisp impl doesn't match spec
           ; | alpha-n ; is this ok due to the lists being broken or what?
           ; not-pl-start-newline1 wsnn* not-pl-start-newline1 ; I'm forgetting why we needed to duplicate here?
           ; I think this was just some incorrect late night thinking
           | stars ( not-asterisk-whitespace1 | word-char-n ) ; not-whitespace1 would match another asterisk >_< ; XXX NOTE word-char-n is not word char it is alpha numeric (duh)
           | parl-indent parl-wsnn

parl-ws-bt : not-whitespace1 | big-tokes ; XXX big-tokes-stars ...
parl-ws-bt-l-s : not-whitespace1 | word-char-n | big-tokes-less-s
parl-ncn-bt-l-d : not-colon-newline1 | big-tokes-less-d
parl-prp-bt : not-prp-newline1 | big-tokes
parl-pw-bt : not-plus-whitespace1 | big-tokes | word-char-n ; FIXME word-char vs word-char-n probably can be collapsed into one
parl-wsnn : bt-chars
          ; alpha-n ; can't have alpha-n here because not-newline? will -> aa) at some point
          ; TODO I think markup has to go here?
          ; TODO don't gobble footnote-definition, the intersection of so many complements
          | ( ASTERISK | PLUS | HYPHEN ) parl-ws-bt-l-s
          | wsnn+ STARS ; have to have wsnn+ for disjointness with headings
          | ( digits | alphas ) parl-prp-bt
          | ( digits | alphas ) ( PERIOD | R-PAREN ) parl-ws-bt
          | HASH parl-pw-bt ; #+ and # are claimed but #anythingelse is paragraph ; this was broken due to word-char vs word-char-n issues
          ; FIXME the #+ part of this is a nightmare (not surprisingly)
          | malformed
          ; I think the right answer here is any whitespace before a colon
          ; or no colon, because no whitespace and ANY colon on the line -> keyword
          | HASH PLUS not-whitespace-l-d? wsnn+ not-newline? COLON ; FIXME broken for #+:end: lol: oops
          ; | not-colon-newline COLON not-colon-newline ; FIXME quite broken
          | COLON not-colon-newline
          | NEGATED-SET ; FIXME not sure why these are not being picked up in some other way ...
          | UNDERSCORE ; FIXME WAT WAT WAT
          | AT
          | PERCENT
          | PERIOD
          | L-PAREN
          | R-PAREN ; FIXME maybe also need some others of not-pl-start-whitespace1 ??

malformed : detached-block-node /wsnn* ; XXX this is a risky thing to do :/
          | blk-greater-malformed
          | planning-dissociated
          | ak-key-no-colon
          | babel-call-no-colon

malformed-wsnn : un-affiliated-keyword ; doubling up on not-newline causes issues

un-affiliated-keyword : affiliated-keyword ; FIXME not quite working as desired

;; TODO need to complete the negation of additional forms that can
;; appear at the start of paragraphs

; FIXME and no options
ak-key-no-colon : ak-key parl-ncn-bt-l-d
babel-call-no-colon : CALL parl-ncn-bt-l-d

; TODO negate
no-colon-no-keywords : CALL nc-start
parl-ncln-bt-l-d : not-colon-lsb-newline1 | big-tokes-less-d
nc-start : parl-ncln-bt-l-d
         | LSB not-rsb-newline1
         | COLON

;;;; *

;;; headlines

;; it is pretty much impossible to parse headlines
;; newline first grammar makes it impossible to parse * H :n: :t:
;; todo-keywords can only be known at runtime * EXPIRED [#A] could be just a title
;; It is possible to write a negated grammar for COMMENT but it pushes enormous
;; complexity into the lexer, ON THE OTHER HAND a second pass parsers is MUCH
;; easier to write a grammar for!

; both planning and property drawer can only have a single newline each before them
headline-node : headline ( newline ( planning | planning-malformed ) )? property-drawer? ; FIXME property drawers broken again
headline : HEADING | newline-or-bof stars @wsnn+ headline-content? ; XXX do we force normalize to a single space in headlines? XXX probably need to preserve wssn+ due to the fact that we are going to reparse and thus would lose srcloc
stars : ASTERISK | STARS ; ASTERISK+ destorys performance
headline-content : @not-newline

; we don't use the simplest form to avoid parsing the stars twice
; headline : stars /wsnn+ @not-newline

;;; planning

; XXX this is the grammar that matches the spec
;planning : ( /wsnn* plan-info )+ /wsnn*

; XXX this is the grammar that matches the current elisp org-element
; it is probably preferable to use this one because it makes it possible
; to get a valid parse of a planning line even as someone is typing away
; it is probably worth the additional complexity to make it possible to
; run a parser every single time a new char is typed and still be able
; to get a correct parse for the line, especially since these things
; are the first line after a heading

; FIXME negating timestamps adds massive complexity to the tokenizer
; because you have to account for digits-2 and digits-4 separate from
; digits-n which would be a pain, the spec says that planning lines
; shall only contain repeated planning info elements so I think that
; we could also parse malformed planning lines for consistency but
; not actually do anything with them

; XXX and yet here we are, we need those to parse dates correctly
; anyway, so we can probably manage

;-not-plan-keyword-timestamp-newline : not-newline ; TODO
;not-plan-keyword-timestamp-newline : ( unsyms-less-timestamp | ns-nwt-less-negated | wsnn | word-char-n ) ; not-timestamp-plan-newline
                                   ;| plan-keyword not-colon-newline

planning : ( plan-sep plan-info )+ /wsnn* ;not-plan-keyword-timestamp-newline?
plan-sep : /wsnn*
;plan-sep : /wsnn* | not-plan-keyword-timestamp-newline /wsnn

planning-malformed : plan-mal-info+
plan-mal-info : plan-mal-sep? plan-keyword /COLON plan-mal-sep? ; XXX will gobble?
plan-mal-sep : not-plan-keyword-timestamp-newline
             | plan-keyword not-colon-newline

plan-info : plan-keyword /COLON /wsnn* plan-timestamp?
plan-keyword : plan-dead | plan-sched | plan-open | plan-close
plan-timestamp : timestamp
plan-dead : CHARS-DEADLINE
plan-sched : CHARS-SCHEDULED
plan-open : CHARS-OPENED ; XXX suggested improvement
plan-close : CHARS-CLOSED

planning-dissociated : planning

;;; headline runtime parsing

; note that even in this setting COMMENT cannot be a todo keyword
; becuase it will require a change to the lexer since COMMENT would
; appear in two places in the grammar which would force the grammar
; to change, which it can't, I really don't like reserved words anywhere
; in a grammar, but if there are going to be headline comments then we
; will deal with it

headline-content-2 : h-rt-todo-keyword /wsnn+ h-rt-mid? h-rt-tags?
                   | h-rt-todo-keyword /wsnn*
                   | h-rt-mid-no-rtk? h-rt-tags?
                   | h-rt-mid-weird? h-rt-tags?
                   | h-rt-mid-no-rtk
                   | h-rt-tags-tail?

h-rt-mid-common : h-priority /wsnn* h-comment h-rt-title?
                | h-priority /wsnn* h-rt-title-not-comment?
                ; TODO I think we need to unnegate lsb at some point here?
                | h-comment h-rt-title? ;h-rt-tags?

h-rt-mid : h-rt-mid-common
         | h-rt-title-not-comment?; h-rt-tags?

h-rt-mid-no-rtk : h-rt-mid-common
                | h-rt-title-not-comment-rtk?; h-rt-tags?

; this will mark the line as weird because there is a todo keyword at the start of the title
h-rt-mid-weird : h-rt-mid-common
               ; we don't have to worry about insanity like a todo keyword of COM ending with MENT
               ; the tokenizer will save us from that
               | h-rt-title-weird ; note the lack of a space ; FIXME kna needs to be part of title here

h-rt-title-weird : h-rt-todo-keyword-not-active h-rt-title?
                 | h-rt-todo-keyword-not-active h-rt-tags-missing-space?
h-rt-todo-keyword-not-active : @h-rt-todo-keyword
h-rt-tags-missing-space : @h-tags wsnn* newline

;asdf : h-priority h-comment? h-rt-title-not-comment? h-rt-tags?
                 ;| h-rt-title-begin not-newline? h-rt-title-end
                 ;| h-rt-title-single

;h-rt-tail : h-priority? h-ctt? h-rt-tags? /wsnn*
          ;| h-priority h-rt-title?
          ;| h-rt-title

h-rt-todo-keyword : RUNTIME-TODO-KEYWORD ; configure the tokenizer at runtime
h-rt-title : @h-ctt-start
h-rt-tags : /wsnn+ h-rt-tags-tail
h-rt-tags-tail : @h-tags wsnn* newline-or-eof ; XXX really I need to be able to get token-EOF


; TODO will need to incorporate this into the h-rt-title-begin

headline-chars-complex : not-lsb-whitespace1
                       | LSB not-hash-newline1
                       | LSB HASH not-rsb-newline1 not-rsb-newline1 ; XXX example of where NEGATED-SET being more than one char hurts us?
                       | LSB HASH RSB not-rsb-newline1 ; the workaround is simple enough

not-tags : not-colon-newline wsnn* newline-or-eof ; block ending with colon
         | not-tag-whitespace tags-contents wsnn* newline-or-eof ; seriously, this is all you need XXX FALSE I was right that we had to handle the fact that not-tag-newline tag-contents allows whitespace COLON to happen
         | not-tag-newline not-colon-whitespace1 tags-contents wsnn* newline-or-eof

; * :a: b:cd:
; * :a: b:cd:
; * :a: b:cd:
; * :a: b:cd:
; * :a:!b:cd:
; * :a:-b:cd:

; not ( tag contents + COMMENT + todo keywords ) ? ARCHIVE ? I think it is ok given wsnn+ before h-tags?
; those are the only single tokesn we need to ban
; a single char can't match properties so we are ok
; then we refine such that
; todo keywords can be included in the start of the one that comes after todo keywords
; comment can be included after comment

h-rt-title-begin : not-COMMENT-RTK-lsb-whitespace
; TODO as with all negated, specify the full set so you know that you are closed
; then add back the patterns that are ok to match
h-rt-title-end : not-tags
h-rt-title-single : not-COMMENT-RTK-lsb-tag-whitespace ; a lot o nots

h-rt-title-not-comment-rtk : h-rt-title-begin @not-newline? h-rt-title-end
                           | h-rt-title-single

;h-rt-title-not-comment : ( h-rt-title-begin | CHARS-COMMENT ) @not-newline? h-rt-title-end
; FIXME h-comment somehow does not take priority over this but I don't think we needed CHARS-COMMENT
; here anyway or at all, because h-rt-title-not-comment does not come _after_ h-comment, it comes _beside_ it
; XXX no, just a bug, this was supposed to be adding RTK back in
h-rt-title-not-comment : ( h-rt-title-begin | RUNTIME-TODO-KEYWORD ) @not-newline? h-rt-title-end
                       | h-rt-title-single

;; comment

h-comment : CHARS-COMMENT ; XXX implementation note the elisp impl does NOT require a space following comment
; org-element is inconsistent with fontification here

;; priority
h-priority : @priority
priority : /LSB /HASH priority-level /RSB
priority-level : not-whitespace1 ; XXX spec and impl are divergent here ; XXX LOL [#$] is a valid priority in the elisp impl XXX this is safe under NEGATED-SET+
; spec says "a single letter" impl works with any char
; XXX fontification bug highlighting only works with uppercase and digit

;; tags

; XXX the spec is extremely unclear about how tags work
; org-element behavior is currently that you MUST have a non-empty title
; in order for tags to actually be tags the impl for structured
; editing interaction and formatting is inconsistent with this but
; only when the not-actually-tag is separated by a space from the
; priority cookie or TODO keyword I _suspect_ that this is either a
; bug or a conscious design decision, I personally have been annoyed
; by not being able to have tagged nameless headlines, but in a sense
; it does simplify the grammar a bit

h-tags : ( tag-start | tag-archive )+ /COLON
@tag-start : /COLON tag-name
tag-name : @tag-name-parts* ; XXX spec unclear behavior inconsistent ; XXX change: empty tags for regularity
tag-name-parts : word-char-n | word-char | UNDERSCORE | AT | HASH | PERCENT
tags-contents : ( @tag-name-parts | COLON | ARCHIVE )+
; org-element allows empty tags and interaction layer recognizes them
; IF THEY ARE NOT BY THEMSLEVES AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
; XXX my suggestion is either to allow empty tags or to fix the elisp implementation

; FIXME any alpha-numeric char ... UTF? not-whitespace ??? probably not ?
;tag-archive : /COLON CHARS-ARCHIVE
tag-archive : ARCHIVE

;;;;;;;;;;;;;;;; XXX unused
h-ctt : ( h-comment | @not-whitespace ) @not-newline? not-tags
      | ( h-comment | @not-whitespace )? not-tags
      | h-comment

h-ctt-start : ( h-comment | @headline-chars-complex ) @not-newline? not-tags
            | ( h-comment | @headline-chars-complex )? not-tags
            | h-comment
;;;;;;;;;;;;;;;; XXX unused

;;;; :

;;; drawers

; property drawers are defined by both position and by structure
; due to the bad backtracking behavior in brag it is not possible
; to parse a property drawer correctly if it hits a point where it
; must backtrack because the regular drawer will take precednece
; this is EXTREMELY annoying and there is no way around it
property-drawer : pdrawer-unparsed | newline wsnn* properties node-property* /nlws end
; NOTE when this fails to parse, it WILL parse as a regular drawer
pdrawer-unparsed : DRAWER-PROPS
properties : PROPERTIES-D ; COLON "properties" COLON
end : END-D ; COLON "end" COLON
plus : PLUS
node-property : /newline wsnn* /COLON property-name plus? /COLON [ property-value ] ; the spec does not say it but the implementation allows value to be empty
; the spec for node-property and the implementation are different
; the second wsnn is not documented but is required
; plus is optional but the spec says that empty names are not allowed
; this is false :+: will produce a property whose value is the empty string
; our implementation _will_ break in the case where the elisp one succeeds
; note also that elisp org upcases all property values
property-name : @not-whitespace* @not-plus-whitespace1
property-value : wsnn+ not-newline{,1} ; wsnn{1} also valid here since not-newline will matchs wsnn{2,}

; NOTE you cannot nest drawers, an internal drawer heading inside another drawer
; is just text, though it does highlight incorrectly
; XXX the grammer becomes more complicated because regular drawers are allowed to match properties
; this means that we have to fully specify how drawers and property drawers because the ambiguity
; in the grammar is exploited by the parser to increase performance
drawer : DRAWER | drawer-spec | pdrawer-unparsed ; XXX pdrawer-unparsed issues here
@drawer-spec : newline-or-bof wsnn* ( /COLON drawer-name /COLON | ARCHIVE /COLON | properties ) wsnn* drawer-contents? /nlws end ; XXX the second wsnn* is undocumented
drawer-name : @wordhyus ; A-Za-z0-9_- (rx word) (explicilty not + apparently?) ; FIXME word constituent ???
;drawer-contents : ( newline @not-newline )* ; FIXME big issue with headlines

; drawer-contents : no-headlines ;( newline @not-newline? )+ ; the simple version
drawer-contents : org-node-d* ; FIXME I'm kind of expecting fallthrough due to ambiguity here? also big issue with the fact that paragraph-lines inside of drawer need to not match :end:
org-node-d : affiliated-keyword* ( org-nbe-less-d | paragraph-line-d | newline )

;;;; #

;;; comments

comment-element : ( COMMENT-ELEMENT | comment-line)+ ; remember kids one-or-more != one-and-maybe-more?
comment-line : newline-or-bof wsnn* HASH ( wsnn+ @not-newline? )?

;;; keywords

@nlbofwsnn : /newline-or-bof wsnn*
babel-call : nlbofwsnn CALL /COLON not-newline?

keyword : todo-spec-line | nlbofwsnn @keyword-line ; FIXME todo-spec-line probably needs to be top level
keyword-line : ( /HASH /PLUS keyword-key | kw-prefix ) keyword-options? /COLON /wsnn+ keyword-value? ; FIXME check on the /wsnn+ here
kw-prefix : AUTHOR | DATE | TITLE ; FIXME these should just go in not-whitespace probably
keyword-options : LSB not-newline RSB ; FIXME this is almost certainly incorrectly specified

todo-spec-line : TODO-SPEC-LINE

affiliated-keyword : nlbofwsnn @affiliated-keyword-line
affiliated-keyword-line : ak-key keyword-options? /COLON /wsnn+ keyword-value?
; ak-key defines which keywords can affiliate
ak-key : CAPTION | HEADER | NAME | PLOT | RESULTS | ak-key-attr

-keyword-line : ( /HASH /PLUS keyword-key | END-DB | AUTHOR | DATE | TITLE ) /COLON keyword-value? ; elisp does longest match to colon
              | /HASH /PLUS keyword-key-sigh keyword-value-sigh?

; last colon not followed by whitespace is what we expect here
; XXX NOTE current elisp behavior has ~#+begin:~ as a keyword, I think this is incorrect
keyword-key : not-whitespace ; FIXME this should include author date and title surely?
keyword-value : not-newline

keyword-key-sigh : END-D | PROPERTIES-D
keyword-value-sigh : not-colon-newline ; like with paragraph we have to defend against colons down the line
                   | not-whitespace-l-d? wsnn+ not-newline? COLON not-newline?

;kw-prefix : kw-author | kw-date | kw-title
;kw-author : AUTHOR
;kw-date : DATE
;kw-title : TITLE

;;; affiliated keywords

-affiliated-keyword : /newline-or-bof wsnn* ak-key /COLON /wsnn+ ak-value ; leading whitespace on the value is not explicitly in the spec
ak-value : @not-newline
-ak-key : ak-key-opt | ak-key-attr | ak-key-no-opt
@ak-key-no-opt : ak-key-name-no-opt
; but apparently AUTHOR DATE TITLE can also have opt??
; caption author date title all can contain objects?
; what are those?
@ak-key-name-no-opt : header | name | plot ; | ak-key-maybe-opt
;; @ak-key-maybe-opt : AUTHOR | DATE | TITLE  ; XXX the syntax document is EXTREMELY confusing here
; these three are very much not affiliated keywords, they do not and
; will not affiliate to anything, despite this they are listed in the
; affiliated keywords section
ak-key-attr : ATTR-PREFIX attr-backend

header : HEADER
name : NAME
plot : PLOT
attr-backend : @wordhyus

; not clear whether this should be enforced here
; I don't think that it is actually part of the
; syntax at all
; multi is caption header and attr
; affiliated-keywords-multi
; affiliated-keywords-single

ak-opt : LSB not-newline RSB
ak-key-opt : ak-key-name-opt ak-opt
ak-key-name-opt : caption | result
caption : CAPTION
result : RESULT

;;; blocks

; ugh, matching the arbitrary names here is ...
; not something I think that brag can handle in
; an elegant way because the block-type-name has
; to match ... maybe possible but I don't know how
; to do it or maybe we just don't enforce the
; matching here because we don't actually need to?
; basically, you can't determine the well formedness
; of an org-file from just its syntax because you need
; a stack to keep track of which block you are in

@block-less-dyn : ( blk-src | /newline-or-bof blk-ex ) ; FIXME do we really / the newline here? I guess?

; NOTE greater blocks that do not have a special status e.g. src blocks for babel
; can only be determined to be malformed during a later pass, not by the grammar alone
block-begin-line : /newline-or-bof wsnn* blk-greater-begin
block-end-line : /newline-or-bof wsnn* blk-greater-end ; FIXME paragraph vs out of place end line

blk-ex : blk-ex-begin blk-ex-contents nlpws blk-ex-end
blk-ex-begin : BEGIN-EX wsnn blk-line-contents | BEGIN-EX
blk-ex-end : END-EX ; wsnn*? or we deal with that elsewhere ?
blk-ex-contents : no-headlines ; XXX watch out for greedy ?


; XXX NOTE these WILL mispair and have to be processed in a second step
; if this happens, the parse results up to the start of next heading cannot
; be trusted and should be considered to be incorrect
blk-greater-begin : blk-greater-type wsnn blk-line-contents | blk-greater-type

blk-greater-end : END-BLOCK block-type-name | bg-end-special
bg-end-special : END-SRC block-type-rest ; these are for things like #+end_srclol
               | END-EX block-type-rest

blk-greater-type : BEGIN-BLOCK block-type-name | bg-type-special
bg-type-special : BEGIN-SRC block-type-rest ; these are for things like #+begin_srclol
                | BEGIN-EX block-type-rest

blk-greater-malformed : ( END-BLOCK | BEGIN-BLOCK ) /wsnn* ; if this occures alone
block-type-name : @not-whitespace ;| CHARS-COMMENT | CHARS-ARCHIVE ; CHARS- are in not-whitespace via big-tokes
block-type-rest : @not-whitespace


blk-dyn : /newline-or-bof blk-dyn-begin blk-dyn-contents newline blk-dyn-end
; XXX elisp impl requires at least wsnn after #+begin: to work
; FIXME NOTE #+begin: asdf is just a keyword if there is no #+end found
blk-dyn-begin : BEGIN-DB /COLON wsnn blk-line-contents? | BEGIN-DB /COLON ; XXX suggested improvement
; #+begin: without at least whitespace is tably and org-elemently not the start of a dynamic block
; I suppose there might be some completely insane people that use #+begin: without anything following
; it for some other purpose, but really?
blk-dyn-end : END-DB /COLON
blk-dyn-contents : org-node-dyn* ;anything except #+end: basically
org-node-dyn : affiliated-keyword* ( drawer | org-nbe-less-d | paragraph-line | newline )

@no-headlines : ( PARAGRAPH @not-newline? | line-not-headline)+
@line-not-headline : newline+ @start-not-headline @not-newline?
                  ; | paragraph ; XXX pretty sure that paragraph should not be needed here and that #+end_ forms should never be parl
                  ;| newline ; XXX not-newline? other elements? XXX cannot have newline by itself it will eat incorrectly
; not clear what order to do this in, parse to the end of the drawer in one go and then
; reparse its contents as org elements? we don't have an intersectional parser here
; using no-headlines it is possible to parse blocks all the way to the end without issue, which
; might be nice ... at least for src and ex blocks, it also makes everything clearer
; the tradeoff for drawers is that you really do have to do a second pass to match org
; behavior, because drawers can contain any other element we might be able to do this
; just by adding other org nodes as contents of the drawer? except other drawers as
; pointed out by the spec ...

@start-not-headline : @not-asterisk-newline1 | stars @not-asterisk-whitespace1 | @word-char-n

; I suspect that we can use complex | simple as a way to try to parse things that can fail
; that we do not what to fall through
blk-line-contents : @not-newline
blk-line-rest : @not-newline

detached-block-node : det-blk-src-begin
                    | det-blk-src-end
                    | det-blk-ex-begin
                    | det-blk-ex-end

det-blk-src-begin : blk-src-begin
det-blk-src-end : blk-src-end
det-blk-ex-begin : blk-ex-begin
det-blk-ex-end : blk-ex-end

blk-src : SRC-BLOCK | /newline-or-bof blk-src-begin blk-src-contents? nlpws blk-src-end
;blk-src : blk-src-begin newline blk-src-contents? wsnn* blk-src-end
blk-src-begin : ( BEGIN-SRC wsnn blk-src-line-contents | BEGIN-SRC ) /wsnn*
;blk-src-begin-malformed : BEGIN-SRC /wsnn* newline ; FIXME newline first grammar issues :/
blk-src-end : END-SRC /wsnn*
blk-src-contents : no-headlines ; FIXME we just need the bounds for the contents of the block for 2nd pass?
;blk-src-contents : no-headlines-hungry-no-src-end ; this is a version that eats newlines
blk-src-line-contents : language wsnn blk-src-line-rest-alt | language wsnn*
language : @not-whitespace ; FIXME

;no-headlines-hungry-no-src-end : line-not-headline-not-src-end+
;line-not-headline-not-src-end : newline* start-not-headline not-newline-not-src-end newline

;;; switches XXX

; still evil but these are a little less evil

; switches and headlines are probably tied for the most aweful parts of the whole grammar

; the drafts of this section of the grammar before I removed the
; special case for -l were probably the inspiration for some of the
; more sanity destorying pages of the Necronomicon

; these should be removed from org-mode ASAP and replaced
; ideally with header arguments which are general and extensible
; before that can happen there needs to be an upgrade path for existing users

blk-src-line-rest-alt : switches-sane /wsnn blk-src-args-after-switches-sane
                      | switches-sane
                      | @not-switch @not-newline?

@--test--switches-sane : /BOF? switches-sane
switches-sane : ( switch-sane ( /wsnn format-string )? /wsnn )* switch-sane ( /wsnn format-string )?
switch-sane : switch-sign alpha
last-switch-string : wsnn format-string

@switch-sign : PLUS | HYPHEN

not-switch : @not-plus-hyphen1
| PLUS   @not-alpha-newline1
| HYPHEN @not-alpha-newline1
| PLUS   @alpha @not-whitespace1
| HYPHEN @alpha @not-whitespace1

blk-src-parameters : COLON not-newline ; TODO
; NOTE the correct parameters grammar is a subset of
; the not-a-format-string grammar since it starts with colon
                   | wsnn+ COLON not-newline ; TODO

@blk-src-args-after-switches-sane : blk-src-parameters
                                  | not-dq-ph-newline not-newline? ; TODO not-dq-ph-colon-newline for params
                                  | switch-sign not-alpha-newline1 not-newline?
                                  | switch-sign ( @alpha @not-whitespace | @word-char-n ) @not-newline?
                                  | blk-src-args-broken ; XXX user done goofed

; you may have a dq there but then no more dq at all on the line
; this will be extremely weird, but could happen
blk-src-args-broken : DQ not-dq-newline?

format-string : /DQ format-string-contents /DQ
; TODO other escape sequences
format-string-contents : ( @not-bs-dq-newline | /BS DQ | BS )+

string : DQ string-contents DQ
; TODO other escape sequences
string-contents : ( @not-bs-dq | /BS DQ | BS )+

;;;; |

;;; tables

;table : ( table-row | table-row-rule )+
table : table-row+
table-dumb : /newline-or-bof /PIPE @not-newline ; as a matter of last resort
table-row : /newline-or-bof /wsnn* table-cell+ /PIPE?
;table-cell : /PIPE @not-pipe-not-newline? ; this is NOT ambiguous the minimal match is /PIPE+ PIPE? !??!?!
table-cell : /PIPE /space? ( @not-pipe-bs-newline | /BS PIPE | BS )* /space? ; XXX divergence
table-row-rule : /newline-or-bof /wsnn* /PIPE /HYPHEN /not-newline? ; everything else gets wiped

;;;;

;;; plain lists

plain-list-line : /newline-or-bof pl-indent ( ordered-list-line | descriptive-list-line )
pl-indent : @wsnn*
ordered-list-line : bullet-counter plain-list-line-tail?
bullet-counter : ( digits | alphas-unmixed ) ( PERIOD | R-PAREN )
;; XXX NOTE the worg spec is inconsistent with behavior, single letters DO NOT WORK AS COUNTERS
;; TODO ARGH, I've never checked what the org-export backends do O_O AAAAAAAAAAAAAAAAAAAA
;; yet another part of the elisp implementation to deal with FFS
;; html and tex export backends do not support letters in the bullet counter

descriptive-list-line : bullet-plain plain-list-line-tail?
bullet-plain : HYPHEN | PLUS | wsnn+ ASTERISK

plain-list-line-tail : @wsnn+ @not-newline | @wsnn+ ; sadly we have to use the dumb parser here due to ambiguity
;plain-list-line-tail : wsnn+ counter-set? check-box? plain-list-tag? not-newline | wsnn
; TODO this can be negated I think
plain-list-yes-we-can : counter-set check-box plain-list-tag not-newline?
                      | counter-set           plain-list-tag not-newline?
                      |             check-box plain-list-tag not-newline?
                      |                       plain-list-tag not-newline?
                      | counter-set check-box pl-not-tag?
                      |             check-box pl-not-tag?
                      |             check-box
                      | counter-set pl-not-check-box?
                      | pl-not-counter-set not-newline? ; technically

;                     | counter-set check-box plain-list-tag not-newline?

pl-not-counter-set : not-lsb-at-digits-newline
                   | LSB not-at-newline1
                   | LSB AT not-digits-newline
                   | LSB AT digits not-rsb-newline

pl-not-check-box : pl-not-check-box-start not-newline?

pl-not-check-box-start : not-lsb-space-X-hyphen-newline
                       | LSB not-space-X-hyphen-newline1
                       | LSB space-X-hyphen not-rsb-newline1

space-X-hyphen : space | CHAR-UPPER-X | HYPHEN

; XXX spec is unclear and I can't find anything obvious in org-element
; essentially you can't have two colons appear anywhere on the line, I'm not sure whether
; the plain-list-tag can be empty, but since I'm moving to allow empty tags for regularity
; it is consistent to allow empty tags here, also the plain list tag does NOT follow the
; same syntax as headline tags ... it is literally anything until the last paired colons on the line
pl-not-tag : not-colon-newline
           | ( not-colon-newline? COLON )+ not-colon-newline?

counter-set: LSB AT counter-set-content RSB  ; wow this is useful!
counter-set-content : digits
check-box : LSB ( cb-todo | cb-in-process | cb-done ) RSB
cb-todo : space
cb-in-process : HYPHEN ; started ?
cb-done : CHAR-UPPER-X ; AAAAAAAAAAAAAAAAAAAAAAAA ;_; complexity XXX

; TODO check if this taints lowercase as well
plain-list-tag-text : @not-newline
plain-list-tag : pl-tag-end
pl-tag-end : COLON COLON

;;;; [

;;; footnotes

; XXX impl note: these bind the paragraph that follow them ... but they do it
; differently than other elements, probably due to ... who knows? what differences
; in the implementation, actually they bind all elements that follow them except for
; a double blank line
footnote-definition : footnote-definition-line org-node-f*

@org-node-f : affiliated-keyword* ( org-nbe-less-f | blank-line )
@org-node-f-in : affiliated-keyword* ( org-nbe-f-in  | blank-line )

footnote-definition-line : newline-or-bof FOOTNOTE-START fn-label RSB fn-def

fn-def : @not-newline? org-node-f

footnote-anchor : footnote-inline | footnote-marker
; NOTE fn-defs must start at column 0, not 100% sure what that means
footnote-inline : FOOTNOTE-START-INLINE fn-def-inline RSB ; FIXME the tokenizer for this is :/ [fn:: !?
;ootnote-contents : not-rsb ; FIXME I'm pretty sure there is a nasty bug in the elisp impl where
                            ; footnotes don't do shortest match, they do longest match
                            ; FIXME this naieve definition also fails to correctly manage
                            ; unbalanced parents
fn-def-inline : @not-newline? org-node-f-in ; FIXME actually this might just be org-node-basic ?? but what the heck would it mean to have a footnote definition typeset INSIDE a footnote definition? I bet it just won't render and there will be no warning?
footnote-marker : FOOTNOTE-START fn-label RSB
fn-label : wordhyus

;;;; <[

;;; timestamps

; the org spec is currently silent on how org will handle dates beyond
; 0000 and 9999, the relevant standards for expanded representations
; are ISO 8601-1:2019,5.2.2.3 and ISO 8601-2:2019,8.4.3. The problem
; with expanded representations is that they require all parties to
; agree ahead of time how wide the year is and prefix with + and
; leading zeros, I am not sure that this is as robust as we would like
; 0000-01-01 is january first of the year zero, -0001-01-01 is jan
; first of the year 1BCE, and +10000-01-01 for jan 1 of 10000CE 5
; digits must be prefixed by the plus sign, the standard is not
; entirely clear, but I think that we could do PLUS digits HYPHEN
; or DIGIT-4 HYPHEN and everything would work out

; on a separate but related note, org timestamps are always in local
; time and do not currently support timezones, which is a problem

; further absurdities that are related to the timezone issue: the
; date/time implementation as a text format completely fails if
; authoring on another planet

; given my objective to ensure that org documents can be interpreted
; without having to stick stupid things like #+planet: mars in the
; header or risk your earthling readers getting incorrect dates --- I
; suggest that org switch to storing all dates and times in earth zulu
; time or with an offset as it stands, the timezone setting of the
; computer drafting the document must be known to determine what day
; it was etc. users could still draft using <2020-12-16> but C-c C-c
; would add the correct offset? actually this is tricky, because there
; are two cases, one where the location is clear, "napoleon on [1812-01-01]"
; and the other where it is not, the issue is that a single date refers
; to as many different time intervals as there are timezones and without
; knowing the timezone you don't know the date, similar issue if we were
; to try to convert to sols
; https://www.eecis.udel.edu/~mills/missions.html
; https://www.eecis.udel.edu/~mills/ipin.html
; https://en.wikipedia.org/wiki/Timekeeping_on_Mars
; HOWEVER having applied a bit more brain power to the problem, let's
; just assume that clock synchonization will happen between earth and
; mars so that the unix epoch could be synchronized between the frames
; probably with multiple reference stations in free fall and/or in deep
; space to account for gravitaitonal differences etc. so actually the
; only issue would be a practical notational one, or a UI one, since we
; can use timestamp with timezone or just straight epoc for this to work
; earth vs martian year/day is a much harder issue

; ([+-][0-9]\+|[0-9]{4})(-[0-9]{2}){2}
; ([0-9]{2}:[0-9]{2}(:[0-9]{2}(,[0-9]{1,9})?)?[+-][0-9]{2}:[0-9]{2})?
; followed by an optional day of the week and then the repeat or delay for example
; [+10000-01-01 10:11:00,992315771-04:00 Sat]
; or more temporally local
; [2021-03-03 17:43-07:00 Sat]

timestamp : ts-diary | ts-active | ts-inactive | ts-range-active | ts-range-inactive
ts-diary : LAB "%%" L-PAREN ts-diary-sexp R-PAREN RAB ; this spec doesn't make any sense
;  SEXP can contain any character excepted > and \n.
ts-diary-sexp : NOT-RAB-NOT-NEWLINE+
ts-active : /LAB date ( /space+ time )? ts-rod? /RAB
ts-inactive : /LSB date ( /space+ time )? ts-rod? /RSB
ts-range-active : ts-active /hh ts-active | /LAB date /space+ time /HYPHEN time ts-rod /RAB
ts-range-inactive : ts-inactive /hh ts-inactive | /LSB date /space+ time /HYPHEN time ts-rod /RSB
hh : HYPHEN HYPHEN

;; better to handle date correctness outside the parser to reduce token complexity
;; date
date : @date-normal | @date-ex
@date-suffix : /HYPHEN month /HYPHEN day ( space+ day-abbrev )?
date-normal : year date-suffix
year : DIGIT-4
month : DIGIT-2
day : DIGIT-2
date-ex : date-sign year-ex date-suffix
year-ex : digits ; XXX pretty sure this is abuse of notation for iso8601 but whatever
date-sign : PLUS | HYPHEN

;; time
time : hour /COLON minute
hour : DIGIT-2
minute : DIGIT-2
day-abbrev : not-lsb-hy-plus-digit-whitespace ; FIXME non whitespace not + - ] > DIGIT \n

;; repeat or delay
ts-rod : ts-rod-entry ts-rod-entry?  ; FIXME one repeater and one warning delay? not sure what this is
ts-rod-entry : ts-rod-mark ts-rod-value ts-rod-unit
ts-rod-mark : "+" | "++" | ".+" | "-" | "--"
ts-rod-value : digits
ts-rod-unit : "h" | "d" | "w" | "m" | "y"

;;;; @

;;; export snippets

export-snippet : at-at esnip-name COLON esnip-value at-at
esnip-name : wordhy
esnip-value : not-at-at
at-at : AT AT
not-at-at : ( @not-at1 | ( AT @not-at1 ) )+

;;;;

;;; ???????

;clock
;inline-task
;item
;section

;;;; tokens

;;; whitespace

;; the elisp org parser parses whitespace as significant
;; XXX suggestion: disallow all leading whitespace or invoke undefined behavior

@newline-or-bof : newline | /BOF
@newline-or-eof : newline? ; XXXXXXXXXXXXXXXXX this might might might work if no major structure starts with a newline, we will be able to test that once the newline first form is working
nlws : newline ( tab | space )* ; TODO FIXME this has to be parsed as significant whitespace
nlpws : newline+ ( tab | space )* ; variant to handle cases like #+end_src ; TODO FIXME this has to be parsed as significant whitespace
whitespace : newline | space | tab
@wsnn : tab | space ; FIXME need other whitespace chars FIXME need to move multi whitespace to tokenizer

;; this isn't going to work is in ;_;
blank-line : newline /newline ; please tell me that cutting backtracks, that would be beyond wonderful
double-blank-line : newline newline /newline

bof : /BOF
newline : NEWLINE ; FIXME in many cases we also need to accept BOF here

space : SPACE ; TODO SPACE-N needs to be a lexeme which will cause a branch in here
tab : TAB
; FIXME missing a bunch of other things that count as whitespace
;bof : BOF ; FIXME this doesn't work

;;; big

bt-asterisk : STARS

bt-colon : END-D | PROPERTIES-D

bt-chars : CHARS-ARCHIVE
         | ARCHIVE ; starts with colon but doesn't end with it to simplify tag parsing, replaced CHARS-ARCHIVE

bt-chars-plan : CHARS-OPENED
              | CHARS-CLOSED
              | CHARS-DEADLINE
              | CHARS-SCHEDULED

bt-chars-no-title-start : CHARS-COMMENT
                        | RUNTIME-TODO-KEYWORD

; missing colon plus the other two ???? things that can be followed by whitespace or not a colon?
bt-hash : CALL ; parl ok
        | NAME | HEADER | PLOT | AUTHOR | DATE | TITLE | RESULT | CAPTION | ATTR-PREFIX ; park ok via ak-key
        | BEGIN-DB | END-DB

bt-blk-begin : BEGIN-BLOCK
             | BEGIN-SRC
             | BEGIN-EX

bt-blk-end : END-BLOCK
           | END-SRC ; parl ok via detached-block-node
           | END-EX ; parl ok via detached-block-node

bt-blk : bt-blk-begin | bt-blk-end

bt-lsb : FOOTNOTE-START | FOOTNOTE-START-INLINE

big-tokes-less-d-s-p-cnt-blk : bt-lsb
                             | bt-hash
                             | bt-chars

big-tokes-less-d-s-blk : big-tokes-less-d-s-p-cnt-blk
                       | bt-chars-no-title-start
                       | bt-chars-plan

big-tokes-less-s-blk : big-tokes-less-d-s-blk
                     | bt-colon

big-tokes-less-s-src-end : big-tokes-less-s-blk
                         | bt-blk-begin
                         | END-BLOCK | END-EX

big-tokes-less-src-end : big-tokes-less-s-src-end
                       | bt-asterisk

big-tokes-less-s-ex-end : big-tokes-less-s-blk
                        | bt-blk-begin
                        | END-BLOCK | END-SRC

big-tokes-less-ex-end : big-tokes-less-s-ex-end
                      | bt-asterisk

big-tokes-less-d-s-p-cnt : big-tokes-less-d-s-p-cnt-blk
                         | bt-blk

big-tokes-less-COMMENT-RTK : big-tokes-less-d-s-p-cnt
                           | bt-asterisk
                           | bt-colon ; spidy sense say that h-rt-title-single is going to need to drop this
                           | bt-chars-plan

big-tokes-less-d-s-p : bt-chars-no-title-start
                     | big-tokes-less-d-s-p-cnt

big-tokes-less-p : bt-asterisk
                 | bt-colon
                 | big-tokes-less-d-s-p

big-tokes-less-d-s : bt-chars-plan
                   | big-tokes-less-d-s-p

big-tokes : bt-asterisk
          | bt-colon
          | big-tokes-less-d-s

big-tokes-less-d : bt-asterisk
                 | big-tokes-less-d-s

big-tokes-less-s : bt-colon
                 | big-tokes-less-d-s

;;; individuals

@alpha : ALPHA | CHAR-UPPER-X ; CHAR-LOWER-L ; XXX complexity
alpha-n : ALPHA-LOWER-N | ALPHA-UPPER-N
digit-n : DIGIT-2 | DIGIT-3 | DIGIT-4 | DIGIT-N ; FIXME in roughly 7979 years will need DIGIT-5
digits : DIGIT | @digit-n ; FIXME +?
alphas : ( alpha | alpha-n )+ ; need the + here due to mixed case
alphas-unmixed : alpha | alpha-n ; needed for cases where case mixing is not allowed
@word-char : DIGIT | alpha
word-char-less-X : DIGIT | ALPHA
word-char-n : @digit-n | @alpha-n
wordhyus : ( word-char | HYPHEN | UNDERSCORE | word-char-n )+
wordhy : ( word-char | HYPHEN )+

;;;; negation

;; here be the scary implementation details for what you have to do if
;; you want to be able to parse nearly all of org as a context free
;; language, amazingly it pretty much works, probably because the
;; elisp implementation uses regex for nearly everything and because
;; the set of negated charachters that are required to make it possible
;; to parse org is finite

;;; not yet negated

nwt-less-negated : BS | UNDERSCORE | SQ
                 | LAB | LCB | RCB | L-PAREN
                 | PERCENT

;;; restoration

; because standard EBNF grammars do not support intersection we have
; to explicilty consturct the negated sets we need from the closed
; negated set

; all negated chars must be dealt with explicitly because negation
; must be closed to fit within the grammar every negation that is
; added to the grammar adds significant complexity, but it is orderly
; complexity so in many cases it may be worth it because it allows the
; rest of the grammar to be simpler

non-whitespace-token : @nwt-less-negated | @unsyms
@unsyms :                   AT | BS | DQ | LSB | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-at :                BS | DQ | LSB | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-bs :           AT      | DQ | LSB | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-dq :           AT | BS      | LSB | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-lsb :          AT | BS | DQ       | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-rsb :          AT | BS | DQ | LSB       | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-rab :          AT | BS | DQ | LSB | RSB | LAB       | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-pipe :         AT | BS | DQ | LSB | RSB | LAB | RAB        | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-plus :         AT | BS | DQ | LSB | RSB | LAB | RAB | PIPE        | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-hash :         AT | BS | DQ | LSB | RSB | LAB | RAB | PIPE | PLUS        | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-colon :        AT | BS | DQ | LSB | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN         | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-hyphen :       AT | BS | DQ | LSB | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE          | ASTERISK | word-char
@unsyms-less-asterisk :     AT | BS | DQ | LSB | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN            | word-char

@unsyms-less-bs-dq :        AT           | LSB | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-plus-hyphen :  AT | BS | DQ | LSB | RSB | LAB | RAB | PIPE        | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE          | ASTERISK | word-char
@unsyms-less-bullet :       AT | BS | DQ | LSB | RSB | LAB | RAB | PIPE        | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE                     | word-char
@unsyms-less-pipe-bullet :  AT | BS | DQ | LSB | RSB | LAB | RAB               | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE                     | word-char
@unsyms-less-pipe-bs :      AT      | DQ | LSB | RSB | LAB | RAB        | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-alpha :        AT | BS | DQ | LSB | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | DIGIT
@unsyms-less-sb-colon :     AT | BS | DQ             | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN         | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-pl-start :     AT | BS | DQ | LSB | RSB | LAB | RAB                      | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE                     ; alpha ; spec says alpha bullets too but impl says nah?
@unsyms-less-prp :          AT | BS | DQ | LSB | RSB | LAB | RAB | PIPE | PLUS | HASH                    | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-tag :               BS | DQ | LSB | RSB | LAB | RAB | PIPE | PLUS        | PERIOD | R-PAREN                                | HYPHEN | ASTERISK
@unsyms-less-dq-ph :        AT | BS      | LSB | RSB | LAB | RAB | PIPE          HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE          | ASTERISK | word-char
@unsyms-less-colon-lsb :    AT | BS | DQ       | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN         | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | word-char
@unsyms-less-lsb-tag :           BS | DQ       | RSB | LAB | RAB | PIPE | PLUS        | PERIOD | R-PAREN                                | HYPHEN | ASTERISK
@unsyms-less-digit :        AT | BS | DQ | LSB | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | alpha
@unsyms-less-lsb-at-digit :      BS | DQ       | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE | HYPHEN | ASTERISK | alpha
@unsyms-less-lsb-X-hyphen : AT | BS | DQ       | RSB | LAB | RAB | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE          | ASTERISK | word-char-less-X
@unsyms-less-ab-digit-hy :  AT | BS | DQ | LSB | RSB             | PIPE | PLUS | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE          | ASTERISK | alpha
@unsyms-less-timestamp :    AT | BS | DQ                         | PIPE | PLUS | HASH | PERIOD | R-PAREN         | PERCENT | UNDERSCORE          | ASTERISK | alpha
@unsyms-less-hypl-rb-dig :  AT | BS | DQ | LSB       | LAB       | PIPE        | HASH | PERIOD | R-PAREN | COLON | PERCENT | UNDERSCORE          | ASTERISK | alpha

;;; negated sets

not-newline : ( @not-newline1+ | @big-tokes | @word-char-n )+  ; used extensively
not-whitespace : ( @not-whitespace1+ | @big-tokes | @word-char-n )+
not-whitespace-l-d : ( @not-whitespace1+ | @big-tokes-less-d | @word-char-n )+

not-newline-not-asterisk-src-end : ( @not-newline1+ | @big-tokes-less-s-src-end | @word-char-n )+
not-newline-not-src-end : ( @not-newline1+ | @big-tokes-less-src-end | @word-char-n )+

;; individuals
; XXX NOTE make sure you really mean to use these, the not-*-newline1 form is probably what you want
not-newline1 : @not-whitespace1 | space | tab
not-whitespace1 :  NEGATED-SET | @non-whitespace-token

not-at-whitespace1 : ns-nwt-less-negated | unsyms-less-at
not-at-newline1 : not-at-whitespace1 | wsnn
not-at1 : not-at-newline1 | newline

not-lsb-at-digit-newline1 : ns-nwt-less-negated | non-whitespace-token | unsyms-less-digit | wsnn
not-lsb-at-digits-newline : ( @not-lsb-at-digit-newline1 | @big-tokes | alpha-n )+

not-ab-digit-hy-newline1 : ns-nwt-less-negated | unsyms-less-ab-digit-hy | wsnn
not-ab-digits-hy-newline : ( @not-ab-digit-hy-newline1 | @big-tokes-less-p| alpha-n )+

not-lsb-hy-plus-digit-whitespace1 : ns-nwt-less-negated | unsyms-less-hypl-rb-dig | @big-tokes | alpha-n
not-lsb-hy-plus-digit-whitespace : ( @not-lsb-hy-plus-digit-whitespace1 )+

;; unused
; not-plus1 :        ns-nwt-less-negated | @whitespace | unsyms-less-plus
; not-dq1 :          ns-nwt-less-negated | @whitespace | unsyms-less-dq
; not-pipe1 :        ns-nwt-less-negated | @whitespace | unsyms-less-pipe
; not-colon1 :       ns-nwt-less-negated | @whitespace | unsyms-less-colon
; not-pl-start1 :    ns-nwt-less-negated | @whitespace | unsyms-less-pl-start
; not-prp1 :         ns-nwt-less-negated | @whitespace | unsyms-less-prp

not-lsb-space-X-hyphen-newline1 : ns-nwt-less-negated | unsyms-less-lsb-X-hyphen | wsnn
not-lsb-space-X-hyphen-newline : ( not-lsb-space-X-hyphen-newline1 | @big-tokes | word-char-n )+
not-space-X-hyphen-newline1 : not-lsb-space-X-hyphen-newline1 | LSB

ns-nwt-less-negated : NEGATED-SET | @nwt-less-negated

not-plan-keyword-timestamp-newline : ( ns-nwt-less-negated | unsyms-less-timestamp | @big-tokes-less-p | word-char-n )+

not-COMMENT-RTK-lsb-whitespace : ( @not-lsb-whitespace1 | big-tokes-less-COMMENT-RTK | word-char-n )+

not-COMMENT-RTK-lsb-tag-whitespace : ( @not-lsb-tag-whitespace1 | big-tokes-less-COMMENT-RTK | word-char-n )+
not-lsb-tag-whitespace1 : ns-nwt-less-negated | unsyms-less-lsb-tag

not-alpha-whitespace1 : ns-nwt-less-negated | unsyms-less-alpha
not-alpha-newline1 : @not-alpha-whitespace1 | wsnn

not-digit-newline1 : ns-nwt-less-negated | unsyms-less-digit | wsnn
not-digits-newline : ( @not-digit-newline1 | @big-tokes | alpha-n )+

not-asterisk-whitespace1 :    ns-nwt-less-negated | unsyms-less-asterisk
not-asterisk-newline1 :       @not-asterisk-whitespace1 | wsnn
not-asterisk1 :               not-asterisk-newline1 | newline

not-lsb-whitespace1 : ns-nwt-less-negated | unsyms-less-lsb
not-lsb-newline1 : @not-lsb-whitespace1 | wsnn

not-rsb-newline1 : ns-nwt-less-negated | wsnn | unsyms-less-rsb
not-rsb-newline : ( @not-rsb-newline1 | @big-tokes | word-char-n )+

not-colon-lsb-whitespace1 : ns-nwt-less-negated | unsyms-less-colon-lsb
not-colon-lsb-newline1 : not-colon-lsb-whitespace1 | wsnn

not-bullet-pipe1 : ns-nwt-less-negated | @whitespace | unsyms-less-pipe-bullet
not-plus-hyphen1 : ns-nwt-less-negated | @whitespace | unsyms-less-plus-hyphen

not-pl-start-newline1 : ns-nwt-less-negated | wsnn | unsyms-less-pl-start
not-prp-newline1 :      ns-nwt-less-negated | wsnn | unsyms-less-prp

not-colon-whitespace1 : ns-nwt-less-negated | unsyms-less-colon
not-colon-newline1 :  not-colon-whitespace1 | wsnn
not-colon-newline :    ( @not-colon-newline1 | @big-tokes-less-d | word-char-n )+

not-pipe-not-newline1 : ns-nwt-less-negated | wsnn | unsyms-less-pipe
not-pipe-not-newline : ( @not-pipe-not-newline1 | @big-tokes | word-char-n )+

not-pipe-bs-newline1 : ns-nwt-less-negated | unsyms-less-pipe-bs | wsnn
not-pipe-bs-newline : ( @not-pipe-bs-newline1 | @big-tokes | word-char-n )+

not-tag-whitespace1 : ns-nwt-less-negated | unsyms-less-tag
not-tag-whitespace : @not-tag-whitespace1+ ; TODO which big tokes?
not-tag-newline1 : not-tag-whitespace1 | wsnn
not-tag-newline : @not-tag-newline1+ ; TODO which big tokes?

not-pl-start-whitespace1 : ns-nwt-less-negated | unsyms-less-pl-start
not-plus-whitespace1 :     ns-nwt-less-negated | unsyms-less-plus
not-plus-newline1 : not-plus-whitespace1 | wsnn
not-bs-dq-whitespace1 :    ns-nwt-less-negated | @unsyms-less-bs-dq
not-bs-dq-newline1 : space | tab | @not-bs-dq-whitespace1
not-bs-dq1 : whitespace | @not-bs-dq-whitespace1
not-bs-dq-newline : ( @not-bs-dq-newline1 | word-char-n )+
not-bs-dq : ( @not-bs-dq1 | word-char-n )+

not-dq-newline1 : ns-nwt-less-negated | @unsyms-less-dq | wsnn
not-dq-newline : ( @not-dq-newline1 | big-tokes | word-char-n )+

not-dq-ph-newline1 : ns-nwt-less-negated | @unsyms-less-dq-ph | wsnn
not-dq-ph-newline : ( @not-dq-ph-newline1 | big-tokes | word-char-n )+

not-hash-newline1 : ns-nwt-less-negated | @unsyms-less-hash | wsnn

not-pipe-bullet-not-whitespace1 : ns-nwt-less-negated | unsyms-less-pipe-bullet
;not-pipe-bullet-not-newline1 : space | tab | not-pipe-bullet-not-whitespace1 ; unused
;not-pipe-bullet-not-newline : ( @not-pipe-bullet-not-newline1+ | @big-tokes )+ ; unused
not-sb-colon-whitespace1 : ns-nwt-less-negated | unsyms-less-sb-colon
not-sb-colon-whitespace : @not-sb-colon-whitespace1+
