#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 74
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 16
#define ALIAS_COUNT 0
#define TOKEN_COUNT 10
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 7
#define MAX_ALIAS_SEQUENCE_LENGTH 7

enum {
  sym_line_ending = 1,
  sym_stars = 2,
  sym_priority = 3,
  sym_todo = 4,
  sym_comment = 5,
  sym_tag = 6,
  anon_sym_COLON = 7,
  sym_title = 8,
  sym_org_headline = 9,
  sym_org_file = 10,
  sym__section = 11,
  sym_headline = 12,
  sym_tags = 13,
  aux_sym_org_file_repeat1 = 14,
  aux_sym_tags_repeat1 = 15,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_line_ending] = "line_ending",
  [sym_stars] = "stars",
  [sym_priority] = "priority",
  [sym_todo] = "todo",
  [sym_comment] = "comment",
  [sym_tag] = "tag",
  [anon_sym_COLON] = ":",
  [sym_title] = "title",
  [sym_org_headline] = "org_headline",
  [sym_org_file] = "org_file",
  [sym__section] = "_section",
  [sym_headline] = "headline",
  [sym_tags] = "tags",
  [aux_sym_org_file_repeat1] = "org_file_repeat1",
  [aux_sym_tags_repeat1] = "tags_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_line_ending] = sym_line_ending,
  [sym_stars] = sym_stars,
  [sym_priority] = sym_priority,
  [sym_todo] = sym_todo,
  [sym_comment] = sym_comment,
  [sym_tag] = sym_tag,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_title] = sym_title,
  [sym_org_headline] = sym_org_headline,
  [sym_org_file] = sym_org_file,
  [sym__section] = sym__section,
  [sym_headline] = sym_headline,
  [sym_tags] = sym_tags,
  [aux_sym_org_file_repeat1] = aux_sym_org_file_repeat1,
  [aux_sym_tags_repeat1] = aux_sym_tags_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_line_ending] = {
    .visible = true,
    .named = true,
  },
  [sym_stars] = {
    .visible = true,
    .named = true,
  },
  [sym_priority] = {
    .visible = true,
    .named = true,
  },
  [sym_todo] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_tag] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_title] = {
    .visible = true,
    .named = true,
  },
  [sym_org_headline] = {
    .visible = true,
    .named = true,
  },
  [sym_org_file] = {
    .visible = true,
    .named = true,
  },
  [sym__section] = {
    .visible = false,
    .named = true,
  },
  [sym_headline] = {
    .visible = true,
    .named = true,
  },
  [sym_tags] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_org_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tags_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_comment = 1,
  field_end_title = 2,
  field_level = 3,
  field_prio = 4,
  field_tags = 5,
  field_title = 6,
  field_todo = 7,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_comment] = "comment",
  [field_end_title] = "end_title",
  [field_level] = "level",
  [field_prio] = "prio",
  [field_tags] = "tags",
  [field_title] = "title",
  [field_todo] = "todo",
};

