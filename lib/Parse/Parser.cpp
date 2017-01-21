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

ParseResult<Expr> Parser::ParseExpr() {
  return ParseError("Error", ParseErrorKind::InvalidToken);
}

ParseResult<Expr> Parser::ParseIntegerLiteral() {
  return ParseError("Error", ParseErrorKind::InvalidToken);
}
