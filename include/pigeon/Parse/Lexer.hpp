#ifndef PIGEON_PARSE_LEXER_H
#define PIGEON_PARSE_LEXER_H

#include "pigeon/Basic/SourceLoc.hpp"
#include "pigeon/Parse/Token.hpp"
#include <iostream>
#include <stdlib.h>

namespace llvm {
class MemoryBuffer;
class SourceMgr;
}

namespace pigeon {

class Lexer {
  llvm::SourceMgr &SourceMgr;
  const llvm::MemoryBuffer *Buffer;
  const char *CurPtr;

  Lexer(const Lexer &);
  void operator=(const Lexer &);

public:
  Lexer(unsigned BufferID, llvm::SourceMgr &SM);
  void lex(Token &Result);

private:
  void warning(const char *Loc, const char *Message);
  void error(const char *Loc, const char *Message);
  void formToken(tok token, const char *TokStart, Token &Result);

  void lexDigit(Token &Result);
};
}

#endif /* PIGEON_PARSE_LEXER_H */
