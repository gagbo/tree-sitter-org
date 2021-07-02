// This grammar is written to match the one used by Laundry,
// thanks to Tom Gillespie for their effort.

// For further information, see https://github.com/tgbugs/laundry/blob/next/laundry/parser.rkt


// NOTE: I stopped translating `-*` rules, it looks like they are old, unused ones.
//
// NOTE: Sometimes, alias is used where the rule seems to be used as such (like "header-misplaced: header")
//
// NOTE: Unused rules (and their dependencies) are not translated when detected
//
// TODO: Finish alpha raw transcription.
//
// TODO: As far as I understand, the uppercase symbolic rule identifiers should
// be dynamic rules, so they should be externals parsed by a C++ scanner.
//
// TODO: There are a lot of @ and / prefixes used in the right-hand side of
// patterns. I have no idea how it will translate in a TS grammar here.
// Especially the non-capturing not-newline and stuff
//
// TODO: Redo test harness

module.exports = grammar({
  name: "org",

  externals: (_$) => [],

  // In brag, @ before a rule identifier means we don't want the rule
  // to generate a node in the AST.
  // This is like the silent modifier in Pest grammars,
  // or the inline rules here.
  inline: ($) => [
    $.org_node_basic,
    $.org_node_basic_element,
    $.org_nbe_less_df,
    $.org_nbe_less_d,
    $.org_nbe_less_f,
    $.org_nbe_f_in,
    $.not_newline,
    $.paragraph_line,
    $.paragraph_line_f_in,
    $.wsnn,
    $.parl_lines,
    $.parl_se_wsnn,
    $.plan_sep,
    $.h_rt_todo_keyword,
    $.h_tags,
    $.h_ctt_start,
    $.priority,
    $.tag_start,
    $.tag_name_parts,
    $.not_whitespace,
    $.not_plus_whitespace1,
    $.drawer_spec,
    $.wordhyus,
    $.nlbofwsnn,
    $.keyword_line,
    $.affiliated_keyword_line,
    $.block_less_dyn,
    $.no_headlines,
    $.line_not_headline,
    $.start_not_headline,
    $.__test__switches_sane,
    $.not_switch,
    $.switch_sign,
    $.not_plus_hyphen1,
    $.not_alpha_newline1,
    $.not_whitespace1,
    $.blk_src_args_after_switches_sane,
    $.date_normal,
    $.date_suffix,
    $.date_ex,
    $.alpha,
    $.word_char,
    $.nwt_less_negated,
    $.unsyms,
    $.unsyms_less_at,
    $.unsyms_less_bs,
    $.unsyms_less_dq,
    $.unsyms_less_lsb,
    $.unsyms_less_rsb,
    $.unsyms_less_rab,
    $.unsyms_less_pipe,
    $.unsyms_less_plus,
    $.unsyms_less_hash,
    $.unsyms_less_colon,
    $.unsyms_less_hyphen,
    $.unsyms_less_asterisk,
    $.unsyms_less_bs_dq,
    $.unsyms_less_plus_hyphen,
    $.unsyms_less_bullet,
    $.unsyms_less_pipe_bullet,
    $.unsyms_less_pipe_bs,
    $.unsyms_less_alpha,
    $.unsyms_less_sb_colon,
    $.unsyms_less_pl_start,
    $.unsyms_less_prp,
    $.unsyms_less_tag,
    $.unsyms_less_dq_ph,
    $.unsyms_less_colon_lsb,
    $.unsyms_less_lsb_tag,
    $.unsyms_less_digit,
    $.unsyms_less_lsb_at_digit,
    $.unsyms_less_lsb_X_hyphen,
    $.unsyms_less_ab_digit_hy,
    $.unsyms_less_timestamp,
    $.unsyms_less_hypl_rb_dig,
    $.not_whitespace1,
    $.non_whitespace_token,
  ],

  rules: {
    org_file: ($) => repeat($.org_node),

    org_node: ($) => choice($.headline_node, $.org_node_basic),

    org_node_basic: ($) => seq(
      repeat($.affiliated_keyword),
      choice(
        $.org_node_basic_element,
        $.double_blank_line,
        $.newline)),

    org_node_basic_element: ($) => choice(
      $.drawer,
      $.blk_dyn,
      $.org_nbe_less_d,
      $.paragraph),

    org_nbe_less_df: ($) => choice(
      $.block_less_dyn,
      // $.block_begin_line,
      // $.block_end_line,
      $.babel_call,
      $.keyword,
      $.comment_element,
      $.table,
      $.plain_list_line),

    org_nbe_less_d: ($) => choice(
      $.org_nbe_less_df,
      // TODO $.footnote_definition
    ),

    org_nbe_less_f: ($) => choice(
      $.org_nbe_less_df,
      $.paragraph),

    org_nbe_f_in: ($) => choice(
      $.org_nbe_less_df,
      $.paragraph_f_in,
      $.comment_element),

    paragraph: ($) => prec.left(50, repeat1(choice(
      seq("PARAGRAPH", optional($.not_newline)),
      seq($.hyperlink, optional($.not_newline)),
      $.paragraph_line))),
    paragraph_line: ($) => seq(
      $.newline,
      choice($.parl_lines, $.end)),
    paragraph_line_d: ($) => seq (
      $.newline,
      $.parl_lines),
    hyperlink: (_$) => "LINK",

    paragraph_f_in: ($) => repeat1($.paragraph_line_f_in),
    paragraph_line_f_in: ($) => seq(
      $.newline,
      choice(
        $.parl_lines,
        // TODO $.misplaced_footnote_definition,
        $.end)),

    // misplaced_footnote_definition: ($) => $.footnote_definition_line,

    parl_indent: ($) => repeat1($.wsnn),
    parl_lines: ($) => choice(
      seq($.parl_start, optional($.not_newline)),
      seq(optional($.parl_indent), $.parl_se_wsnn),
      $.stars,
      seq(repeat($.wsnn), "STARS", repeat($.wsnn)),
      repeat1($.wsnn)),

    parl_se_wsnn: ($) => choice(
      $.digits,
      $.alphas,
      ":",
      seq("#", "+", ":", $.not_colon_newline),
      seq("#", "+", ":"),
      seq("#", "+", $.not_colon_newline),
      seq("#", "+"),
      $.big_tokes_less_d_s_blk,
      $.malformed_wsnn),

    parl_start: ($) => choice(
      $.not_pl_start_whitespace1,
      seq($.stars, choice(
        $.not_asterisk_whitespace1,
        $.word_char_n)),
      seq(optional($.parl_indent), $.parl_wsnn)),

    parl_ws_bt: ($) => choice(
      $.not_whitespace1,
      $.big_tokes),
    parl_ws_bt_l_s: ($) => choice(
      $.not_whitespace1,
      $.word_char_n,
      $.big_tokes_less_s),
    parl_ncn_bt_l_d: ($) => choice(
      $.not_colon_newline1,
      $.big_tokes_less_d),
    parl_prp_bt: ($) => choice(
      $.not_prp_newline1,
      $.big_tokes),
    parl_pw_bt: ($) => choice(
      $.not_plus_whitespace1,
      $.big_tokes,
      $.word_char_n),
    parl_wsnn: ($) => choice(
      $.bt_chars,
      seq(choice("ASTERISK", "+", "-"), $.parl_ws_bt_l_s),
      seq(repeat1($.wsnn), "STARS"),
      seq(choice($.digits, $.alphas), $.parl_prp_bt),
      seq(choice($.digits, $.alphas), choice(".", ")"), $.parl_ws_bt),
      seq("#", $.parl_pw_bt),
      $.malformed,
      seq("#", "+", optional($.not_whitespace_l_d), repeat1($.wsnn), optional($.not_newline), ":"),
      seq(":", $.not_colon_newline),
      "NEGATED_SET",
      "UNDERSCORE",
      "@",
      "PERCENT",
      ".",
      "(",
      ")"),

    malformed: ($) => choice(
      seq($.detached_block_node, repeat($.wsnn)),
      $.blk_greater_malformed,
      alias($.planning, $.planning_dissociated),
      $.ak_key_no_colon,
      $.babel_call_no_colon),

    malformed_wsnn: ($) => alias($.affiliated_keyword, $.un_affiliated_keyword),

    ak_key_no_colon: ($) => seq($.ak_key, $.parl_ncn_bt_l_d),
    babel_call_no_colon: ($) => seq("CALL", $.parl_ncn_bt_l_d),

    no_colon_no_keywords: ($) => seq("CALL", $.nc_start),
    parl_ncln_bt_l_d: ($) => choice(
      $.not_colon_lsb_newline1,
      $.big_tokes_less_d),
    nc_start: ($) => choice(
      $.parl_ncln_bt_l_d,
      seq("[", $.not_rsb_newline1),
      ":"),

    headline_node: ($) => prec.right(50, seq(
      $.headline,
      optional(seq($.newline, choice($.planning, $.planning_malformed))),
      optional($.property_drawer))),
    headline: ($) => choice(
      "HEADING",
      seq($.newline, $.stars, repeat1($.wsnn), optional($.headline_content))),
    stars: (_$) => choice("ASTERISK", "STARS"),
    headline_content: ($) => $.not_newline,

    planning: ($) => seq(
      repeat1(seq(optional($.plan_sep), $.plan_info)),
      repeat($.wsnn)),
    plan_sep: ($) => repeat1($.wsnn),

    planning_malformed: ($) => repeat1($.plan_mal_info),
    plan_mal_info: ($) => seq(
      optional($.plan_mal_sep),
      $.plan_keyword,
      ":",
      optional($.plan_mal_sep)),
    plan_mal_sep: ($) => choice(
      $.not_plan_keyword_timestamp_newline,
      seq($.plan_keyword, $.not_colon_newline)),

    plan_info: ($) => seq(
      $.plan_keyword,
      ":",
      repeat($.wsnn),
      optional(alias($.timestamp, $.plan_timestamp))),
    plan_keyword: ($) => choice(
      $.plan_dead,
      $.plan_sched,
      $.plan_open,
      $.plan_close),
    plan_dead: (_$) => "CHARS-DEADLINE",
    plan_sched: (_$) => "CHARS-SCHEDULED",
    plan_open: (_$) => "CHARS-OPENED",
    plan_close: (_$) => "CHARS-CLOSED",

    headline_content_2: ($) => choice(
      seq(
        $.h_rt_todo_keyword,
        repeat1($.wsnn),
        optional($.h_rt_mid),
        optional($.h_rt_tags)
      ),
      seq($.h_rt_todo_keyword, repeat($.wsnn)),
      seq(optional($.h_rt_mid_no_rtk), optional($.h_rt_tags)),
      seq(optional($.h_rt_mid_weird), optional($.h_rt_tags)),
      $.h_rt_mid_no_rtk,
      optional($.h_rt_tags_tail)),

    h_rt_mid_common: ($) => choice(
      seq($.h_priority, repeat($.wsnn), $.h_comment, optional($.h_rt_title)),
      seq($.h_priority, repeat($.wsnn), optional($.h_rt_title_not_comment)),
      seq($.h_comment, optional($.h_rt_title))),
    h_rt_mid: ($) => choice($.h_rt_mid_common, $.h_rt_title_not_comment),
    h_rt_mid_no_rtk: ($) => choice($.h_rt_mid_common, $.h_rt_title_not_comment_rtk),
    h_rt_mid_weird: ($) => choice($.h_rt_mid_common, $.h_rt_title_weird),
    h_rt_title_weird: ($) => choice(
      seq(
        alias($.h_rt_todo_keyword, $.h_rt_todo_keyword_not_active),
        optional($.h_rt_title)),
      seq(
        alias($.h_rt_todo_keyword, $.h_rt_todo_keyword_not_active),
        optional($.h_rt_tags_missing_space))),
    h_rt_tags_missing_space: ($) => seq($.h_tags, repeat($.wsnn), $.newline),

    h_rt_todo_keyword: (_$) => "RUNTIME-TODO-KEYWORD",
    h_rt_title: ($) => $.h_ctt_start,
    h_rt_tags: ($) => seq(repeat1($.wsnn), $.h_rt_tags_tail),
    h_rt_tags_tail: ($) => seq(
      $.h_tags,
      repeat($.wsnn),
      $.newline_or_eof),

    headline_chars_complex: ($) => choice(
      $.not_lsb_whitespace1,
      seq("[", $.not_hash_newline1),
      seq("[", "#", $.not_rsb_newline1, $.not_rsb_newline1),
      seq("[", "#", "]", $.not_rsb_newline1)),
    not_tags: ($) => choice(
      seq($.not_colon_newline, repeat($.wsnn), $.newline_or_eof),
      seq($.not_tag_whitespace,
          // $.tags_contents,
          repeat($.wsnn), $.newline_or_eof),
      seq(
        $.not_tag_newline,
        $.not_colon_whitespace1,
        // $.tags_contents,
        repeat($.wsnn),
        $.newline_or_eof)),
    h_rt_title_begin: ($) => $.not_COMMENT_RTK_lsb_whitespace,
    h_rt_title_end: ($) => $.not_tags,
    h_rt_title_single: ($) => $.not_COMMENT_RTK_lsb_tag_whitespace,

    h_rt_title_not_comment_rtk: ($) => choice(
      seq(
        $.h_rt_title_begin,
        optional($.not_newline),
        $.h_rt_title_end
      ),
      $.h_rt_title_single),
    h_rt_title_not_comment: ($) => choice(
      seq(
        choice($.h_rt_title_begin, "RUNTIME-TODO-KEYWORD"),
        optional($.not_newline),
        $.h_rt_title_end),
      $.h_rt_title_single),

    h_comment: (_$) => "CHARS-COMMENT",

    h_priority: ($) => $.priority,
    priority: ($) => seq("[", "#", $.priority_level, "]"),
    priority_level: ($) => $.not_whitespace1,

    h_tags: ($) => seq(
      repeat1(choice($.tag_start, $.tag_archive)),
      ":"),
    tag_start: ($) => seq(":", $.tag_name),
    tag_name: ($) => repeat1($.tag_name_parts),
    tag_name_parts: ($) => choice(
      $.word_char_n,
      $.word_char,
      "UNDERSCORE",
      "@",
      "#",
      "PERCENT"),
    tag_contents: ($) => repeat1(choice(
      $.tag_name_parts,
      ":",
      "ARCHIVE")),

    tag_archive: (_$) => "ARCHIVE",

    h_ctt_start: ($) => choice(
      seq(
        choice($.h_comment, $.headline_chars_complex),
        optional($.not_newline),
        $.not_tags),
      seq(
        optional(choice($.h_comment, $.headline_chars_complex)),
        $.not_tags),
      $.h_comment),

    property_drawer: ($) => choice(
      $.pdrawer_unparsed,
      seq(
        $.newline,
        repeat($.wsnn),
        $.properties,
        repeat($.node_property),
        $.nlws,
        $.end)),
    pdrawer_unparsed: (_$) => "DRAWER-PROPS",
    properties: (_$) => "PROPERTIES-D",
    end: (_$) => "END-D",
    plus: (_$) => "+",
    node_property: ($) => seq(
      $.newline,
      repeat($.wsnn),
      ":",
      $.property_name,
      optional($.plus),
      ":",
      optional($.property_value)),
    property_name: ($) => seq(
      repeat($.not_whitespace),
      $.not_plus_whitespace1
    ),
    property_value: ($) => seq(
      repeat1($.wsnn),
      optional($.not_newline)
    ),

    drawer: ($) => choice(
      "DRAWER",
      $.drawer_spec,
      $.pdrawer_unparsed),
    drawer_spec: ($) => seq(
      $.newline,
      repeat($.wsnn),
      choice(
        seq(":", $.drawer_name, ":"),
        seq("ARCHIVE", ":"),
        $.properties),
      repeat($.wsnn),
      optional($.drawer_contents),
      $.nlws,
      $.end),
    drawer_name: ($) => $.wordhyus,
    drawer_contents: ($) => repeat1($.org_node_d),
    org_node_d: ($) => repeat1($.affiliated_keyword),

    comment_element: ($) => prec.left(50, repeat1(choice(
      "COMMENT-ELEMENT",
      $.comment_line))),
    comment_line: ($) => seq(
      $.newline,
      repeat($.wsnn),
      "#",
      optional(seq(
        repeat1($.wsnn),
        optional($.not_newline)))),

    nlbofwsnn: ($) => seq($.newline, repeat($.wsnn)),
    babel_call: ($) => seq($.nlbofwsnn, "CALL", ":", optional($.not_newline)),

    keyword: ($) => choice(
      $.todo_spec_line,
      seq($.nlbofwsnn, $.keyword_line)
    ),
    keyword_line: ($) => seq(
      choice(seq("#", "+", $.keyword_key), $.kw_prefix),
      optional($.keyword_options),
      ":",
      repeat1($.wsnn),
      optional($.keyword_value)),
    kw_prefix: (_$) => choice("AUTHOR", "DATE", "TITLE"),
    keyword_options: ($) => seq("[", $.not_newline, "]"),

    todo_spec_line: (_$) => "TODO-SPEC-LINE",

    affiliated_keyword: ($) => seq($.nlbofwsnn, $.affiliated_keyword_line),
    affiliated_keyword_line: ($) => seq(
      $.ak_key,
      optional($.keyword_options),
      ":",
      repeat1($.wsnn),
      optional($.keyword_value)),
    ak_key: ($) => choice(
      "CAPTION",
      "HEADER",
      "NAME",
      "PLOT",
      "RESULTS",
      $.ak_key_attr
    ),

    // -keyword_line: ($) => choice(
    //   seq(
    //     choice(
    //       seq("#", "+", $.keyword_key),
    //       "END-DB",
    //       "AUTHOR",
    //       "DATE",
    //       "TITLE"),
    //     ":",
    //     optional($.keyword_value)),
    //   seq(
    //     "#",
    //     "+",
    //     $.keyword_key_sigh,
    //     optional($.keyword_value_sigh))),

    keyword_key: ($) => $.not_whitespace,
    keyword_value: ($) => $.not_newline,

    keyword_key_sigh: (_$) => choice("END-D", "PROPERTIES-D"),
    keyword_value_sigh: ($) => choice(
      $.not_colon_newline,
      seq(
        optional($.not_whitespace_l_d),
        repeat1($.wsnn),
        optional($.not_newline),
        ":",
        optional($.not_newline))),

    ak_value: ($) => $.not_newline,
    ak_key_attr: ($) => seq("ATTR-PREFIX", $.attr_backend),

    header: (_$) => "HEADER",
    name: (_$) => "NAME",
    plot: (_$) => "PLOT",
    attr_backend: ($) => $.wordhyus,

    ak_opt: ($) => seq("[", $.not_newline, "]"),
    ak_key_opt: ($) => seq($.ak_key_name_opt, $.ak_opt),
    ak_key_name_opt: ($) => choice($.caption, $.result),
    caption: (_$) => "CAPTION",
    result: (_$) => "RESULT",

    block_less_dyn: ($) => choice(
      $.blk_src,
      seq($.newline, $.blk_ex)),

    blk_ex: ($) => seq($.blk_ex_begin, $.blk_ex_contents, $.nlpws, $.blk_ex_end),
    blk_ex_begin: ($) => choice(
      seq(
        "BEGIN-EX",
        $.wsnn,
        $.blk_line_contents),
      "BEGIN-EX"),
    blk_ex_end: (_$) => "END-EX",
    blk_ex_contents: ($) => $.no_headlines,

    blk_greater_begin: ($) => choice(
      seq($.blk_greater_type, $.wsnn, $.blk_line_contents),
      $.blk_greater_type),
    blk_greater_end: ($) => choice(
      seq("END-BLOCK", $.block_type_name),
      $.bg_end_special),
    bg_end_special: ($) => choice(
      seq("END-SRC", $.block_type_rest),
      seq("END-EX", $.block_type_rest)),
    blk_greater_type: ($) => choice(
      seq("BEGIN-BLOCK", $.block_type_name),
      $.bg_type_special),
    bg_type_special: ($) => choice(
      seq("BEGIN-SRC", $.block_type_rest),
      seq("BEGIN-EX", $.block_type_rest)),
    blk_greater_malformed: ($) => seq(
      choice("END-BLOCK", "BEGIN-BLOCK"),
      repeat($.wsnn)),
    block_type_name: ($) => $.not_whitespace,
    block_type_rest: ($) => $.not_whitespace,

    blk_dyn: ($) => seq(
      $.newline,
      $.blk_dyn_begin,
      optional($.blk_dyn_contents),
      $.newline,
      $.blk_dyn_end),
    blk_dyn_begin: ($) => choice(
      seq("BEGIN-DB", ":", $.wsnn, optional($.blk_line_contents)),
      seq("BEGIN-DB", ":")),
    blk_dyn_end: (_$) => seq("END-DB", ":"),
    blk_dyn_contents: ($) => repeat1($.org_node_dyn),
    org_node_dyn: ($) => seq(
      repeat($.affiliated_keyword),
      choice(
        $.drawer,
        $.org_nbe_less_d,
        $.paragraph_line,
        $.newline)),

    no_headlines: ($) => repeat1(choice(
      seq("PARAGRAPH", optional($.not_newline)),
      $.line_not_headline)),
    line_not_headline: ($) => seq(
      repeat1($.newline),
      $.start_not_headline,
      optional($.not_newline)),
    start_not_headline: ($) => choice(
      $.not_asterisk_newline1,
      // seq($.start, $.not_asterisk_whitespace1),
      $.word_char_n),

    blk_line_contents: ($) => $.not_newline,
    blk_line_rest: ($) => $.not_newline,

    detached_block_node: ($) => choice(
      alias($.blk_src_begin, $.det_blk_src_begin),
      alias($.blk_src_end, $.det_blk_src_end),
      alias($.blk_ex_begin, $.det_blk_ex_begin),
      alias($.blk_ex_end, $.det_blk_ex_end)),

    blk_src: ($) => choice(
      "SRC-BLOCK",
      seq(
        $.newline,
        $.blk_src_begin,
        optional($.blk_src_contents),
        $.nlpws,
        $.blk_src_end)),
    blk_src_begin: ($) => seq(
      choice(
        seq("BEGIN-SRC", $.wsnn, $.blk_src_line_contents),
        "BEGIN-SRC"),
      repeat($.wsnn)),
    blk_src_end: ($) => seq("END-SRC", repeat($.wsnn)),
    blk_src_contents: ($) => $.no_headlines,
    blk_src_line_contents: ($) => choice(
      seq(
        alias($.not_whitespace, $.language),
        $.wsnn,
        $.blk_src_line_rest_alt),
      seq(
        alias($.not_whitespace, $.language),
        repeat($.wsnn))),
    blk_src_line_rest_alt: ($) => choice(
      seq($.switches_sane, $.wsnn, alias($.blk_src_parameters, $.blk_src_args_after_swiches_sane)),
      $.switches_sane,
      seq($.not_switch, $.not_newline)),

    __test__switches_sane: ($) => seq(
      // optional($.BOF),
      $.switches_sane),
    switches_sane: ($) => seq(
      repeat(seq(
        $.switch_sane,
        optional(seq($.wsnn, $.format_string)),
        $.wsnn)),
      $.switch_sane,
      optional(seq($.wsnn, $.format_string))),
    switch_sane: ($) => seq($.switch_sign, $.alpha),
    last_switch_string: ($) => seq($.wsnn, $.format_string),
    switch_sign: (_$) => choice("+", "-"),

    not_switch: ($) => choice(
      $.not_plus_hyphen1,
      seq("+", $.not_alpha_newline1),
      seq("-", $.not_alpha_newline1),
      seq("+", $.alpha, $.not_whitespace1),
      seq("-", $.alpha, $.not_whitespace1)),

    blk_src_parameters: ($) => seq(":", $.not_newline),
    blk_src_args_after_switches_sane: ($) => choice(
      $.blk_src_parameters,
      seq($.not_dq_ph_newline, optional($.not_newline)),
      seq($.switch_sign, $.not_alpha_newline1, optional($.not_newline)),
      seq(
        $.switch_sign,
        choice(
          seq($.alpha, $.not_whitespace),
          $.word_char_n),
        optional($.not_newline)),
      $.blk_src_args_broken),
    blk_src_args_broken: ($) => seq("\"", optional($.not_dq_newline)),

    format_string: ($) => seq("\"", $.format_string_contents, "\""),
    format_string_contents: ($) => repeat1(choice(
      $.not_bs_dq_newline,
      seq("BS", "\""),
      "BS")),

    string: ($) => seq("\"", $.string_contents, "\""),
    string_contents: ($) => repeat1(choice(
      $.not_bs_dq,
      seq("BS", "\""),
      "BS")),

    table: ($) => prec.right(50, repeat1($.table_row)),
    table_dumb: ($) => seq($.newline, "|", $.not_newline),
    table_row: ($) => seq(
      $.newline,
      repeat($.wsnn),
      repeat1($.table_cell),
      optional("|")),
    table_cell: ($) => seq(
      "|",
      optional($.space),
      repeat(choice(
        $.not_pipe_bs_newline,
        seq("BS", "|"),
        "BS")),
      optional($.space)),

    plain_list_line: ($) => seq(
      $.newline,
      optional($.pl_indent),
      choice($.ordered_list_line, $.descriptive_list_line)),
    pl_indent: ($) => repeat1($.wsnn),
    ordered_list_line: ($) => seq($.bullet_counter, optional($.plain_list_line_tail)),
    bullet_counter: ($) => seq(
      choice($.digits, $.alphas_unmixed),
      choice(".", ")")),
    descriptive_list_line: ($) => seq(
      $.bullet_plain,
      optional($.plain_list_line_tail)),
    bullet_plain: ($) => choice(
      "-",
      "+",
      seq(repeat1($.wsnn), "ASTERISK")),
    plain_list_line_tail: ($) => choice(
      seq(repeat1($.wsnn), $.not_newline),
      repeat1($.wsnn)),

    // TODO Finish plain lists

    // TODO footnotes

    timestamp: ($) => choice(
      $.ts_diary,
      $.ts_active,
      $.ts_inactive,
      $.ts_range_active,
      $.ts_range_inactive
    ),
    ts_diary: ($) => seq("LAB", "%%", "(", $.ts_diary_sexp, ")", ">"),
    ts_diary_sexp: (_$) => repeat1("NOT-RAB-NOT-NEWLINE"),
    ts_active: ($) => seq(
      "LAB",
      $.date,
      optional(seq(repeat1($.space), $.time)),
      optional($.ts_rod),
      ">"),
    ts_inactive: ($) => seq(
      "[",
      $.date,
      optional(seq(repeat1($.space), $.time)),
      optional($.ts_rod),
      "]"),
    ts_range_active: ($) => choice(
      seq($.ts_active, $.hh, $.ts_active),
      seq(
        "LAB",
        $.date,
        repeat1($.space),
        $.time,
        "-",
        $.time,
        $.ts_rod,
        ">")),
    ts_range_inactive: ($) => choice(
      seq($.ts_inactive, $.hh, $.ts_inactive),
      seq(
        "[",
        $.date,
        repeat1($.space),
        $.time,
        "-",
        $.time,
        $.ts_rod,
        "]")),
    hh: (_$) => seq("-", "-"),

    date: ($) => choice($.date_normal, $.date_ex),
    date_suffix: ($) => seq(
      "-",
      $.month,
      "-",
      $.day,
      optional(seq(repeat1($.space), $.day_abbrev))),
    date_normal: ($) => seq($.year, $.date_suffix),
    year: (_$) => "DIGIT-4",
    month: (_$) => "DIGIT-2",
    day: (_$) => "DIGIT-2",
    date_ex: ($) => seq($.date_sign, $.year_ex, $.date_suffix),
    year_ex: ($) => $.digits,
    date_sign: (_$) => choice("+", "-"),

    time: ($) => seq($.hour, ":", $.minute),
    hour: (_$) => "DIGIT-2",
    minute: (_$) => "DIGIT-2",
    day_abbrev: ($) => $.not_lsb_hy_plus_digit_whitespace,

    ts_rod: ($) => seq(
      $.ts_rod_entry,
      repeat1($.ts_rod_entry)
    ),
    ts_rod_entry: ($) => seq(
      $.ts_rod_mark,
      $.ts_rod_value,
      $.ts_rod_unit),
    ts_rod_mark: (_$) => choice(
      "+",
      "++",
      ".+",
      "-",
      "--"),
    ts_rod_value: ($) => $.digits,
    ts_rod_unit: (_$) => choice(
      "h",
      "d",
      "w",
      "m",
      "y"),

    // TODO export_snippets

    newline_or_bof: ($) => choice($.newline, $.bof),
    newline_or_eof: ($) => $.newline, // Or EOF ??
    nlws: ($) => seq(
      $.newline,
      repeat(choice(
        $.tab,
        $.space))),
    nlpws: ($) => seq(
      repeat1($.newline),
      repeat(choice(
        $.tab,
        $.space))),
    whitespace: ($) => choice(
      $.newline,
      $.space,
      $.tab),
    wsnn: ($) => choice(
      $.tab,
      $.space),

    blank_line: ($) => seq(
      $.newline,
      $.newline),
    double_blank_line: ($) => prec(50, seq(
      $.newline,
      $.newline,
      $.newline)),

    bof: (_$) => "BOF",
    newline: (_$) => choice("\n", "\r\n"),

    space: (_$) => " ",
    tab: (_$) => "\t",

    bt_asterisk: (_$) => "STARS",
    bt_colon: (_$) => choice("END-D", "PROPERTIES-D"),
    bt_chars: (_$) => choice("CHARS-ARCHIVE", "ARCHIVE"),
    bt_chars_plan: (_$) => choice(
      "CHARS-OPENED",
      "CHARS-CLOSED",
      "CHARS-DEADLINE",
      "CHARS-SCHEDULED"),
    bt_chars_no_title_start: (_$) => choice(
      "CHARS-COMMENT",
      "RUNTIME-TODO-KEYWORD"
    ),
    bt_hash: (_$) => choice(
      "CALL",
      "NAME",
      "HEADER",
      "PLOT",
      "AUTHOR",
      "DATE",
      "TITLE",
      "RESULT",
      "CAPTION",
      "ATTR-PREFIX",
      "BEGIN-DB",
      "END-DB"),
    bt_blk_begin: (_$) => choice("BEGIN-BLOCK", "BEGIN-SRC", "BEGIN-EX"),
    bt_blk_end: (_$) => choice("END-BLOCK", "END-SRC", "END-EX"),
    bt_blk: ($) => choice($.bt_blk_begin, $.bt_blk_end),
    bt_lsb: (_$) => choice("FOOTNOTE-START", "FOOTNOTE-START-INLINE"),
    big_tokes_less_d_s_p_cnt_blk: ($) => choice(
      $.bt_lsb,
      $.bt_hash,
      $.bt_chars),
    big_tokes_less_d_s_blk: ($) => choice(
      $.big_tokes_less_d_s_p_cnt_blk,
      $.bt_chars_no_title_start,
      $.bt_chars_plan),
    big_tokes_less_s_blk: ($) => choice(
      $.big_tokes_less_d_s_blk,
      $.bt_colon),
    big_tokes_less_s_src_end: ($) => choice(
      $.big_tokes_less_s_blk,
      $.bt_blk_begin,
      "END-BLOCK",
      "END-EX"),
    big_tokes_less_src_end: ($) => choice(
      $.big_tokes_less_s_blk,
      $.bt_asterisk),
    big_tokes_less_s_ex_end: ($) => choice(
      $.big_tokes_less_s_blk,
      $.bt_blk_begin,
      "END-BLOCK",
      "END-SRC"),
    big_tokes_less_ex_end: ($) => choice(
      $.big_tokes_less_s_ex_end,
      $.bt_asterisk),
    big_tokes_less_d_s_p_cnt: ($) => choice(
      $.big_tokes_less_d_s_p_cnt_blk,
      $.bt_blk),
    big_tokes_less_COMMENT_RTK: ($) => choice(
      $.big_tokes_less_d_s_p_cnt,
      $.bt_asterisk,
      $.bt_colon,
      $.bt_chars_plan),
    big_tokes_less_d_s_p: ($) => choice(
      $.bt_chars_no_title_start,
      $.big_tokes_less_d_s_p_cnt
    ),
    big_tokes_less_p: ($) => choice(
      $.bt_asterisk,
      $.bt_colon,
      $.big_tokes_less_d_s_p),
    big_tokes_less_d_s: ($) => choice(
      $.bt_chars_plan,
      $.big_tokes_less_d_s_p),
    big_tokes: ($) => choice(
      $.bt_asterisk,
      $.bt_colon,
      $.big_tokes_less_d_s),
    big_tokes_less_d: ($) => choice(
      $.bt_asterisk,
      $.big_tokes_less_d_s),
    big_tokes_less_s: ($) => choice(
      $.bt_colon,
      $.big_tokes_less_d_s),

    alpha: (_$) => /[a-zA-Z]/,
    alpha_n: (_$) => /[a-zA-Z]/,
    digit_n: (_$) => /\d{2,}/,
    digits: (_$) => /\d+/,
    alphas: ($) => repeat1(choice($.alpha, $.alpha_n)),
    alphas_unmixed: ($) => choice($.alpha, $.alpha_n),
    word_char: ($) => choice(/\d/, $.alpha),
    word_char_less_X: (_$) => choice(/\d/, /[a-zA-WYZ]/),
    word_char_n: ($) => choice($.digit_n, $.alpha_n),
    wordhyus: ($) => repeat1(choice(
      $.word_char,
      "-",
      "_",
      $.word_char_n)),
    wordhy: ($) => repeat1(choice($.word_char, "-")),

    nwt_less_negated: (_$) => choice(
      "\\",
      "_",
      "'",
      "<",
      "{",
      "}",
      "(",
      "%"),

    non_whitespace_token: ($) => choice($.nwt_less_negated, $.unsyms),
    unsyms: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_at: ($) => choice("\\", "\"", "[", "]", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_bs: ($) => choice("@", "\"", "[", "]", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_dq: ($) => choice("@", "\\", "[", "]", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_lsb: ($) => choice("@", "\\", "\"", "]", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_rsb: ($) => choice("@", "\\", "\"", "[", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_rab: ($) => choice("@", "\\", "\"", "[", "]", "<", "|", "+", "#", ".", ")", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_pipe: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", "+", "#", ".", ")", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_plus: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", "|", "#", ".", ")", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_hash: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", "|", "+", ".", ")", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_colon: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", "|", "+", "#", ".", ")", "%", "_", "-", "*", $.word_char),
    unsyms_less_hyphen: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "*", $.word_char),
    unsyms_less_asterisk: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "-", $.word_char),

    unsyms_less_bs_dq: ($) => choice("@", "[", "]", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_plus_hyphen: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", "|", "#", ".", ")", ":", "%", "_", "*", $.word_char),
    unsyms_less_bullet: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", "|", "#", ".", ")", ":", "%", "_", $.word_char),
    unsyms_less_pipe_bullet: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", "#", ".", ")", ":", "%", "_", $.word_char),
    unsyms_less_pipe_bs: ($) => choice("@", "\"", "[", "]", "<", ">", "+", "#", ".", ")", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_alpha: (_$) => choice("@", "\\", "\"", "[", "]", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "-", "*", /\d/),
    unsyms_less_sb_colon: ($) => choice("@", "\\", "\"", "<", ">", "|", "+", "#", ".", ")", "%", "_", "-", "*", $.word_char),
    unsyms_less_pl_start: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", ".", ")", ":", "%", "_", $.alpha),
    unsyms_less_prp: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", "|", "+", "#", ":", "%", "_", "-", "*", $.word_char),
    unsyms_less_tag: (_$) => choice("\\", "\"", "[", "]", "<", ">", "|", "+", ".", ")", "-", "*"),
    unsyms_less_dq_ph: ($) => choice("@", "\\", "[", "]", "<", ">", "|", "#", ".", ")", ":", "%", "_", "*", $.word_char),
    unsyms_less_colon_lsb: ($) => choice("@", "\\", "\"", "]", "<", ">", "|", "+", "#", ".", ")", "%", "_", "-", "*", $.word_char),
    unsyms_less_lsb_tag: (_$) => choice("\\", "\"", "]", "<", ">", "|", "+", ".", ")", "-", "*"),
    unsyms_less_digit: ($) => choice("@", "\\", "\"", "[", "]", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "-", "*", $.alpha),
    unsyms_less_lsb_at_digit: ($) => choice("\\", "\"", "]", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "-", "*", $.alpha),
    unsyms_less_lsb_X_hyphen: ($) => choice("@", "\\", "\"", "]", "<", ">", "|", "+", "#", ".", ")", ":", "%", "_", "*", $.word_char_less_X),
    unsyms_less_ab_digit_hy: ($) => choice("@", "\\", "\"", "[", "]", "|", "+", "#", ".", ")", ":", "%", "_", "*", $.alpha),
    unsyms_less_timestamp: ($) => choice("@", "\\", "\"", "|", "+", "#", ".", ")", "%", "_", "*", $.alpha),
    unsyms_less_hypl_rb_dig: ($) => choice("@", "\\", "\"", "[", "<", "|", "#", ".", ")", ":", "%", "_", "*", $.alpha),

    not_newline: ($) => repeat1(choice(
      repeat1($.not_newline1),
      $.big_tokes,
      $.word_char_n)),
    not_whitespace: ($) => repeat1(choice(
      repeat1($.not_whitespace1),
      $.big_tokes,
      $.word_char_n)),
    not_whitespace_l_d: ($) => repeat1(choice(
      repeat1($.not_whitespace1),
      $.big_tokes_less_d,
      $.word_char_n)),

    not_newline_not_asterisk_src_end: ($) => repeat1(choice(
      repeat1($.not_newline),
      $.big_tokes_less_s_src_end,
      $.word_char_n)),
    not_newline_not_src_end: ($) => repeat1(choice(
      repeat1($.not_newline),
      $.big_tokes_less_src_end,
      $.word_char_n)),

    not_newline1: ($) => choice($.not_whitespace1, $.space, $.tab),
    not_whitespace1: ($) => choice(/[^ \t\n0-9a-zA-Z\\"|:%_*@+-\[\]>]/, $.non_whitespace_token),

    not_at_whitespace1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_at),
    not_at_newline1: ($) => choice($.not_at_whitespace1, $.wsnn),
    not_at1: ($) => choice($.not_at_newline1, $.newline),

    not_lsb_at_digit_newline1: ($) => choice(
      $.ns_nwt_less_negated,
      $.non_whitespace_token,
      $.unsyms_less_digit,
      $.wsnn),
    not_lsb_at_digits_newline: ($) => repeat1(choice(
      $.not_lsb_at_digit_newline1,
      $.big_tokes,
      $.alpha_n)),

    not_ab_digit_hy_newline1: ($) => choice(
      $.ns_nwt_less_negated,
      $.unsyms_less_ab_digit_hy,
      $.wsnn),
    not_ab_digits_hy_newline: ($) => repeat1(choice(
      $.not_ab_digit_hy_newline1,
      $.big_tokes_less_p,
      $.alpha_n)),

    not_lsb_hy_plus_digit_whitespace1: ($) => choice(
      $.ns_nwt_less_negated,
      $.unsyms_less_hypl_rb_dig,
      $.big_tokes,
      $.alpha_n),
    not_lsb_hy_plus_digit_whitespace: ($) => repeat1($.not_lsb_hy_plus_digit_whitespace),


    not_lsb_space_X_hyphen_newline1: ($) => choice(
      $.ns_nwt_less_negated,
      $.unsyms_less_lsb_X_hyphen,
      $.wsnn),

    not_lsb_space_X_hyphen_newline: ($) => repeat1(choice( $.not_lsb_space_X_hyphen_newline1, $.big_tokes, $.word_char_n )),
    not_space_X_hyphen_newline1: ($) => choice($.not_lsb_space_X_hyphen_newline1, "["),

    ns_nwt_less_negated: ($) => choice(/[^ \t\n0-9a-zA-Z\\"|:%_*@+-\[\]>]/, $.nwt_less_negated),

    not_plan_keyword_timestamp_newline: ($) => repeat1(choice( $.ns_nwt_less_negated, $.unsyms_less_timestamp, $.big_tokes_less_p, $.word_char_n )),

    not_COMMENT_RTK_lsb_whitespace: ($) => repeat1(choice( $.not_lsb_whitespace1, $.big_tokes_less_COMMENT_RTK, $.word_char_n )),

    not_COMMENT_RTK_lsb_tag_whitespace: ($) => repeat1(choice( $.not_lsb_tag_whitespace1, $.big_tokes_less_COMMENT_RTK, $.word_char_n )),
    not_lsb_tag_whitespace1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_lsb_tag),

    not_alpha_whitespace1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_alpha),
    not_alpha_newline1: ($) => choice($.not_alpha_whitespace1, $.wsnn),

    not_digit_newline1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_digit, $.wsnn),
    not_digits_newline: ($) => repeat1(choice( $.not_digit_newline1, $.big_tokes, $.alpha_n )),

    not_asterisk_whitespace1: ($) =>    choice($.ns_nwt_less_negated, $.unsyms_less_asterisk),
    not_asterisk_newline1: ($) =>       choice($.not_asterisk_whitespace1, $.wsnn),
    not_asterisk1: ($) =>               choice($.not_asterisk_newline1, $.newline),

    not_lsb_whitespace1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_lsb),
    not_lsb_newline1: ($) => choice($.not_lsb_whitespace1, $.wsnn),

    not_rsb_newline1: ($) => choice($.ns_nwt_less_negated, $.wsnn, $.unsyms_less_rsb),
    not_rsb_newline: ($) => repeat1(choice( $.not_rsb_newline1, $.big_tokes, $.word_char_n )),

    not_colon_lsb_whitespace1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_colon_lsb),
    not_colon_lsb_newline1: ($) => choice($.not_colon_lsb_whitespace1, $.wsnn),

    not_bullet_pipe1: ($) => choice($.ns_nwt_less_negated, $.whitespace, $.unsyms_less_pipe_bullet),
    not_plus_hyphen1: ($) => choice($.ns_nwt_less_negated, $.whitespace, $.unsyms_less_plus_hyphen),

    not_pl_start_newline1: ($) => choice($.ns_nwt_less_negated, $.wsnn, $.unsyms_less_pl_start),
    not_prp_newline1: ($) =>      choice($.ns_nwt_less_negated, $.wsnn, $.unsyms_less_prp),

    not_colon_whitespace1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_colon),
    not_colon_newline1: ($) =>  choice($.not_colon_whitespace1, $.wsnn),
    not_colon_newline: ($) =>    repeat1(choice( $.not_colon_newline1, $.big_tokes_less_d, $.word_char_n )),

    not_pipe_not_newline1: ($) => choice($.ns_nwt_less_negated, $.wsnn, $.unsyms_less_pipe),
    not_pipe_not_newline: ($) => repeat1(choice( $.not_pipe_not_newline1, $.big_tokes, $.word_char_n )),

    not_pipe_bs_newline1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_pipe_bs, $.wsnn),
    not_pipe_bs_newline: ($) => repeat1(choice( $.not_pipe_bs_newline1, $.big_tokes, $.word_char_n )),

    not_tag_whitespace1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_tag),
    not_tag_whitespace: ($) => repeat1($.not_tag_whitespace1),
      not_tag_newline1: ($) => choice($.not_tag_whitespace1, $.wsnn),
    not_tag_newline: ($) => repeat1($.not_tag_newline1),

    not_pl_start_whitespace1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_pl_start),
    not_plus_whitespace1: ($) =>     choice($.ns_nwt_less_negated, $.unsyms_less_plus),
    not_plus_newline1: ($) => choice($.not_plus_whitespace1, $.wsnn),
    not_bs_dq_whitespace1: ($) =>    choice($.ns_nwt_less_negated, $.unsyms_less_bs_dq),
    not_bs_dq_newline1: ($) => choice($.space, $.tab, $.not_bs_dq_whitespace1),
    not_bs_dq1: ($) => choice($.whitespace, $.not_bs_dq_whitespace1),
    not_bs_dq_newline: ($) => repeat1(choice( $.not_bs_dq_newline1, $.word_char_n )),
    not_bs_dq: ($) => repeat1(choice( $.not_bs_dq1, $.word_char_n )),

    not_dq_newline1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_dq, $.wsnn),
    not_dq_newline: ($) => repeat1(choice( $.not_dq_newline1, $.big_tokes, $.word_char_n )),

    not_dq_ph_newline1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_dq_ph, $.wsnn),
    not_dq_ph_newline: ($) => repeat1(choice( $.not_dq_ph_newline1, $.big_tokes, $.word_char_n )),

    not_hash_newline1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_hash, $.wsnn),

    not_pipe_bullet_not_whitespace1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_pipe_bullet),
    not_sb_colon_whitespace1: ($) => choice($.ns_nwt_less_negated, $.unsyms_less_sb_colon),
    not_sb_colon_whitespace: ($) => repeat1($.not_sb_colon_whitespace1),

  },
});
