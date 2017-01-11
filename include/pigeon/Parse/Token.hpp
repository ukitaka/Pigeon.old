//
//  Token.h
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/06.
//
//

#ifndef PIGEON_PARSE_TOKEN_H
#define PIGEON_PARSE_TOKEN_H

#include "llvm/ADT/StringRef.h"

namespace pigeon {

enum class tok {
  unknown = 0,
  eof,
  identifier,
  oper_binary,
  oper_postfix,
  oper_prefix,
  integer_literal,
  floating_literal,
  string_literal,
  comment,
  kw_var,
  NUM_TOKENS
};

class Token {
  tok Kind;
  llvm::StringRef Text;

public:
  Token() : Kind(tok::unknown) {}

  llvm::StringRef getText() const { return Text; }
  bool isEOF() const { return Kind == tok::eof; }

  void setToken(tok K, llvm::StringRef T) {
    Kind = K;
    Text = T;
  }
};
}

#endif /* PIGEON_PARSE_TOKEN_H */
