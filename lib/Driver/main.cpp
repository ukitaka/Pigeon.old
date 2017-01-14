#include "pigeon/Parse/Lexer.hpp"
#include "pigeon/Parse/Token.hpp"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/Support/SMLoc.h"
#include "llvm/Support/SourceMgr.h"
#include <iostream>
#include <string>

using namespace std;

void printToken(pigeon::Token Token);

int main() {
  llvm::SourceMgr SourceMgr;
  const char *source = "var abc = (1 + 2) * 3\n"
  "func piyo() -> Void {\n"
  "  var a = 123\n"
  "}";
  unique_ptr<llvm::MemoryBuffer> buf = llvm::MemoryBuffer::getMemBuffer(source);
  unsigned mainBufferID =
      SourceMgr.AddNewSourceBuffer(std::move(buf), llvm::SMLoc());
  pigeon::Lexer lexer(mainBufferID, SourceMgr);

  pigeon::Token token;

  while (!token.is(pigeon::tok::eof)) {
    lexer.lex(token);
    printToken(token);
  }

  return 0;
}

string kindString(pigeon::tok Kind) {
  switch (Kind) {
  case pigeon::tok::unknown:
    return "tok::unknown";
  case pigeon::tok::eof:
    return "tok::eof";
  case pigeon::tok::identifier:
    return "tok::identifier";
  case pigeon::tok::oper_binary:
    return "tok::oper_binary";
  case pigeon::tok::oper_postfix:
    return "tok::oper_postfix";
  case pigeon::tok::oper_prefix:
    return "tok::oper_prefix";
  case pigeon::tok::integer_literal:
    return "tok::integer_literal";
  case pigeon::tok::floating_literal:
    return "tok::integer_literal";
  case pigeon::tok::string_literal:
    return "tok::string_literal";
  case pigeon::tok::comment:
    return "tok::comment";
  case pigeon::tok::kw_var:
    return "tok::kw_var";
  case pigeon::tok::kw_func:
    return "tok::kw_func";
  case pigeon::tok::l_paren:
    return "tok::l_paren";
  case pigeon::tok::r_paren:
    return "tok::r_paren";
  case pigeon::tok::l_brace:
    return "tok::l_brace";
  case pigeon::tok::r_brace:
    return "tok::r_brace";
  case pigeon::tok::l_square:
    return "tok::l_square";
  case pigeon::tok::r_square:
    return "tok::r_square";
  case pigeon::tok::period:
    return "tok::period";
  case pigeon::tok::comma:
    return "tok::comma";
  case pigeon::tok::colon:
    return "tok::colon";
  case pigeon::tok::semi:
    return "tok::semi";
  case pigeon::tok::equal:
    return "tok::equal";
  case pigeon::tok::at_sign:
    return "tok::at_sign";
  case pigeon::tok::pound:
    return "tok::pound";
  case pigeon::tok::arrow:
    return "tok::arrow";
  case pigeon::tok::NUM_TOKENS:
    return "tok::NUM_TOKENS";
  }
}

void printToken(pigeon::Token Token) {
  cout << "(" << kindString(Token.getKind()) << " " << string(Token.getText())
       << ")" << endl;
}
