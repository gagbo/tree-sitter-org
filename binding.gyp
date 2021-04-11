{
  "targets": [
    {
      "target_name": "tree_sitter_org_binding",
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "src"
      ],
      "sources": [
        "src/parser.c",
        "src/scanner.cc",
        "src/binding.cc"
      ],
      "cflags_c": [
        "-std=c99",
      ],
      "cflags_cc": [
        "-std=c++17",
      ]
    }
  ]
}