static const TSFieldMapSlice ts_field_map_slices[33] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 3},
  [3] = {.index = 5, .length = 3},
  [4] = {.index = 8, .length = 3},
  [5] = {.index = 11, .length = 3},
  [6] = {.index = 14, .length = 3},
  [7] = {.index = 17, .length = 4},
  [8] = {.index = 21, .length = 4},
  [9] = {.index = 25, .length = 4},
  [10] = {.index = 29, .length = 4},
  [11] = {.index = 33, .length = 4},
  [12] = {.index = 37, .length = 4},
  [13] = {.index = 41, .length = 4},
  [14] = {.index = 45, .length = 4},
  [15] = {.index = 49, .length = 4},
  [16] = {.index = 53, .length = 4},
  [17] = {.index = 57, .length = 5},
  [18] = {.index = 62, .length = 5},
  [19] = {.index = 67, .length = 5},
  [20] = {.index = 72, .length = 5},
  [21] = {.index = 77, .length = 5},
  [22] = {.index = 82, .length = 5},
  [23] = {.index = 87, .length = 5},
  [24] = {.index = 92, .length = 5},
  [25] = {.index = 97, .length = 5},
  [26] = {.index = 102, .length = 5},
  [27] = {.index = 107, .length = 6},
  [28] = {.index = 113, .length = 6},
  [29] = {.index = 119, .length = 6},
  [30] = {.index = 125, .length = 6},
  [31] = {.index = 131, .length = 6},
  [32] = {.index = 137, .length = 7},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_end_title, 1},
    {field_level, 0},
  [2] =
    {field_end_title, 2},
    {field_level, 0},
    {field_prio, 1},
  [5] =
    {field_end_title, 2},
    {field_level, 0},
    {field_todo, 1},
  [8] =
    {field_comment, 1},
    {field_end_title, 2},
    {field_level, 0},
  [11] =
    {field_end_title, 2},
    {field_level, 0},
    {field_title, 1},
  [14] =
    {field_end_title, 2},
    {field_level, 0},
    {field_tags, 1},
  [17] =
    {field_comment, 2},
    {field_end_title, 3},
    {field_level, 0},
    {field_prio, 1},
  [21] =
    {field_end_title, 3},
    {field_level, 0},
    {field_prio, 1},
    {field_title, 2},
  [25] =
    {field_end_title, 3},
    {field_level, 0},
    {field_prio, 1},
    {field_tags, 2},
  [29] =
    {field_end_title, 3},
    {field_level, 0},
    {field_prio, 2},
    {field_todo, 1},
  [33] =
    {field_comment, 2},
    {field_end_title, 3},
    {field_level, 0},
    {field_todo, 1},
  [37] =
    {field_end_title, 3},
    {field_level, 0},
    {field_title, 2},
    {field_todo, 1},
  [41] =
    {field_end_title, 3},
    {field_level, 0},
    {field_tags, 2},
    {field_todo, 1},
  [45] =
    {field_comment, 1},
    {field_end_title, 3},
    {field_level, 0},
    {field_title, 2},
  [49] =
    {field_comment, 1},
    {field_end_title, 3},
    {field_level, 0},
    {field_tags, 2},
  [53] =
    {field_end_title, 3},
    {field_level, 0},
    {field_tags, 2},
    {field_title, 1},
  [57] =
    {field_comment, 2},
    {field_end_title, 4},
    {field_level, 0},
    {field_prio, 1},
    {field_title, 3},
  [62] =
    {field_comment, 2},
    {field_end_title, 4},
    {field_level, 0},
    {field_prio, 1},
    {field_tags, 3},
  [67] =
    {field_end_title, 4},
    {field_level, 0},
    {field_prio, 1},
    {field_tags, 3},
    {field_title, 2},
  [72] =
    {field_comment, 3},
    {field_end_title, 4},
    {field_level, 0},
    {field_prio, 2},
    {field_todo, 1},
  [77] =
    {field_end_title, 4},
    {field_level, 0},
    {field_prio, 2},
    {field_title, 3},
    {field_todo, 1},
  [82] =
    {field_end_title, 4},
    {field_level, 0},
    {field_prio, 2},
    {field_tags, 3},
    {field_todo, 1},
  [87] =
    {field_comment, 2},
    {field_end_title, 4},
    {field_level, 0},
    {field_title, 3},
    {field_todo, 1},
  [92] =
    {field_comment, 2},
    {field_end_title, 4},
    {field_level, 0},
    {field_tags, 3},
    {field_todo, 1},
  [97] =
    {field_end_title, 4},
    {field_level, 0},
    {field_tags, 3},
    {field_title, 2},
    {field_todo, 1},
  [102] =
    {field_comment, 1},
    {field_end_title, 4},
    {field_level, 0},
    {field_tags, 3},
    {field_title, 2},
  [107] =
    {field_comment, 2},
    {field_end_title, 5},
    {field_level, 0},
    {field_prio, 1},
    {field_tags, 4},
    {field_title, 3},
  [113] =
    {field_comment, 3},
    {field_end_title, 5},
    {field_level, 0},
    {field_prio, 2},
    {field_title, 4},
    {field_todo, 1},
  [119] =
    {field_comment, 3},
    {field_end_title, 5},
    {field_level, 0},
    {field_prio, 2},
    {field_tags, 4},
    {field_todo, 1},
  [125] =
    {field_end_title, 5},
    {field_level, 0},
    {field_prio, 2},
    {field_tags, 4},
    {field_title, 3},
    {field_todo, 1},
  [131] =
    {field_comment, 2},
    {field_end_title, 5},
    {field_level, 0},
    {field_tags, 4},
    {field_title, 3},
    {field_todo, 1},
  [137] =
    {field_comment, 3},
    {field_end_title, 6},
    {field_level, 0},
    {field_prio, 2},
    {field_tags, 5},
    {field_title, 4},
    {field_todo, 1},
};

