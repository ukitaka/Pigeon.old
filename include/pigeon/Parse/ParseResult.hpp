//
//  ParseResult.h
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/21.
//
//

#ifndef PIGEON_PARSE_PARSE_RESULT_H
#define PIGEON_PARSE_PARSE_RESULT_H

#include "pigeon/Parse/ParseError.hpp"

namespace pigeon {
    
    template <typename T>
    class ParseResult {
    public:
        ParseResult(T const& OK): Kind(Success) {
            Success = OK;
        }

        ParseResult(ParseError const& Err): Kind(ResultKind::Error) {
            Error = Err;
        }
        
        enum class ResultKind {
            Success,
            Error,
        };

    private:
        ResultKind Kind;
        union {
            T Success;
            ParseError Error;
        };
    };
    
}

#endif /* PIGEON_PARSE_PARSE_RESULT_H */
