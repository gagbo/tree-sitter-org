#include "tree_sitter/parser.h"
#include <memory>

static const char* ORG_TODO_KEYWORDS_1[] = {"TODO", "DONE"};

enum TokenType {
  ORG_HEADLINE,
};


class Scanner {
    public:
        /// Serialize the scanner to bytes
        /// Return the count of bytes written
        unsigned int serialize(char* buffer) const;
        friend std::unique_ptr<Scanner> deserialize(const char* buffer, unsigned int length);
        /// Scan the stream to find the correct token type
        bool scan(TSLexer* lexer, const bool*valid_symbols);
};

extern "C" {
void *tree_sitter_org_external_scanner_create();
void tree_sitter_org_external_scanner_destroy(void *payload);
unsigned tree_sitter_org_external_scanner_serialize(void *payload,
                                                    char *buffer);
void tree_sitter_org_external_scanner_deserialize(void *payload,
                                                  const char *buffer,
                                                  unsigned length);
bool tree_sitter_org_external_scanner_scan(void *payload, TSLexer *lexer,
                                           const bool *valid_symbols);
}

unsigned int Scanner::serialize(char *buffer) const {
  return 0;
}

bool Scanner::scan(TSLexer *lexer, const bool *valid_symbols) {
  return false;
}

/// Deserialize a buffer and modifies the current scanner to fit this
std::unique_ptr<Scanner> deserialize(const char* buffer, unsigned int length) {
    return std::make_unique<Scanner>();
}


void *tree_sitter_org_external_scanner_create() { return nullptr; }

void tree_sitter_org_external_scanner_destroy(void *payload) {
  auto scanner = reinterpret_cast<Scanner*>(payload);
  delete scanner;
}

unsigned tree_sitter_org_external_scanner_serialize(void *payload,
                                                    char *buffer) {
  auto scanner = reinterpret_cast<Scanner*>(payload);
  auto size = scanner->serialize(buffer);
  return size;
}

void tree_sitter_org_external_scanner_deserialize(void *payload,
                                                  const char *buffer,
                                                  unsigned length) {
  auto scanner = deserialize(buffer, length);
}

bool tree_sitter_org_external_scanner_scan(void *payload, TSLexer *lexer,
                                           const bool *valid_symbols) {
  auto scanner = reinterpret_cast<Scanner*>(payload);
  return scanner->scan(lexer, valid_symbols);
}
