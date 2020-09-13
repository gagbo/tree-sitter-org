module.exports = grammar({
  name: 'org',

  externals: $ => [
      $.org_headline
  ],

  rules: {
    // TODO: add the metadata header
    org_file: $ => repeat($._section),

    _section: $ => choice(
        $.headline
        // TODO: add other kinds
    ),
    
    headline: $ => seq(
        field('level', $.stars),
        $.whitespace,
        field('title', $.title)
    ),

    title: $ => $.text,
    stars: $ => /\*+/,
    text: $ => /[^\r\n]+/,
    whitespace: $ => /\s+/
  }
});

