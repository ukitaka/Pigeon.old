#ifndef PIGEON_PARSE_LEXER_H
#define PIGEON_PARSE_LEXER_H

#include <iostream>
#include <stdlib.h>
#include "pigeon/Basic/SourceLoc.hpp"
#include "pigeon/Parse/Token.hpp"

namespace llvm {
    class MemoryBuffer;
    class SourceMgr;
}

namespace pigeon {

    class Lexer {
        llvm::SourceMgr &SourceMgr;
        const llvm::MemoryBuffer *Buffer;
        const char *CurPtr;

        Lexer(const Lexer&);
        void operator=(const Lexer&);
        
    public:
        Lexer(unsigned BufferID, llvm::SourceMgr &SM);
        void Lex(Token &Result);

    private:
        void Warning(const char* Loc, const char* Message);
        void Error(const char* Loc, const char* Message);
        void FormToken(tok token, const char *TokStart, Token& Result);

        void LexDigit(Token &Result);
    };
}

#endif /* PIGEON_PARSE_LEXER_H */
