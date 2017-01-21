#include "pigeon/Parse/Parser.hpp"
#include "pigeon/AST/Expr.hpp"
#include "pigeon/Parse/Lexer.hpp"
#include "pigeon/Parse/ParseError.hpp"
#include "pigeon/Parse/ParseResult.hpp"
#include "llvm/Support/SourceMgr.h"
#include <memory>

using namespace pigeon;

Parser::Parser(unsigned BufferID, llvm::SourceMgr &SourceMgr)
    : L(std::unique_ptr<Lexer>(new Lexer(BufferID, SourceMgr))) {}

void Parser::ConsumeToken() { L->lex(Token); }

void Parser::ConsumeToken(tok Kind) {
  assert(Token.is(Kind));
  ConsumeToken();
}

bool Parser::ConsumeTokenIf(tok Kind) {
  if (Token.isNot(Kind))
    return false;
  ConsumeToken();
  return true;
}

ParseResult<Expr> Parser::ParseExpr() {
  return ParseError("Error", ParseErrorKind::InvalidToken);
}

ParseResult<Expr> Parser::ParseIntegerLiteral() {
  if (Token.isNot(tok::integer_literal)) {
    return IntegerLiteral(Token.getText());
  }
  return ParseError("Error", ParseErrorKind::InvalidToken);
}
