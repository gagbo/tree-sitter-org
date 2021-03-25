#include <tree_sitter/parser.h>
#include <memory>

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

/// Deserialize a buffer and modifies the current scanner to fit this
std::unique_ptr<Scanner> deserialize(const char* buffer, unsigned int length) {
    return std::make_unique<Scanner>();
}

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


void *tree_sitter_org_external_scanner_create() { return nullptr; }

void tree_sitter_org_external_scanner_destroy(void *payload) {}

unsigned tree_sitter_org_external_scanner_serialize(void *payload,
                                                    char *buffer) {
  auto scan = deserialize(buffer,0);
  return 0;
}

void tree_sitter_org_external_scanner_deserialize(void *payload,
                                                  const char *buffer,
                                                  unsigned length) {
  auto scan = deserialize(buffer, length);
}

bool tree_sitter_org_external_scanner_scan(void *payload, TSLexer *lexer,
                                           const bool *valid_symbols) {
  return false;
}