static TSSymbol ts_alias_sequences[33][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(10);
      if (lookahead == '*') ADVANCE(16);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == 'C') ADVANCE(20);
      if (lookahead == 'D') ADVANCE(43);
      if (lookahead == 'N') ADVANCE(26);
      if (lookahead == 'T') ADVANCE(42);
      if (lookahead == 'W') ADVANCE(21);
      if (lookahead == '[') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(11);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == 'C') ADVANCE(54);
      if (lookahead == 'D') ADVANCE(78);
      if (lookahead == 'N') ADVANCE(59);
      if (lookahead == 'T') ADVANCE(76);
      if (lookahead == 'W') ADVANCE(55);
      if (lookahead == '[') ADVANCE(53);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(49);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '\r') ADVANCE(2);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(2)
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(13);
      if (lookahead == '\r') ADVANCE(3);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == 'C') ADVANCE(75);
      if (lookahead == '[') ADVANCE(53);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(50);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(14);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == 'C') ADVANCE(75);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(51);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(15);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(52);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(9);
      END_STATE();
    case 7:
      if (lookahead == ']') ADVANCE(17);
      END_STATE();
    case 8:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 9:
      if (('A' <= lookahead && lookahead <= 'C') ||
          ('a' <= lookahead && lookahead <= 'c')) ADVANCE(7);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_line_ending);
      if (lookahead == '\n') ADVANCE(11);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(49);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_line_ending);
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '\r') ADVANCE(2);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_line_ending);
      if (lookahead == '\n') ADVANCE(13);
      if (lookahead == '\r') ADVANCE(3);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(50);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_line_ending);
      if (lookahead == '\n') ADVANCE(14);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(51);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_line_ending);
      if (lookahead == '\n') ADVANCE(15);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(52);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_priority);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_todo);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'A') ADVANCE(37);
      if (lookahead == 'O') ADVANCE(35);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'A') ADVANCE(31);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'C') ADVANCE(27);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'D') ADVANCE(47);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'D') ADVANCE(41);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'E') ADVANCE(47);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'E') ADVANCE(46);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'E') ADVANCE(33);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'E') ADVANCE(23);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'E') ADVANCE(38);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'G') ADVANCE(47);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'I') ADVANCE(45);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'I') ADVANCE(39);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'L') ADVANCE(34);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'L') ADVANCE(28);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'M') ADVANCE(36);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'M') ADVANCE(29);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'N') ADVANCE(22);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'N') ADVANCE(44);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'N') ADVANCE(30);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'N') ADVANCE(25);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'O') ADVANCE(47);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'O') ADVANCE(24);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'O') ADVANCE(40);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'T') ADVANCE(47);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'T') ADVANCE(32);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == 'X') ADVANCE(44);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == '\n') ADVANCE(11);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == 'C') ADVANCE(54);
      if (lookahead == 'D') ADVANCE(78);
      if (lookahead == 'N') ADVANCE(59);
      if (lookahead == 'T') ADVANCE(76);
      if (lookahead == 'W') ADVANCE(55);
      if (lookahead == '[') ADVANCE(53);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(49);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == '\n') ADVANCE(13);
      if (lookahead == '\r') ADVANCE(3);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == 'C') ADVANCE(75);
      if (lookahead == '[') ADVANCE(53);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(50);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == '\n') ADVANCE(14);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == 'C') ADVANCE(75);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(51);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == '\n') ADVANCE(15);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(52);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == '#') ADVANCE(84);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'A') ADVANCE(71);
      if (lookahead == 'O') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'A') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'C') ADVANCE(61);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'D') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'D') ADVANCE(77);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(67);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(74);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'G') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'I') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'I') ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'L') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'L') ADVANCE(62);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'M') ADVANCE(70);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'M') ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'N') ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'N') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'N') ADVANCE(60);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'N') ADVANCE(80);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'O') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'O') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'O') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'O') ADVANCE(73);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'T') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'T') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'T') ADVANCE(66);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'X') ADVANCE(79);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == ']') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_title);
      if (('A' <= lookahead && lookahead <= 'C') ||
          ('a' <= lookahead && lookahead <= 'c')) ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_title);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 4},
  [6] = {.lex_state = 4},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 5},
  [9] = {.lex_state = 5},
  [10] = {.lex_state = 5},
  [11] = {.lex_state = 5},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 8},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 2},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 2},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 2},
  [61] = {.lex_state = 2},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 2},
  [64] = {.lex_state = 2},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 2},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 2},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 2},
};

