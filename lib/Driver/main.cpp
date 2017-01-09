#include <iostream>
#include <string>
#include "llvm/ADT/StringSwitch.h"
#include "pigeon/Parse/Lexer.hpp"
#include "pigeon/Parse/Token.hpp"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/SMLoc.h"

using namespace std;
//using namespace llvm;

int main() {
    llvm::SourceMgr SourceMgr;
    const char *source = "1+2\n";
    unique_ptr<llvm::MemoryBuffer> buf = llvm::MemoryBuffer::getMemBuffer(source);
    unsigned mainFileID = SourceMgr.AddNewSourceBuffer(std::move(buf), llvm::SMLoc());
    printf("%2d\n", mainFileID);

    return 0;
}
