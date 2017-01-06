#include <iostream>
#include <stdlib.h>
#include <string>
#include "llvm/ADT/StringSwitch.h"
#include "pigeon/Parse/lexer.hpp"

void pigeon::Lexer::test() {
    std::cout << "test!! OK!!" << std::endl;
    std::string str = "func";
    int i = llvm::StringSwitch<int>(str)
    .Case("func", 1)
    .Case("class", 2)
    .Default(3);

    std::cout << "hello world!!!" << std::endl;
    std::cout << i << std::endl;
}
