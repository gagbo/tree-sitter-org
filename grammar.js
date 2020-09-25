module.exports = grammar({
  name: "org",

  // TODO: org_headline might need to be an external because of the BOL assertion
  // on stars that can't work in this grammar.js file
  externals: ($) => [$.org_headline],

  rules: {
    // TODO: add the metadata header
    org_file: ($) => repeat($._section),

    _section: ($) =>
      choice(
        $.headline
        // TODO: add other kinds
      ),

    headline: ($) =>
      seq(
        field("level", $.stars),
        optional(field("todo", $.todo)),
        optional(field("prio", $.priority)),
        optional(field("comment", $.comment)),
        optional(prec(-50, field("title", $.title))),
        optional(field("tags", $.tags)),
        $.line_ending
      ),

    // text: ($) => /[^\r\n]+/,
    line_ending: ($) => token(choice(/\r\n/, /\n/)),
    // whitespace: ($) => /\s+/,

    stars: ($) => /\*+/,

    title: ($) => /[^\r\n]+/,
    priority: ($) => /\[#[A-Ca-c]\]/,
    todo: ($) => token(choice("TODO", "NEXT", "DONE", "WAITING", "CANCELLED")),
    comment: ($) => /COMMENT/,
    tag: ($) => /[a-zA-Z0-9#%]+/,
    tags: ($) => seq(/:/, repeat1(seq($.tag, /:/))),
  },
});
