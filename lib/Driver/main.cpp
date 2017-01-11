#include "pigeon/Parse/Lexer.hpp"
#include "pigeon/Parse/Token.hpp"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/Support/SMLoc.h"
#include "llvm/Support/SourceMgr.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  llvm::SourceMgr SourceMgr;
  const char *source = "1+2\n";
  unique_ptr<llvm::MemoryBuffer> buf = llvm::MemoryBuffer::getMemBuffer(source);
  unsigned mainBufferID =
      SourceMgr.AddNewSourceBuffer(std::move(buf), llvm::SMLoc());
  pigeon::Lexer lexer(mainBufferID, SourceMgr);

  pigeon::Token token;

  while (!token.isEOF()) {
    lexer.lex(token);
    std::cout << std::string(token.getText()) << std::endl;
  }

  return 0;
}
