//
//  Parser.hpp
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/17.
//
//

#ifndef PIGEON_PARSE_PARSER_H
#define PIGEON_PARSE_PARSER_H

#include "Lexer.hpp"
#include "pigeon/AST/Expr.hpp"
#include "pigeon/Parse/ParseResult.hpp"
#include <memory>

namespace llvm {
class SourceMgr;
}

namespace pigeon {
class Parser {
public:
  Parser(unsigned BufferID, llvm::SourceMgr &SourceMgr);
  ParseResult<Expr> ParseExpr();
  ParseResult<Expr> ParseIntegerLiteral();
  void ConsumeToken();
  void ConsumeToken(tok Kind);
  bool ConsumeTokenIf(tok Kind);

private:
  Token Token;
  std::unique_ptr<Lexer> L;
};
}

#endif /* PIGEON_PARSE_PARSER_H */
