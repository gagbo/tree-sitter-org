module.exports = grammar({
  name: 'Org',

  rules: {
    // TODO: add the metadata header
    org_file: $ => repeat($._section),

    _section: $ => choice(
        $.headline
        // TODO: add other kinds
    ),
    
    headline: $ => seq(
        $.stars,
        $.whitespace,
        $.title
    ),

    title: $ => $.text,
    stars: $ => /\*+/,
    text: $ => /[^\r\n]+/,
    whitespace: $ => /\s+/
  }
});

