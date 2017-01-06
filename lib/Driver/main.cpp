#include <iostream>
#include <string>
#include "llvm/ADT/StringSwitch.h"
#include "pigeon/Parse/Lexer.hpp"
#include "pigeon/Parse/Token.hpp"

using namespace std;

int main() {
//    auto lexer = new pigeon::Lexer();
//    lexer->test();

    printf("%2d\n", pigeon::tok::identifier);
    printf("%2d\n", pigeon::tok::NUM_TOKENS);
    printf("%2d\n", pigeon::tok::integer_literal);

    return 0;
}