enum {
  ts_external_token_org_headline = 0,
};

static TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_org_headline] = sym_org_headline,
};

static bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_org_headline] = true,
  },
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_stars] = ACTIONS(1),
    [sym_priority] = ACTIONS(1),
    [sym_todo] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [sym_tag] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_org_headline] = ACTIONS(1),
  },
  [1] = {
    [sym_org_file] = STATE(70),
    [sym__section] = STATE(4),
    [sym_headline] = STATE(4),
    [aux_sym_org_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_stars] = ACTIONS(5),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(7), 1,
      sym_line_ending,
    ACTIONS(9), 1,
      sym_priority,
    ACTIONS(11), 1,
      sym_todo,
    ACTIONS(13), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(17), 1,
      sym_title,
    STATE(64), 1,
      sym_tags,
  [22] = 6,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(19), 1,
      sym_line_ending,
    ACTIONS(21), 1,
      sym_priority,
    ACTIONS(23), 1,
      sym_comment,
    ACTIONS(25), 1,
      sym_title,
    STATE(57), 1,
      sym_tags,
  [41] = 3,
    ACTIONS(5), 1,
      sym_stars,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    STATE(7), 3,
      sym__section,
      sym_headline,
      aux_sym_org_file_repeat1,
  [53] = 5,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(29), 1,
      sym_line_ending,
    ACTIONS(31), 1,
      sym_comment,
    ACTIONS(33), 1,
      sym_title,
    STATE(65), 1,
      sym_tags,
  [69] = 5,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(35), 1,
      sym_line_ending,
    ACTIONS(37), 1,
      sym_comment,
    ACTIONS(39), 1,
      sym_title,
    STATE(66), 1,
      sym_tags,
  [85] = 3,
    ACTIONS(41), 1,
      ts_builtin_sym_end,
    ACTIONS(43), 1,
      sym_stars,
    STATE(7), 3,
      sym__section,
      sym_headline,
      aux_sym_org_file_repeat1,
  [97] = 4,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(46), 1,
      sym_line_ending,
    ACTIONS(48), 1,
      sym_title,
    STATE(58), 1,
      sym_tags,
  [110] = 4,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(50), 1,
      sym_line_ending,
    ACTIONS(52), 1,
      sym_title,
    STATE(62), 1,
      sym_tags,
  [123] = 4,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(54), 1,
      sym_line_ending,
    ACTIONS(56), 1,
      sym_title,
    STATE(73), 1,
      sym_tags,
  [136] = 4,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(58), 1,
      sym_line_ending,
    ACTIONS(60), 1,
      sym_title,
    STATE(68), 1,
      sym_tags,
  [149] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(62), 1,
      sym_line_ending,
    STATE(71), 1,
      sym_tags,
  [159] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(64), 1,
      sym_line_ending,
    STATE(60), 1,
      sym_tags,
  [169] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(66), 1,
      sym_line_ending,
    STATE(69), 1,
      sym_tags,
  [179] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(68), 1,
      sym_line_ending,
    STATE(67), 1,
      sym_tags,
  [189] = 3,
    ACTIONS(70), 1,
      sym_line_ending,
    ACTIONS(72), 1,
      sym_tag,
    STATE(19), 1,
      aux_sym_tags_repeat1,
  [199] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(74), 1,
      sym_line_ending,
    STATE(56), 1,
      sym_tags,
  [209] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(76), 1,
      sym_line_ending,
    STATE(63), 1,
      sym_tags,
  [219] = 3,
    ACTIONS(78), 1,
      sym_line_ending,
    ACTIONS(80), 1,
      sym_tag,
    STATE(19), 1,
      aux_sym_tags_repeat1,
  [229] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(83), 1,
      sym_line_ending,
    STATE(61), 1,
      sym_tags,
  [239] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(85), 1,
      sym_line_ending,
    STATE(59), 1,
      sym_tags,
  [249] = 1,
    ACTIONS(87), 2,
      ts_builtin_sym_end,
      sym_stars,
  [254] = 1,
    ACTIONS(89), 2,
      ts_builtin_sym_end,
      sym_stars,
  [259] = 1,
    ACTIONS(91), 2,
      ts_builtin_sym_end,
      sym_stars,
  [264] = 1,
    ACTIONS(93), 2,
      ts_builtin_sym_end,
      sym_stars,
  [269] = 1,
    ACTIONS(95), 2,
      ts_builtin_sym_end,
      sym_stars,
  [274] = 1,
    ACTIONS(97), 2,
      ts_builtin_sym_end,
      sym_stars,
  [279] = 1,
    ACTIONS(99), 2,
      ts_builtin_sym_end,
      sym_stars,
  [284] = 1,
    ACTIONS(101), 2,
      ts_builtin_sym_end,
      sym_stars,
  [289] = 1,
    ACTIONS(103), 2,
      ts_builtin_sym_end,
      sym_stars,
  [294] = 1,
    ACTIONS(105), 2,
      ts_builtin_sym_end,
      sym_stars,
  [299] = 1,
    ACTIONS(107), 2,
      ts_builtin_sym_end,
      sym_stars,
  [304] = 1,
    ACTIONS(109), 2,
      ts_builtin_sym_end,
      sym_stars,
  [309] = 1,
    ACTIONS(111), 2,
      ts_builtin_sym_end,
      sym_stars,
  [314] = 1,
    ACTIONS(113), 2,
      ts_builtin_sym_end,
      sym_stars,
  [319] = 1,
    ACTIONS(115), 2,
      ts_builtin_sym_end,
      sym_stars,
  [324] = 1,
    ACTIONS(117), 2,
      ts_builtin_sym_end,
      sym_stars,
  [329] = 1,
    ACTIONS(119), 2,
      ts_builtin_sym_end,
      sym_stars,
  [334] = 1,
    ACTIONS(121), 2,
      ts_builtin_sym_end,
      sym_stars,
  [339] = 1,
    ACTIONS(123), 2,
      ts_builtin_sym_end,
      sym_stars,
  [344] = 1,
    ACTIONS(125), 2,
      ts_builtin_sym_end,
      sym_stars,
  [349] = 1,
    ACTIONS(127), 2,
      ts_builtin_sym_end,
      sym_stars,
  [354] = 1,
    ACTIONS(129), 2,
      ts_builtin_sym_end,
      sym_stars,
  [359] = 1,
    ACTIONS(131), 2,
      ts_builtin_sym_end,
      sym_stars,
  [364] = 1,
    ACTIONS(133), 2,
      ts_builtin_sym_end,
      sym_stars,
  [369] = 1,
    ACTIONS(135), 2,
      ts_builtin_sym_end,
      sym_stars,
  [374] = 1,
    ACTIONS(137), 2,
      ts_builtin_sym_end,
      sym_stars,
  [379] = 1,
    ACTIONS(139), 2,
      ts_builtin_sym_end,
      sym_stars,
  [384] = 1,
    ACTIONS(78), 2,
      sym_line_ending,
      sym_tag,
  [389] = 2,
    ACTIONS(141), 1,
      sym_tag,
    STATE(16), 1,
      aux_sym_tags_repeat1,
  [396] = 1,
    ACTIONS(143), 2,
      ts_builtin_sym_end,
      sym_stars,
  [401] = 1,
    ACTIONS(145), 2,
      ts_builtin_sym_end,
      sym_stars,
  [406] = 1,
    ACTIONS(147), 2,
      ts_builtin_sym_end,
      sym_stars,
  [411] = 1,
    ACTIONS(149), 2,
      ts_builtin_sym_end,
      sym_stars,
  [416] = 1,
    ACTIONS(151), 2,
      ts_builtin_sym_end,
      sym_stars,
  [421] = 1,
    ACTIONS(153), 1,
      sym_line_ending,
  [425] = 1,
    ACTIONS(155), 1,
      sym_line_ending,
  [429] = 1,
    ACTIONS(157), 1,
      sym_line_ending,
  [433] = 1,
    ACTIONS(159), 1,
      sym_line_ending,
  [437] = 1,
    ACTIONS(161), 1,
      sym_line_ending,
  [441] = 1,
    ACTIONS(163), 1,
      sym_line_ending,
  [445] = 1,
    ACTIONS(165), 1,
      sym_line_ending,
  [449] = 1,
    ACTIONS(167), 1,
      sym_line_ending,
  [453] = 1,
    ACTIONS(169), 1,
      sym_line_ending,
  [457] = 1,
    ACTIONS(171), 1,
      sym_line_ending,
  [461] = 1,
    ACTIONS(173), 1,
      sym_line_ending,
  [465] = 1,
    ACTIONS(175), 1,
      sym_line_ending,
  [469] = 1,
    ACTIONS(177), 1,
      sym_line_ending,
  [473] = 1,
    ACTIONS(179), 1,
      sym_line_ending,
  [477] = 1,
    ACTIONS(181), 1,
      ts_builtin_sym_end,
  [481] = 1,
    ACTIONS(183), 1,
      sym_line_ending,
  [485] = 1,
    ACTIONS(185), 1,
      anon_sym_COLON,
  [489] = 1,
    ACTIONS(187), 1,
      sym_line_ending,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 22,
  [SMALL_STATE(4)] = 41,
  [SMALL_STATE(5)] = 53,
  [SMALL_STATE(6)] = 69,
  [SMALL_STATE(7)] = 85,
  [SMALL_STATE(8)] = 97,
  [SMALL_STATE(9)] = 110,
  [SMALL_STATE(10)] = 123,
  [SMALL_STATE(11)] = 136,
  [SMALL_STATE(12)] = 149,
  [SMALL_STATE(13)] = 159,
  [SMALL_STATE(14)] = 169,
  [SMALL_STATE(15)] = 179,
  [SMALL_STATE(16)] = 189,
  [SMALL_STATE(17)] = 199,
  [SMALL_STATE(18)] = 209,
  [SMALL_STATE(19)] = 219,
  [SMALL_STATE(20)] = 229,
  [SMALL_STATE(21)] = 239,
  [SMALL_STATE(22)] = 249,
  [SMALL_STATE(23)] = 254,
  [SMALL_STATE(24)] = 259,
  [SMALL_STATE(25)] = 264,
  [SMALL_STATE(26)] = 269,
  [SMALL_STATE(27)] = 274,
  [SMALL_STATE(28)] = 279,
  [SMALL_STATE(29)] = 284,
  [SMALL_STATE(30)] = 289,
  [SMALL_STATE(31)] = 294,
  [SMALL_STATE(32)] = 299,
  [SMALL_STATE(33)] = 304,
  [SMALL_STATE(34)] = 309,
  [SMALL_STATE(35)] = 314,
  [SMALL_STATE(36)] = 319,
  [SMALL_STATE(37)] = 324,
  [SMALL_STATE(38)] = 329,
  [SMALL_STATE(39)] = 334,
  [SMALL_STATE(40)] = 339,
  [SMALL_STATE(41)] = 344,
  [SMALL_STATE(42)] = 349,
  [SMALL_STATE(43)] = 354,
  [SMALL_STATE(44)] = 359,
  [SMALL_STATE(45)] = 364,
  [SMALL_STATE(46)] = 369,
  [SMALL_STATE(47)] = 374,
  [SMALL_STATE(48)] = 379,
  [SMALL_STATE(49)] = 384,
  [SMALL_STATE(50)] = 389,
  [SMALL_STATE(51)] = 396,
  [SMALL_STATE(52)] = 401,
  [SMALL_STATE(53)] = 406,
  [SMALL_STATE(54)] = 411,
  [SMALL_STATE(55)] = 416,
  [SMALL_STATE(56)] = 421,
  [SMALL_STATE(57)] = 425,
  [SMALL_STATE(58)] = 429,
  [SMALL_STATE(59)] = 433,
  [SMALL_STATE(60)] = 437,
  [SMALL_STATE(61)] = 441,
  [SMALL_STATE(62)] = 445,
  [SMALL_STATE(63)] = 449,
  [SMALL_STATE(64)] = 453,
  [SMALL_STATE(65)] = 457,
  [SMALL_STATE(66)] = 461,
  [SMALL_STATE(67)] = 465,
  [SMALL_STATE(68)] = 469,
  [SMALL_STATE(69)] = 473,
  [SMALL_STATE(70)] = 477,
  [SMALL_STATE(71)] = 481,
  [SMALL_STATE(72)] = 485,
  [SMALL_STATE(73)] = 489,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_org_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_org_file, 1),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_org_file_repeat1, 2),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_org_file_repeat1, 2), SHIFT_REPEAT(2),
  [46] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [50] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [52] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tags, 2),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_tags_repeat1, 2),
  [80] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_tags_repeat1, 2), SHIFT_REPEAT(72),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 9),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 15),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 4),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 7, .production_id = 32),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 31),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 5),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 30),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 6),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 7),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 29),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 28),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 8),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 27),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 3),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 10),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 26),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 2),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 25),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 11),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 24),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 23),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 12),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 22),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 13),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 14),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 21),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 2, .production_id = 1),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 16),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 17),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 20),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 18),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 19),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [181] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_org_external_scanner_create(void);
void tree_sitter_org_external_scanner_destroy(void *);
bool tree_sitter_org_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_org_external_scanner_serialize(void *, char *);
void tree_sitter_org_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_org(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .public_symbol_map = ts_symbol_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .field_count = FIELD_COUNT,
    .field_names = ts_field_names,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .external_scanner = {
      (const bool *)ts_external_scanner_states,
      ts_external_scanner_symbol_map,
      tree_sitter_org_external_scanner_create,
      tree_sitter_org_external_scanner_destroy,
      tree_sitter_org_external_scanner_scan,
      tree_sitter_org_external_scanner_serialize,
      tree_sitter_org_external_scanner_deserialize,
    },
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
