#ifndef PIGEON_PARSE_LEXER_H
#define PIGEON_PARSE_LEXER_H

#include <iostream>
#include <stdlib.h>
#include "pigeon/Basic/SourceLoc.hpp"

namespace pigeon {

    enum class tok {
        unknown = 0,
        identifier,
        oper_binary_unspaced,
        oper_binary_spaced,
        integer_literal,
        NUM_TOKENS
    };
    
    class Lexer {
        public:
            void test();
    };
}

#endif
