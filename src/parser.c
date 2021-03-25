#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 75
#define LARGE_STATE_COUNT 3
#define SYMBOL_COUNT 21
#define ALIAS_COUNT 0
#define TOKEN_COUNT 14
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 7
#define MAX_ALIAS_SEQUENCE_LENGTH 7

enum {
  sym_line_ending = 1,
  sym_stars = 2,
  sym_priority = 3,
  anon_sym_TODO = 4,
  anon_sym_NEXT = 5,
  anon_sym_DONE = 6,
  anon_sym_WAITING = 7,
  anon_sym_CANCELLED = 8,
  sym_comment = 9,
  sym_tag = 10,
  anon_sym_COLON = 11,
  sym_title = 12,
  sym_org_headline = 13,
  sym_org_file = 14,
  sym__section = 15,
  sym_headline = 16,
  sym_todo = 17,
  sym_tags = 18,
  aux_sym_org_file_repeat1 = 19,
  aux_sym_tags_repeat1 = 20,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_line_ending] = "line_ending",
  [sym_stars] = "stars",
  [sym_priority] = "priority",
  [anon_sym_TODO] = "TODO",
  [anon_sym_NEXT] = "NEXT",
  [anon_sym_DONE] = "DONE",
  [anon_sym_WAITING] = "WAITING",
  [anon_sym_CANCELLED] = "CANCELLED",
  [sym_comment] = "comment",
  [sym_tag] = "tag",
  [anon_sym_COLON] = ":",
  [sym_title] = "title",
  [sym_org_headline] = "org_headline",
  [sym_org_file] = "org_file",
  [sym__section] = "_section",
  [sym_headline] = "headline",
  [sym_todo] = "todo",
  [sym_tags] = "tags",
  [aux_sym_org_file_repeat1] = "org_file_repeat1",
  [aux_sym_tags_repeat1] = "tags_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_line_ending] = sym_line_ending,
  [sym_stars] = sym_stars,
  [sym_priority] = sym_priority,
  [anon_sym_TODO] = anon_sym_TODO,
  [anon_sym_NEXT] = anon_sym_NEXT,
  [anon_sym_DONE] = anon_sym_DONE,
  [anon_sym_WAITING] = anon_sym_WAITING,
  [anon_sym_CANCELLED] = anon_sym_CANCELLED,
  [sym_comment] = sym_comment,
  [sym_tag] = sym_tag,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_title] = sym_title,
  [sym_org_headline] = sym_org_headline,
  [sym_org_file] = sym_org_file,
  [sym__section] = sym__section,
  [sym_headline] = sym_headline,
  [sym_todo] = sym_todo,
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
  [anon_sym_TODO] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NEXT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DONE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_WAITING] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CANCELLED] = {
    .visible = true,
    .named = false,
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
  [sym_todo] = {
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
    {field_comment, 1},
    {field_end_title, 2},
    {field_level, 0},
  [8] =
    {field_end_title, 2},
    {field_level, 0},
    {field_title, 1},
  [11] =
    {field_end_title, 2},
    {field_level, 0},
    {field_todo, 1},
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
    {field_comment, 1},
    {field_end_title, 3},
    {field_level, 0},
    {field_title, 2},
  [33] =
    {field_comment, 1},
    {field_end_title, 3},
    {field_level, 0},
    {field_tags, 2},
  [37] =
    {field_end_title, 3},
    {field_level, 0},
    {field_tags, 2},
    {field_title, 1},
  [41] =
    {field_end_title, 3},
    {field_level, 0},
    {field_prio, 2},
    {field_todo, 1},
  [45] =
    {field_comment, 2},
    {field_end_title, 3},
    {field_level, 0},
    {field_todo, 1},
  [49] =
    {field_end_title, 3},
    {field_level, 0},
    {field_title, 2},
    {field_todo, 1},
  [53] =
    {field_end_title, 3},
    {field_level, 0},
    {field_tags, 2},
    {field_todo, 1},
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
    {field_comment, 1},
    {field_end_title, 4},
    {field_level, 0},
    {field_tags, 3},
    {field_title, 2},
  [77] =
    {field_comment, 3},
    {field_end_title, 4},
    {field_level, 0},
    {field_prio, 2},
    {field_todo, 1},
  [82] =
    {field_end_title, 4},
    {field_level, 0},
    {field_prio, 2},
    {field_title, 3},
    {field_todo, 1},
  [87] =
    {field_end_title, 4},
    {field_level, 0},
    {field_prio, 2},
    {field_tags, 3},
    {field_todo, 1},
  [92] =
    {field_comment, 2},
    {field_end_title, 4},
    {field_level, 0},
    {field_title, 3},
    {field_todo, 1},
  [97] =
    {field_comment, 2},
    {field_end_title, 4},
    {field_level, 0},
    {field_tags, 3},
    {field_todo, 1},
  [102] =
    {field_end_title, 4},
    {field_level, 0},
    {field_tags, 3},
    {field_title, 2},
    {field_todo, 1},
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
      if (eof) ADVANCE(38);
      if (lookahead == '*') ADVANCE(44);
      if (lookahead == ':') ADVANCE(53);
      if (lookahead == 'C') ADVANCE(7);
      if (lookahead == 'D') ADVANCE(30);
      if (lookahead == 'N') ADVANCE(12);
      if (lookahead == 'T') ADVANCE(28);
      if (lookahead == 'W') ADVANCE(8);
      if (lookahead == '[') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(39);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == ':') ADVANCE(53);
      if (lookahead == 'C') ADVANCE(59);
      if (lookahead == 'D') ADVANCE(83);
      if (lookahead == 'N') ADVANCE(65);
      if (lookahead == 'T') ADVANCE(82);
      if (lookahead == 'W') ADVANCE(60);
      if (lookahead == '[') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(54);
      if (lookahead != 0) ADVANCE(90);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(40);
      if (lookahead == '\r') ADVANCE(2);
      if (lookahead == ':') ADVANCE(53);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(2)
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(41);
      if (lookahead == '\r') ADVANCE(3);
      if (lookahead == ':') ADVANCE(53);
      if (lookahead == 'C') ADVANCE(81);
      if (lookahead == '[') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(55);
      if (lookahead != 0) ADVANCE(90);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(42);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(53);
      if (lookahead == 'C') ADVANCE(81);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(56);
      if (lookahead != 0) ADVANCE(90);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(43);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ':') ADVANCE(53);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead != 0) ADVANCE(90);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(37);
      END_STATE();
    case 7:
      if (lookahead == 'A') ADVANCE(24);
      if (lookahead == 'O') ADVANCE(22);
      END_STATE();
    case 8:
      if (lookahead == 'A') ADVANCE(18);
      END_STATE();
    case 9:
      if (lookahead == 'C') ADVANCE(14);
      END_STATE();
    case 10:
      if (lookahead == 'D') ADVANCE(50);
      END_STATE();
    case 11:
      if (lookahead == 'D') ADVANCE(29);
      END_STATE();
    case 12:
      if (lookahead == 'E') ADVANCE(34);
      END_STATE();
    case 13:
      if (lookahead == 'E') ADVANCE(48);
      END_STATE();
    case 14:
      if (lookahead == 'E') ADVANCE(20);
      END_STATE();
    case 15:
      if (lookahead == 'E') ADVANCE(10);
      END_STATE();
    case 16:
      if (lookahead == 'E') ADVANCE(27);
      END_STATE();
    case 17:
      if (lookahead == 'G') ADVANCE(49);
      END_STATE();
    case 18:
      if (lookahead == 'I') ADVANCE(33);
      END_STATE();
    case 19:
      if (lookahead == 'I') ADVANCE(25);
      END_STATE();
    case 20:
      if (lookahead == 'L') ADVANCE(21);
      END_STATE();
    case 21:
      if (lookahead == 'L') ADVANCE(15);
      END_STATE();
    case 22:
      if (lookahead == 'M') ADVANCE(23);
      END_STATE();
    case 23:
      if (lookahead == 'M') ADVANCE(16);
      END_STATE();
    case 24:
      if (lookahead == 'N') ADVANCE(9);
      END_STATE();
    case 25:
      if (lookahead == 'N') ADVANCE(17);
      END_STATE();
    case 26:
      if (lookahead == 'N') ADVANCE(13);
      END_STATE();
    case 27:
      if (lookahead == 'N') ADVANCE(32);
      END_STATE();
    case 28:
      if (lookahead == 'O') ADVANCE(11);
      END_STATE();
    case 29:
      if (lookahead == 'O') ADVANCE(46);
      END_STATE();
    case 30:
      if (lookahead == 'O') ADVANCE(26);
      END_STATE();
    case 31:
      if (lookahead == 'T') ADVANCE(47);
      END_STATE();
    case 32:
      if (lookahead == 'T') ADVANCE(51);
      END_STATE();
    case 33:
      if (lookahead == 'T') ADVANCE(19);
      END_STATE();
    case 34:
      if (lookahead == 'X') ADVANCE(31);
      END_STATE();
    case 35:
      if (lookahead == ']') ADVANCE(45);
      END_STATE();
    case 36:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(36)
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 37:
      if (('A' <= lookahead && lookahead <= 'C') ||
          ('a' <= lookahead && lookahead <= 'c')) ADVANCE(35);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_line_ending);
      if (lookahead == '\n') ADVANCE(39);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(54);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_line_ending);
      if (lookahead == '\n') ADVANCE(40);
      if (lookahead == '\r') ADVANCE(2);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_line_ending);
      if (lookahead == '\n') ADVANCE(41);
      if (lookahead == '\r') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(55);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_line_ending);
      if (lookahead == '\n') ADVANCE(42);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(56);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_line_ending);
      if (lookahead == '\n') ADVANCE(43);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_priority);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_TODO);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_NEXT);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_DONE);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_WAITING);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_CANCELLED);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == '\n') ADVANCE(39);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == ':') ADVANCE(53);
      if (lookahead == 'C') ADVANCE(59);
      if (lookahead == 'D') ADVANCE(83);
      if (lookahead == 'N') ADVANCE(65);
      if (lookahead == 'T') ADVANCE(82);
      if (lookahead == 'W') ADVANCE(60);
      if (lookahead == '[') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(54);
      if (lookahead != 0) ADVANCE(90);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == '\n') ADVANCE(41);
      if (lookahead == '\r') ADVANCE(3);
      if (lookahead == ':') ADVANCE(53);
      if (lookahead == 'C') ADVANCE(81);
      if (lookahead == '[') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(55);
      if (lookahead != 0) ADVANCE(90);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == '\n') ADVANCE(42);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(53);
      if (lookahead == 'C') ADVANCE(81);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(56);
      if (lookahead != 0) ADVANCE(90);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == '\n') ADVANCE(43);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ':') ADVANCE(53);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead != 0) ADVANCE(90);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == '#') ADVANCE(89);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'A') ADVANCE(76);
      if (lookahead == 'O') ADVANCE(74);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'A') ADVANCE(70);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'C') ADVANCE(66);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'D') ADVANCE(50);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'D') ADVANCE(80);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(48);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(62);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(79);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'G') ADVANCE(49);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'I') ADVANCE(86);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'I') ADVANCE(77);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'L') ADVANCE(73);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'L') ADVANCE(67);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'M') ADVANCE(75);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'M') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'N') ADVANCE(61);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'N') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'N') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'N') ADVANCE(85);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'O') ADVANCE(46);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'O') ADVANCE(74);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'O') ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'O') ADVANCE(78);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'T') ADVANCE(47);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'T') ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'T') ADVANCE(71);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'X') ADVANCE(84);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == ']') ADVANCE(45);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_title);
      if (('A' <= lookahead && lookahead <= 'C') ||
          ('a' <= lookahead && lookahead <= 'c')) ADVANCE(88);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_title);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
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
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 4},
  [7] = {.lex_state = 4},
  [8] = {.lex_state = 3},
  [9] = {.lex_state = 5},
  [10] = {.lex_state = 5},
  [11] = {.lex_state = 5},
  [12] = {.lex_state = 5},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 36},
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
  [40] = {.lex_state = 2},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
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
  [70] = {.lex_state = 2},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 2},
  [74] = {.lex_state = 0},
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
    [anon_sym_TODO] = ACTIONS(1),
    [anon_sym_NEXT] = ACTIONS(1),
    [anon_sym_DONE] = ACTIONS(1),
    [anon_sym_WAITING] = ACTIONS(1),
    [anon_sym_CANCELLED] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_org_headline] = ACTIONS(1),
  },
  [1] = {
    [sym_org_file] = STATE(71),
    [sym__section] = STATE(5),
    [sym_headline] = STATE(5),
    [aux_sym_org_file_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_stars] = ACTIONS(5),
  },
  [2] = {
    [sym_todo] = STATE(3),
    [sym_tags] = STATE(64),
    [sym_line_ending] = ACTIONS(7),
    [sym_priority] = ACTIONS(9),
    [anon_sym_TODO] = ACTIONS(11),
    [anon_sym_NEXT] = ACTIONS(11),
    [anon_sym_DONE] = ACTIONS(11),
    [anon_sym_WAITING] = ACTIONS(11),
    [anon_sym_CANCELLED] = ACTIONS(11),
    [sym_comment] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [sym_title] = ACTIONS(17),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 6,
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
    STATE(72), 1,
      sym_tags,
  [19] = 3,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(29), 1,
      sym_stars,
    STATE(4), 3,
      sym__section,
      sym_headline,
      aux_sym_org_file_repeat1,
  [31] = 3,
    ACTIONS(5), 1,
      sym_stars,
    ACTIONS(32), 1,
      ts_builtin_sym_end,
    STATE(4), 3,
      sym__section,
      sym_headline,
      aux_sym_org_file_repeat1,
  [43] = 5,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(34), 1,
      sym_line_ending,
    ACTIONS(36), 1,
      sym_comment,
    ACTIONS(38), 1,
      sym_title,
    STATE(63), 1,
      sym_tags,
  [59] = 5,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(40), 1,
      sym_line_ending,
    ACTIONS(42), 1,
      sym_comment,
    ACTIONS(44), 1,
      sym_title,
    STATE(66), 1,
      sym_tags,
  [75] = 1,
    ACTIONS(46), 5,
      sym_line_ending,
      sym_priority,
      sym_comment,
      anon_sym_COLON,
      sym_title,
  [83] = 4,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(48), 1,
      sym_line_ending,
    ACTIONS(50), 1,
      sym_title,
    STATE(59), 1,
      sym_tags,
  [96] = 4,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(52), 1,
      sym_line_ending,
    ACTIONS(54), 1,
      sym_title,
    STATE(61), 1,
      sym_tags,
  [109] = 4,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(56), 1,
      sym_line_ending,
    ACTIONS(58), 1,
      sym_title,
    STATE(69), 1,
      sym_tags,
  [122] = 4,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(60), 1,
      sym_line_ending,
    ACTIONS(62), 1,
      sym_title,
    STATE(60), 1,
      sym_tags,
  [135] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(64), 1,
      sym_line_ending,
    STATE(65), 1,
      sym_tags,
  [145] = 3,
    ACTIONS(66), 1,
      sym_line_ending,
    ACTIONS(68), 1,
      sym_tag,
    STATE(14), 1,
      aux_sym_tags_repeat1,
  [155] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(71), 1,
      sym_line_ending,
    STATE(70), 1,
      sym_tags,
  [165] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(73), 1,
      sym_line_ending,
    STATE(68), 1,
      sym_tags,
  [175] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(75), 1,
      sym_line_ending,
    STATE(73), 1,
      sym_tags,
  [185] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(77), 1,
      sym_line_ending,
    STATE(57), 1,
      sym_tags,
  [195] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(79), 1,
      sym_line_ending,
    STATE(67), 1,
      sym_tags,
  [205] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(81), 1,
      sym_line_ending,
    STATE(62), 1,
      sym_tags,
  [215] = 3,
    ACTIONS(15), 1,
      anon_sym_COLON,
    ACTIONS(83), 1,
      sym_line_ending,
    STATE(58), 1,
      sym_tags,
  [225] = 3,
    ACTIONS(85), 1,
      sym_line_ending,
    ACTIONS(87), 1,
      sym_tag,
    STATE(14), 1,
      aux_sym_tags_repeat1,
  [235] = 1,
    ACTIONS(89), 2,
      ts_builtin_sym_end,
      sym_stars,
  [240] = 2,
    ACTIONS(91), 1,
      sym_tag,
    STATE(22), 1,
      aux_sym_tags_repeat1,
  [247] = 1,
    ACTIONS(93), 2,
      ts_builtin_sym_end,
      sym_stars,
  [252] = 1,
    ACTIONS(95), 2,
      ts_builtin_sym_end,
      sym_stars,
  [257] = 1,
    ACTIONS(97), 2,
      ts_builtin_sym_end,
      sym_stars,
  [262] = 1,
    ACTIONS(99), 2,
      ts_builtin_sym_end,
      sym_stars,
  [267] = 1,
    ACTIONS(101), 2,
      ts_builtin_sym_end,
      sym_stars,
  [272] = 1,
    ACTIONS(103), 2,
      ts_builtin_sym_end,
      sym_stars,
  [277] = 1,
    ACTIONS(105), 2,
      ts_builtin_sym_end,
      sym_stars,
  [282] = 1,
    ACTIONS(107), 2,
      ts_builtin_sym_end,
      sym_stars,
  [287] = 1,
    ACTIONS(109), 2,
      ts_builtin_sym_end,
      sym_stars,
  [292] = 1,
    ACTIONS(111), 2,
      ts_builtin_sym_end,
      sym_stars,
  [297] = 1,
    ACTIONS(113), 2,
      ts_builtin_sym_end,
      sym_stars,
  [302] = 1,
    ACTIONS(115), 2,
      ts_builtin_sym_end,
      sym_stars,
  [307] = 1,
    ACTIONS(117), 2,
      ts_builtin_sym_end,
      sym_stars,
  [312] = 1,
    ACTIONS(119), 2,
      ts_builtin_sym_end,
      sym_stars,
  [317] = 1,
    ACTIONS(121), 2,
      ts_builtin_sym_end,
      sym_stars,
  [322] = 2,
    ACTIONS(66), 1,
      sym_line_ending,
    ACTIONS(123), 1,
      sym_tag,
  [329] = 1,
    ACTIONS(125), 2,
      ts_builtin_sym_end,
      sym_stars,
  [334] = 1,
    ACTIONS(127), 2,
      ts_builtin_sym_end,
      sym_stars,
  [339] = 1,
    ACTIONS(129), 2,
      ts_builtin_sym_end,
      sym_stars,
  [344] = 1,
    ACTIONS(131), 2,
      ts_builtin_sym_end,
      sym_stars,
  [349] = 1,
    ACTIONS(133), 2,
      ts_builtin_sym_end,
      sym_stars,
  [354] = 1,
    ACTIONS(135), 2,
      ts_builtin_sym_end,
      sym_stars,
  [359] = 1,
    ACTIONS(137), 2,
      ts_builtin_sym_end,
      sym_stars,
  [364] = 1,
    ACTIONS(139), 2,
      ts_builtin_sym_end,
      sym_stars,
  [369] = 1,
    ACTIONS(141), 2,
      ts_builtin_sym_end,
      sym_stars,
  [374] = 1,
    ACTIONS(143), 2,
      ts_builtin_sym_end,
      sym_stars,
  [379] = 1,
    ACTIONS(145), 2,
      ts_builtin_sym_end,
      sym_stars,
  [384] = 1,
    ACTIONS(147), 2,
      ts_builtin_sym_end,
      sym_stars,
  [389] = 1,
    ACTIONS(149), 2,
      ts_builtin_sym_end,
      sym_stars,
  [394] = 1,
    ACTIONS(151), 2,
      ts_builtin_sym_end,
      sym_stars,
  [399] = 1,
    ACTIONS(153), 2,
      ts_builtin_sym_end,
      sym_stars,
  [404] = 1,
    ACTIONS(155), 2,
      ts_builtin_sym_end,
      sym_stars,
  [409] = 1,
    ACTIONS(157), 1,
      sym_line_ending,
  [413] = 1,
    ACTIONS(159), 1,
      sym_line_ending,
  [417] = 1,
    ACTIONS(161), 1,
      sym_line_ending,
  [421] = 1,
    ACTIONS(163), 1,
      sym_line_ending,
  [425] = 1,
    ACTIONS(165), 1,
      sym_line_ending,
  [429] = 1,
    ACTIONS(167), 1,
      sym_line_ending,
  [433] = 1,
    ACTIONS(169), 1,
      sym_line_ending,
  [437] = 1,
    ACTIONS(171), 1,
      sym_line_ending,
  [441] = 1,
    ACTIONS(173), 1,
      sym_line_ending,
  [445] = 1,
    ACTIONS(175), 1,
      sym_line_ending,
  [449] = 1,
    ACTIONS(177), 1,
      sym_line_ending,
  [453] = 1,
    ACTIONS(179), 1,
      sym_line_ending,
  [457] = 1,
    ACTIONS(181), 1,
      sym_line_ending,
  [461] = 1,
    ACTIONS(183), 1,
      sym_line_ending,
  [465] = 1,
    ACTIONS(185), 1,
      ts_builtin_sym_end,
  [469] = 1,
    ACTIONS(187), 1,
      sym_line_ending,
  [473] = 1,
    ACTIONS(189), 1,
      sym_line_ending,
  [477] = 1,
    ACTIONS(191), 1,
      anon_sym_COLON,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(3)] = 0,
  [SMALL_STATE(4)] = 19,
  [SMALL_STATE(5)] = 31,
  [SMALL_STATE(6)] = 43,
  [SMALL_STATE(7)] = 59,
  [SMALL_STATE(8)] = 75,
  [SMALL_STATE(9)] = 83,
  [SMALL_STATE(10)] = 96,
  [SMALL_STATE(11)] = 109,
  [SMALL_STATE(12)] = 122,
  [SMALL_STATE(13)] = 135,
  [SMALL_STATE(14)] = 145,
  [SMALL_STATE(15)] = 155,
  [SMALL_STATE(16)] = 165,
  [SMALL_STATE(17)] = 175,
  [SMALL_STATE(18)] = 185,
  [SMALL_STATE(19)] = 195,
  [SMALL_STATE(20)] = 205,
  [SMALL_STATE(21)] = 215,
  [SMALL_STATE(22)] = 225,
  [SMALL_STATE(23)] = 235,
  [SMALL_STATE(24)] = 240,
  [SMALL_STATE(25)] = 247,
  [SMALL_STATE(26)] = 252,
  [SMALL_STATE(27)] = 257,
  [SMALL_STATE(28)] = 262,
  [SMALL_STATE(29)] = 267,
  [SMALL_STATE(30)] = 272,
  [SMALL_STATE(31)] = 277,
  [SMALL_STATE(32)] = 282,
  [SMALL_STATE(33)] = 287,
  [SMALL_STATE(34)] = 292,
  [SMALL_STATE(35)] = 297,
  [SMALL_STATE(36)] = 302,
  [SMALL_STATE(37)] = 307,
  [SMALL_STATE(38)] = 312,
  [SMALL_STATE(39)] = 317,
  [SMALL_STATE(40)] = 322,
  [SMALL_STATE(41)] = 329,
  [SMALL_STATE(42)] = 334,
  [SMALL_STATE(43)] = 339,
  [SMALL_STATE(44)] = 344,
  [SMALL_STATE(45)] = 349,
  [SMALL_STATE(46)] = 354,
  [SMALL_STATE(47)] = 359,
  [SMALL_STATE(48)] = 364,
  [SMALL_STATE(49)] = 369,
  [SMALL_STATE(50)] = 374,
  [SMALL_STATE(51)] = 379,
  [SMALL_STATE(52)] = 384,
  [SMALL_STATE(53)] = 389,
  [SMALL_STATE(54)] = 394,
  [SMALL_STATE(55)] = 399,
  [SMALL_STATE(56)] = 404,
  [SMALL_STATE(57)] = 409,
  [SMALL_STATE(58)] = 413,
  [SMALL_STATE(59)] = 417,
  [SMALL_STATE(60)] = 421,
  [SMALL_STATE(61)] = 425,
  [SMALL_STATE(62)] = 429,
  [SMALL_STATE(63)] = 433,
  [SMALL_STATE(64)] = 437,
  [SMALL_STATE(65)] = 441,
  [SMALL_STATE(66)] = 445,
  [SMALL_STATE(67)] = 449,
  [SMALL_STATE(68)] = 453,
  [SMALL_STATE(69)] = 457,
  [SMALL_STATE(70)] = 461,
  [SMALL_STATE(71)] = 465,
  [SMALL_STATE(72)] = 469,
  [SMALL_STATE(73)] = 473,
  [SMALL_STATE(74)] = 477,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_org_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_org_file_repeat1, 2),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_org_file_repeat1, 2), SHIFT_REPEAT(2),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_org_file, 1),
  [34] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [38] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [40] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [44] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_todo, 1),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [50] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [52] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tags_repeat1, 2),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_tags_repeat1, 2), SHIFT_REPEAT(74),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tags, 2),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 10),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 7, .production_id = 32),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 4),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 31),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 5),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 30),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 6),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 7),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 29),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 28),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 8),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 27),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 9),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 3),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 26),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 11),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_tags_repeat1, 2),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 25),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 12),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 13),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 2),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 24),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 23),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 14),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 22),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 2, .production_id = 1),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 15),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 21),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 16),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 17),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 20),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 18),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 19),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [185] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
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
