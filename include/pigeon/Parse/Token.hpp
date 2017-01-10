//
//  Token.h
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/06.
//
//

#ifndef PIGEON_PARSE_TOKEN_H
#define PIGEON_PARSE_TOKEN_H

#include "llvm/ADT/StringRef.h"

namespace pigeon {
    enum class tok {
        unknown = 0,
        eof,
        identifier,
        numeric_constant,
        plus, // +
        NUM_TOKENS
    };

    class Token {
        tok token;
        llvm::StringRef Text;
    public:
        Token(): token(tok::unknown) {}

        llvm::StringRef getText() const { return Text; }
        bool isEOF() const { return token == tok::eof; }

        void setToken(tok K, llvm::StringRef T) {
            token = K;
            Text = T;
        }
    };
}

#endif /* PIGEON_PARSE_TOKEN_H */
