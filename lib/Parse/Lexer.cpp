#include "pigeon/Parse/lexer.hpp"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/SourceMgr.h"
#include <iostream>
#include <stdlib.h>
#include <string>

pigeon::Lexer::Lexer(unsigned BufferID, llvm::SourceMgr &SM) : SourceMgr(SM) {
  Buffer = SM.getMemoryBuffer(BufferID);
  CurPtr = Buffer->getBufferStart();
}

void pigeon::Lexer::warning(const char *Loc, const char *Message) {
  SourceMgr.PrintMessage(llvm::SMLoc::getFromPointer(Loc),
                         llvm::SourceMgr::DK_Warning, Message);
}

void pigeon::Lexer::error(const char *Loc, const char *Message) {
  SourceMgr.PrintMessage(llvm::SMLoc::getFromPointer(Loc),
                         llvm::SourceMgr::DK_Error, Message);
}

void pigeon::Lexer::formToken(pigeon::tok token, const char *TokStart,
                              pigeon::Token &Result) {
  Result.setToken(token, llvm::StringRef(TokStart, CurPtr - TokStart));
}

void pigeon::Lexer::lexDigit(Token &Result) {
  const char *TokStart = CurPtr - 1;

  while (isdigit(*CurPtr))
    CurPtr++;

  return formToken(pigeon::tok::integer_literal, TokStart, Result);
}

void pigeon::Lexer::lex(Token &Result) {
  assert(CurPtr >= Buffer->getBufferStart() &&
         CurPtr <= Buffer->getBufferEnd() && "Cur Char Pointer out of range!");
Restart:
  const char *TokStart = CurPtr;

  switch (*CurPtr++) {
  default:
    goto Restart;
  case ' ':
  case '\t':
  case '\n':
  case '\r':
    goto Restart;

  case 0:
    if (CurPtr - 1 != Buffer->getBufferEnd()) {
      warning(CurPtr - 1, "null character embedded in middle of file");
      goto Restart;
    }
    return formToken(pigeon::tok::eof, TokStart, Result);
  case '+':
    return formToken(pigeon::tok::oper_binary, TokStart, Result);
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    return lexDigit(Result);
  }
  goto Restart;
}
