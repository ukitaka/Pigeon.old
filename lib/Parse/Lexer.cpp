#include <iostream>
#include <stdlib.h>
#include <string>
#include "llvm/ADT/StringSwitch.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/MemoryBuffer.h"
#include "pigeon/Parse/lexer.hpp"

pigeon::Lexer::Lexer(unsigned BufferID, llvm::SourceMgr &SM) : SourceMgr(SM) {
  Buffer = SM.getMemoryBuffer(BufferID);
  CurPtr = Buffer->getBufferStart();
}

void pigeon::Lexer::Lex(Token &Result) {
    assert(CurPtr >= Buffer->getBufferStart() &&
           CurPtr <= Buffer->getBufferEnd() && "Cur Char Pointer out of range!");
    std::cout << "OK" << std::endl;
}
