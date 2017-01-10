#include <iostream>
#include <stdlib.h>
#include <string>
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/MemoryBuffer.h"
#include "pigeon/Parse/lexer.hpp"

pigeon::Lexer::Lexer(unsigned BufferID, llvm::SourceMgr &SM) : SourceMgr(SM) {
  Buffer = SM.getMemoryBuffer(BufferID);
  CurPtr = Buffer->getBufferStart();
}


void pigeon::Lexer::Warning(const char* Loc, const char* Message) {
    SourceMgr.PrintMessage(llvm::SMLoc::getFromPointer(Loc), llvm::SourceMgr::DK_Warning, Message);
}

void pigeon::Lexer::Error(const char* Loc, const char* Message) {
    SourceMgr.PrintMessage(llvm::SMLoc::getFromPointer(Loc), llvm::SourceMgr::DK_Error, Message);
}

void pigeon::Lexer::FormToken(pigeon::tok token, const char *TokStart, pigeon::Token& Result) {
    Result.setToken(token, llvm::StringRef(TokStart, CurPtr-TokStart));
}


void pigeon::Lexer::LexDigit(Token &Result) {
    const char *TokStart = CurPtr-1;

    while (isdigit(*CurPtr))
        CurPtr++;

    return FormToken(pigeon::tok::numeric_constant, TokStart, Result);
}

void pigeon::Lexer::Lex(Token &Result) {
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
            if (CurPtr-1 != Buffer->getBufferEnd()) {
                Warning(CurPtr-1, "null character embedded in middle of file");
                goto Restart;
            }
            return FormToken(pigeon::tok::eof, TokStart, Result);
        case '+':
            return FormToken(pigeon::tok::plus, TokStart, Result);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            return LexDigit(Result);
    }
    goto Restart;
}
