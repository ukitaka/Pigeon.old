#include <iostream>
#include <string>
#include "llvm/ADT/StringSwitch.h"
#include "pigeon/Parse/lexer.hpp"

using namespace std;

int main() {
    auto lexer = new pigeon::Lexer();

    lexer->test();

    return 0;
}

