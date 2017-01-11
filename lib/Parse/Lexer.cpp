#include "pigeon/Parse/lexer.hpp"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/SourceMgr.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace pigeon;

Lexer::Lexer(unsigned BufferID, llvm::SourceMgr &SM) : SourceMgr(SM) {
  Buffer = SM.getMemoryBuffer(BufferID);
  CurPtr = Buffer->getBufferStart();
  lexImpl();
}

void Lexer::warning(const char *Loc, const char *Message) {
  SourceMgr.PrintMessage(llvm::SMLoc::getFromPointer(Loc),
                         llvm::SourceMgr::DK_Warning, Message);
}

void Lexer::error(const char *Loc, const char *Message) {
  SourceMgr.PrintMessage(llvm::SMLoc::getFromPointer(Loc),
                         llvm::SourceMgr::DK_Error, Message);
}

void Lexer::formToken(tok token, const char *TokStart) {
  NextToken.setToken(token, llvm::StringRef(TokStart, CurPtr - TokStart));
}

void Lexer::lexNumber() {
  const char *TokStart = CurPtr - 1;

  while (isdigit(*CurPtr))
    CurPtr++;

  return formToken(tok::integer_literal, TokStart);
}

void Lexer::lexImpl() {
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
    return formToken(tok::eof, TokStart);
  case '+':
    return formToken(tok::oper_binary, TokStart);
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
    return lexNumber();
  }
  goto Restart;
}

tok Lexer::kindOfIdentifier(llvm::StringRef Str) {
    tok Kind = llvm::StringSwitch<tok>(Str)
    .Case("func", tok::kw_func)
    .Case("var", tok::kw_var)
    .Default(tok::identifier);

    return Kind;
}
