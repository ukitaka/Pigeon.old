#ifndef PIGEON_PARSE_LEXER_H
#define PIGEON_PARSE_LEXER_H

#include <iostream>
#include <stdlib.h>
#include "pigeon/Basic/SourceLoc.hpp"

namespace llvm {
    class MemoryBuffer;
    class SourceMgr;
}

namespace pigeon {

    enum class tok {
        unknown = 0,
        identifier,
        kw_int,
        kw_var,
        oper_binary_unspaced,
        oper_binary_spaced,
        integer_literal,
        NUM_TOKENS
    };

    class Token {};
    
    class Lexer {
        llvm::SourceMgr &SourceMgr;
        const llvm::MemoryBuffer *Buffer;
        const char *CurPtr;

        Lexer(const Lexer&);
        void operator=(const Lexer&);
        
        public:
        Lexer(unsigned BufferID, llvm::SourceMgr &SM);
        
        void Lex(Token &Result);
    };
}

#endif
