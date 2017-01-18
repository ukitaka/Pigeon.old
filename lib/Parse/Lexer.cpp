#include "pigeon/Parse/Lexer.hpp"
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
  case '(':
    return formToken(tok::l_paren, TokStart);
  case '{':
    return formToken(tok::l_brace, TokStart);
  case '[':
    return formToken(tok::l_square, TokStart);
  case ')':
    return formToken(tok::r_paren, TokStart);
  case '}':
    return formToken(tok::r_brace, TokStart);
  case ']':
    return formToken(tok::r_square, TokStart);
  case '.':
    return formToken(tok::period, TokStart);
  case ',':
    return formToken(tok::comma, TokStart);
  case ':':
    return formToken(tok::colon, TokStart);
  case ';':
    return formToken(tok::semi, TokStart);
  case '=':
    return formToken(tok::equal, TokStart);
  case '@':
    return formToken(tok::at_sign, TokStart);
  case '#':
    return formToken(tok::pound, TokStart);
  case '-':
    if (*CurPtr == '>') {
      CurPtr++;
      return formToken(tok::arrow, TokStart);
    }
    return formToken(tok::oper_binary, TokStart);

  case '/':
    if (*CurPtr == '/') {
      skipSlashSlashComment();
      return formToken(tok::comment, TokStart);
    }
    return formToken(tok::oper_binary, TokStart);

  case '+':
  case '*':
    return formToken(tok::oper_binary, TokStart);

  case 'A':
  case 'B':
  case 'C':
  case 'D':
  case 'E':
  case 'F':
  case 'G':
  case 'H':
  case 'I':
  case 'J':
  case 'K':
  case 'L':
  case 'M':
  case 'N':
  case 'O':
  case 'P':
  case 'Q':
  case 'R':
  case 'S':
  case 'T':
  case 'U':
  case 'V':
  case 'W':
  case 'X':
  case 'Y':
  case 'Z':
  case 'a':
  case 'b':
  case 'c':
  case 'd':
  case 'e':
  case 'f':
  case 'g':
  case 'h':
  case 'i':
  case 'j':
  case 'k':
  case 'l':
  case 'm':
  case 'n':
  case 'o':
  case 'p':
  case 'q':
  case 'r':
  case 's':
  case 't':
  case 'u':
  case 'v':
  case 'w':
  case 'x':
  case 'y':
  case 'z':
  case '_':
    return lexIdentifier();
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
    return lexNumber();
  }
  goto Restart;
}

void Lexer::lexIdentifier() {
  const char *TokStart = CurPtr - 1;

  while (isalpha(*CurPtr) || *CurPtr == '_')
    CurPtr++;

  auto Kind = kindOfIdentifier(llvm::StringRef(TokStart, (CurPtr - TokStart)));

  return formToken(Kind, TokStart);
}

tok Lexer::kindOfIdentifier(llvm::StringRef Str) {
  tok Kind = llvm::StringSwitch<tok>(Str)
                 .Case("func", tok::kw_func)
                 .Case("var", tok::kw_var)
                 .Default(tok::identifier);

  return Kind;
}

void Lexer::skipToEndOfLine() {
  while (*CurPtr != '\n')
    CurPtr++;
}

void Lexer::skipSlashSlashComment() { skipToEndOfLine(); }
