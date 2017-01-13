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
  kw_func,
  l_paren, // (
  r_paren, // )
  l_brace, // {
  r_brace, // }
  l_square, // [
  r_square, // ]
  period,        //.
  comma,         //,
  colon,         //:
  semi,          //;
  equal,         //=
  at_sign,       //@
  pound,         //#
  NUM_TOKENS
};

class Token {
  tok Kind;
  llvm::StringRef Text;

public:
  Token() : Kind(tok::NUM_TOKENS), Text("") {}

  llvm::StringRef getText() const { return Text; }
  tok getKind() const { return Kind; }
  bool isEOF() const { return Kind == tok::eof; }

  void setToken(tok K, llvm::StringRef T) {
    Kind = K;
    Text = T;
  }
};
}

#endif /* PIGEON_PARSE_TOKEN_H */
