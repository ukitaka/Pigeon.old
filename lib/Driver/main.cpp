#include <iostream>
#include <string>
#include "llvm/ADT/StringSwitch.h"
#include "pigeon/Parse/Lexer.hpp"
#include "pigeon/Parse/Token.hpp"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/SMLoc.h"

using namespace std;

int main() {
    llvm::SourceMgr SourceMgr;
    const char *source = "1+2\n";
    unique_ptr<llvm::MemoryBuffer> buf = llvm::MemoryBuffer::getMemBuffer(source);
    unsigned mainBufferID = SourceMgr.AddNewSourceBuffer(std::move(buf), llvm::SMLoc());
    auto lexer = new pigeon::Lexer(mainBufferID, SourceMgr);

    pigeon::Token token;
    lexer->Lex(token);

    return 0;
}
