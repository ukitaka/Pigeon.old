//
//  ParseError.cpp
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/21.
//
//

#include "pigeon/Parse/ParseError.hpp"

using namespace pigeon;

ParseError::ParseError(llvm::StringRef Message, ParseErrorKind Kind):
Kind(Kind),
Message(Message)
{

}
