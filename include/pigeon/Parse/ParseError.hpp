//
//  ParseError.h
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/21.
//
//

#ifndef PIGEON_PARSE_PARSE_ERROR_H
#define PIGEON_PARSE_PARSE_ERROR_H

#include "llvm/ADT/StringRef.h"

namespace pigeon {
enum class ParseErrorKind { InvalidToken };

class ParseError {
public:
  ParseError(llvm::StringRef Message, ParseErrorKind Kind);

  ParseErrorKind GetKind() const { return Kind; }
  llvm::StringRef GetMessage() const { return Message; }

private:
  ParseErrorKind Kind;
  llvm::StringRef Message;
};
}

#endif /* PIGEON_PARSE_PARSE_ERROR_H */
