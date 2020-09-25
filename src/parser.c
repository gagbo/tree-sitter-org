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
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 7

enum {
  sym_line_ending = 1,
  sym_stars = 2,
  sym_title = 3,
  sym_priority = 4,
  sym_todo = 5,
  sym_comment = 6,
  sym_tag = 7,
  aux_sym_tags_token1 = 8,
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
  [sym_title] = "title",
  [sym_priority] = "priority",
  [sym_todo] = "todo",
  [sym_comment] = "comment",
  [sym_tag] = "tag",
  [aux_sym_tags_token1] = "tags_token1",
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
  [sym_title] = sym_title,
  [sym_priority] = sym_priority,
  [sym_todo] = sym_todo,
  [sym_comment] = sym_comment,
  [sym_tag] = sym_tag,
  [aux_sym_tags_token1] = aux_sym_tags_token1,
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
  [sym_title] = {
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
  [aux_sym_tags_token1] = {
    .visible = false,
    .named = false,
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
  field_level = 2,
  field_prio = 3,
  field_tags = 4,
  field_title = 5,
  field_todo = 6,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_comment] = "comment",
  [field_level] = "level",
  [field_prio] = "prio",
  [field_tags] = "tags",
  [field_title] = "title",
  [field_todo] = "todo",
};

static const TSFieldMapSlice ts_field_map_slices[33] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
  [4] = {.index = 5, .length = 2},
  [5] = {.index = 7, .length = 2},
  [6] = {.index = 9, .length = 2},
  [7] = {.index = 11, .length = 3},
  [8] = {.index = 14, .length = 3},
  [9] = {.index = 17, .length = 3},
  [10] = {.index = 20, .length = 3},
  [11] = {.index = 23, .length = 3},
  [12] = {.index = 26, .length = 3},
  [13] = {.index = 29, .length = 3},
  [14] = {.index = 32, .length = 3},
  [15] = {.index = 35, .length = 3},
  [16] = {.index = 38, .length = 3},
  [17] = {.index = 41, .length = 4},
  [18] = {.index = 45, .length = 4},
  [19] = {.index = 49, .length = 4},
  [20] = {.index = 53, .length = 4},
  [21] = {.index = 57, .length = 4},
  [22] = {.index = 61, .length = 4},
  [23] = {.index = 65, .length = 4},
  [24] = {.index = 69, .length = 4},
  [25] = {.index = 73, .length = 4},
  [26] = {.index = 77, .length = 4},
  [27] = {.index = 81, .length = 5},
  [28] = {.index = 86, .length = 5},
  [29] = {.index = 91, .length = 5},
  [30] = {.index = 96, .length = 5},
  [31] = {.index = 101, .length = 5},
  [32] = {.index = 106, .length = 6},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_level, 0},
  [1] =
    {field_level, 0},
    {field_title, 1},
  [3] =
    {field_level, 0},
    {field_prio, 1},
  [5] =
    {field_level, 0},
    {field_todo, 1},
  [7] =
    {field_comment, 1},
    {field_level, 0},
  [9] =
    {field_level, 0},
    {field_tags, 1},
  [11] =
    {field_level, 0},
    {field_tags, 2},
    {field_title, 1},
  [14] =
    {field_level, 0},
    {field_prio, 1},
    {field_title, 2},
  [17] =
    {field_comment, 2},
    {field_level, 0},
    {field_prio, 1},
  [20] =
    {field_level, 0},
    {field_prio, 1},
    {field_tags, 2},
  [23] =
    {field_level, 0},
    {field_title, 2},
    {field_todo, 1},
  [26] =
    {field_level, 0},
    {field_prio, 2},
    {field_todo, 1},
  [29] =
    {field_comment, 2},
    {field_level, 0},
    {field_todo, 1},
  [32] =
    {field_level, 0},
    {field_tags, 2},
    {field_todo, 1},
  [35] =
    {field_comment, 1},
    {field_level, 0},
    {field_title, 2},
  [38] =
    {field_comment, 1},
    {field_level, 0},
    {field_tags, 2},
  [41] =
    {field_level, 0},
    {field_prio, 1},
    {field_tags, 3},
    {field_title, 2},
  [45] =
    {field_comment, 2},
    {field_level, 0},
    {field_prio, 1},
    {field_title, 3},
  [49] =
    {field_comment, 2},
    {field_level, 0},
    {field_prio, 1},
    {field_tags, 3},
  [53] =
    {field_level, 0},
    {field_tags, 3},
    {field_title, 2},
    {field_todo, 1},
  [57] =
    {field_level, 0},
    {field_prio, 2},
    {field_title, 3},
    {field_todo, 1},
  [61] =
    {field_comment, 3},
    {field_level, 0},
    {field_prio, 2},
    {field_todo, 1},
  [65] =
    {field_level, 0},
    {field_prio, 2},
    {field_tags, 3},
    {field_todo, 1},
  [69] =
    {field_comment, 2},
    {field_level, 0},
    {field_title, 3},
    {field_todo, 1},
  [73] =
    {field_comment, 2},
    {field_level, 0},
    {field_tags, 3},
    {field_todo, 1},
  [77] =
    {field_comment, 1},
    {field_level, 0},
    {field_tags, 3},
    {field_title, 2},
  [81] =
    {field_comment, 2},
    {field_level, 0},
    {field_prio, 1},
    {field_tags, 4},
    {field_title, 3},
  [86] =
    {field_level, 0},
    {field_prio, 2},
    {field_tags, 4},
    {field_title, 3},
    {field_todo, 1},
  [91] =
    {field_comment, 3},
    {field_level, 0},
    {field_prio, 2},
    {field_title, 4},
    {field_todo, 1},
  [96] =
    {field_comment, 3},
    {field_level, 0},
    {field_prio, 2},
    {field_tags, 4},
    {field_todo, 1},
  [101] =
    {field_comment, 2},
    {field_level, 0},
    {field_tags, 4},
    {field_title, 3},
    {field_todo, 1},
  [106] =
    {field_comment, 3},
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
      if (eof) ADVANCE(35);
      if (lookahead == '*') ADVANCE(38);
      if (lookahead == ':') ADVANCE(75);
      if (lookahead == 'C') ADVANCE(4);
      if (lookahead == 'D') ADVANCE(27);
      if (lookahead == 'N') ADVANCE(9);
      if (lookahead == 'T') ADVANCE(25);
      if (lookahead == 'W') ADVANCE(5);
      if (lookahead == '[') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == ':') ADVANCE(70);
      if (lookahead == 'C') ADVANCE(41);
      if (lookahead == 'D') ADVANCE(64);
      if (lookahead == 'N') ADVANCE(47);
      if (lookahead == 'T') ADVANCE(63);
      if (lookahead == 'W') ADVANCE(42);
      if (lookahead == '[') ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(39);
      if (lookahead != 0) ADVANCE(70);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(37);
      if (lookahead == '\r') ADVANCE(2);
      if (lookahead == ':') ADVANCE(75);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(2)
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(34);
      END_STATE();
    case 4:
      if (lookahead == 'A') ADVANCE(21);
      if (lookahead == 'O') ADVANCE(19);
      END_STATE();
    case 5:
      if (lookahead == 'A') ADVANCE(15);
      END_STATE();
    case 6:
      if (lookahead == 'C') ADVANCE(11);
      END_STATE();
    case 7:
      if (lookahead == 'D') ADVANCE(72);
      END_STATE();
    case 8:
      if (lookahead == 'D') ADVANCE(26);
      END_STATE();
    case 9:
      if (lookahead == 'E') ADVANCE(31);
      END_STATE();
    case 10:
      if (lookahead == 'E') ADVANCE(72);
      END_STATE();
    case 11:
      if (lookahead == 'E') ADVANCE(17);
      END_STATE();
    case 12:
      if (lookahead == 'E') ADVANCE(7);
      END_STATE();
    case 13:
      if (lookahead == 'E') ADVANCE(24);
      END_STATE();
    case 14:
      if (lookahead == 'G') ADVANCE(72);
      END_STATE();
    case 15:
      if (lookahead == 'I') ADVANCE(30);
      END_STATE();
    case 16:
      if (lookahead == 'I') ADVANCE(22);
      END_STATE();
    case 17:
      if (lookahead == 'L') ADVANCE(18);
      END_STATE();
    case 18:
      if (lookahead == 'L') ADVANCE(12);
      END_STATE();
    case 19:
      if (lookahead == 'M') ADVANCE(20);
      END_STATE();
    case 20:
      if (lookahead == 'M') ADVANCE(13);
      END_STATE();
    case 21:
      if (lookahead == 'N') ADVANCE(6);
      END_STATE();
    case 22:
      if (lookahead == 'N') ADVANCE(14);
      END_STATE();
    case 23:
      if (lookahead == 'N') ADVANCE(10);
      END_STATE();
    case 24:
      if (lookahead == 'N') ADVANCE(29);
      END_STATE();
    case 25:
      if (lookahead == 'O') ADVANCE(8);
      END_STATE();
    case 26:
      if (lookahead == 'O') ADVANCE(72);
      END_STATE();
    case 27:
      if (lookahead == 'O') ADVANCE(23);
      END_STATE();
    case 28:
      if (lookahead == 'T') ADVANCE(72);
      END_STATE();
    case 29:
      if (lookahead == 'T') ADVANCE(73);
      END_STATE();
    case 30:
      if (lookahead == 'T') ADVANCE(16);
      END_STATE();
    case 31:
      if (lookahead == 'X') ADVANCE(28);
      END_STATE();
    case 32:
      if (lookahead == ']') ADVANCE(71);
      END_STATE();
    case 33:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(33)
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 34:
      if (('A' <= lookahead && lookahead <= 'C') ||
          ('a' <= lookahead && lookahead <= 'c')) ADVANCE(32);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_line_ending);
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(39);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_line_ending);
      if (lookahead == '\n') ADVANCE(37);
      if (lookahead == '\r') ADVANCE(2);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == ':') ADVANCE(70);
      if (lookahead == 'C') ADVANCE(41);
      if (lookahead == 'D') ADVANCE(64);
      if (lookahead == 'N') ADVANCE(47);
      if (lookahead == 'T') ADVANCE(63);
      if (lookahead == 'W') ADVANCE(42);
      if (lookahead == '[') ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(39);
      if (lookahead != 0) ADVANCE(70);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == '#') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'A') ADVANCE(58);
      if (lookahead == 'O') ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'A') ADVANCE(52);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'C') ADVANCE(48);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'D') ADVANCE(70);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'D') ADVANCE(62);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(70);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(67);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(44);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'E') ADVANCE(59);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'G') ADVANCE(70);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'I') ADVANCE(66);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'I') ADVANCE(60);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'L') ADVANCE(55);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'L') ADVANCE(49);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'M') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'M') ADVANCE(50);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'N') ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'N') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'N') ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'N') ADVANCE(46);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'O') ADVANCE(70);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'O') ADVANCE(45);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'O') ADVANCE(61);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'T') ADVANCE(70);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'T') ADVANCE(53);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == 'X') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_title);
      if (lookahead == ']') ADVANCE(70);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_title);
      if (('A' <= lookahead && lookahead <= 'C') ||
          ('a' <= lookahead && lookahead <= 'c')) ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_title);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(70);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_priority);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_todo);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == '#' ||
          lookahead == '%' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_tags_token1);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
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
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 2},
  [51] = {.lex_state = 33},
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
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 2},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 2},
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
    [aux_sym_tags_token1] = ACTIONS(1),
    [sym_org_headline] = ACTIONS(1),
  },
  [1] = {
    [sym_org_file] = STATE(68),
    [sym__section] = STATE(6),
    [sym_headline] = STATE(6),
    [aux_sym_org_file_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_stars] = ACTIONS(5),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(7), 1,
      sym_line_ending,
    ACTIONS(9), 1,
      sym_title,
    ACTIONS(11), 1,
      sym_priority,
    ACTIONS(13), 1,
      sym_todo,
    ACTIONS(15), 1,
      sym_comment,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    STATE(62), 1,
      sym_tags,
  [22] = 6,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(19), 1,
      sym_line_ending,
    ACTIONS(21), 1,
      sym_title,
    ACTIONS(23), 1,
      sym_priority,
    ACTIONS(25), 1,
      sym_comment,
    STATE(73), 1,
      sym_tags,
  [41] = 3,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(29), 1,
      sym_stars,
    STATE(4), 3,
      sym__section,
      sym_headline,
      aux_sym_org_file_repeat1,
  [53] = 5,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(32), 1,
      sym_line_ending,
    ACTIONS(34), 1,
      sym_title,
    ACTIONS(36), 1,
      sym_comment,
    STATE(63), 1,
      sym_tags,
  [69] = 3,
    ACTIONS(5), 1,
      sym_stars,
    ACTIONS(38), 1,
      ts_builtin_sym_end,
    STATE(4), 3,
      sym__section,
      sym_headline,
      aux_sym_org_file_repeat1,
  [81] = 5,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(40), 1,
      sym_line_ending,
    ACTIONS(42), 1,
      sym_title,
    ACTIONS(44), 1,
      sym_comment,
    STATE(60), 1,
      sym_tags,
  [97] = 4,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(46), 1,
      sym_line_ending,
    ACTIONS(48), 1,
      sym_title,
    STATE(67), 1,
      sym_tags,
  [110] = 4,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(50), 1,
      sym_line_ending,
    ACTIONS(52), 1,
      sym_title,
    STATE(72), 1,
      sym_tags,
  [123] = 4,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(54), 1,
      sym_line_ending,
    ACTIONS(56), 1,
      sym_title,
    STATE(59), 1,
      sym_tags,
  [136] = 4,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(58), 1,
      sym_line_ending,
    ACTIONS(60), 1,
      sym_title,
    STATE(61), 1,
      sym_tags,
  [149] = 3,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(62), 1,
      sym_line_ending,
    STATE(64), 1,
      sym_tags,
  [159] = 3,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(64), 1,
      sym_line_ending,
    STATE(58), 1,
      sym_tags,
  [169] = 3,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(66), 1,
      sym_line_ending,
    STATE(70), 1,
      sym_tags,
  [179] = 3,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(68), 1,
      sym_line_ending,
    STATE(56), 1,
      sym_tags,
  [189] = 3,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(70), 1,
      sym_line_ending,
    STATE(69), 1,
      sym_tags,
  [199] = 3,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(72), 1,
      sym_line_ending,
    STATE(65), 1,
      sym_tags,
  [209] = 3,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(74), 1,
      sym_line_ending,
    STATE(57), 1,
      sym_tags,
  [219] = 3,
    ACTIONS(76), 1,
      sym_line_ending,
    ACTIONS(78), 1,
      sym_tag,
    STATE(21), 1,
      aux_sym_tags_repeat1,
  [229] = 3,
    ACTIONS(17), 1,
      aux_sym_tags_token1,
    ACTIONS(80), 1,
      sym_line_ending,
    STATE(66), 1,
      sym_tags,
  [239] = 3,
    ACTIONS(82), 1,
      sym_line_ending,
    ACTIONS(84), 1,
      sym_tag,
    STATE(21), 1,
      aux_sym_tags_repeat1,
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
    ACTIONS(141), 2,
      ts_builtin_sym_end,
      sym_stars,
  [389] = 2,
    ACTIONS(82), 1,
      sym_line_ending,
    ACTIONS(143), 1,
      sym_tag,
  [396] = 2,
    ACTIONS(145), 1,
      sym_tag,
    STATE(19), 1,
      aux_sym_tags_repeat1,
  [403] = 1,
    ACTIONS(147), 2,
      ts_builtin_sym_end,
      sym_stars,
  [408] = 1,
    ACTIONS(149), 2,
      ts_builtin_sym_end,
      sym_stars,
  [413] = 1,
    ACTIONS(151), 2,
      ts_builtin_sym_end,
      sym_stars,
  [418] = 1,
    ACTIONS(153), 2,
      ts_builtin_sym_end,
      sym_stars,
  [423] = 1,
    ACTIONS(155), 1,
      sym_line_ending,
  [427] = 1,
    ACTIONS(157), 1,
      sym_line_ending,
  [431] = 1,
    ACTIONS(159), 1,
      sym_line_ending,
  [435] = 1,
    ACTIONS(161), 1,
      sym_line_ending,
  [439] = 1,
    ACTIONS(163), 1,
      sym_line_ending,
  [443] = 1,
    ACTIONS(165), 1,
      sym_line_ending,
  [447] = 1,
    ACTIONS(167), 1,
      sym_line_ending,
  [451] = 1,
    ACTIONS(169), 1,
      sym_line_ending,
  [455] = 1,
    ACTIONS(171), 1,
      sym_line_ending,
  [459] = 1,
    ACTIONS(173), 1,
      sym_line_ending,
  [463] = 1,
    ACTIONS(175), 1,
      sym_line_ending,
  [467] = 1,
    ACTIONS(177), 1,
      sym_line_ending,
  [471] = 1,
    ACTIONS(179), 1,
      ts_builtin_sym_end,
  [475] = 1,
    ACTIONS(181), 1,
      sym_line_ending,
  [479] = 1,
    ACTIONS(183), 1,
      sym_line_ending,
  [483] = 1,
    ACTIONS(185), 1,
      aux_sym_tags_token1,
  [487] = 1,
    ACTIONS(187), 1,
      sym_line_ending,
  [491] = 1,
    ACTIONS(189), 1,
      sym_line_ending,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 22,
  [SMALL_STATE(4)] = 41,
  [SMALL_STATE(5)] = 53,
  [SMALL_STATE(6)] = 69,
  [SMALL_STATE(7)] = 81,
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
  [SMALL_STATE(52)] = 403,
  [SMALL_STATE(53)] = 408,
  [SMALL_STATE(54)] = 413,
  [SMALL_STATE(55)] = 418,
  [SMALL_STATE(56)] = 423,
  [SMALL_STATE(57)] = 427,
  [SMALL_STATE(58)] = 431,
  [SMALL_STATE(59)] = 435,
  [SMALL_STATE(60)] = 439,
  [SMALL_STATE(61)] = 443,
  [SMALL_STATE(62)] = 447,
  [SMALL_STATE(63)] = 451,
  [SMALL_STATE(64)] = 455,
  [SMALL_STATE(65)] = 459,
  [SMALL_STATE(66)] = 463,
  [SMALL_STATE(67)] = 467,
  [SMALL_STATE(68)] = 471,
  [SMALL_STATE(69)] = 475,
  [SMALL_STATE(70)] = 479,
  [SMALL_STATE(71)] = 483,
  [SMALL_STATE(72)] = 487,
  [SMALL_STATE(73)] = 491,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_org_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_org_file_repeat1, 2),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_org_file_repeat1, 2), SHIFT_REPEAT(2),
  [32] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [34] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_org_file, 1),
  [40] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [44] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [46] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [50] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [52] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tags, 2),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tags_repeat1, 2),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_tags_repeat1, 2), SHIFT_REPEAT(71),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 11),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 2, .production_id = 1),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 4),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 7, .production_id = 32),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 5),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 31),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 30),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 6),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 7),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 8),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 29),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 9),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 28),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, .production_id = 27),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 10),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 3),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 26),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 12),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 25),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, .production_id = 2),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 24),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 13),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 23),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 22),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 14),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 15),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 21),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, .production_id = 16),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_tags_repeat1, 2),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 17),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 18),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 20),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, .production_id = 19),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [179] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
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
