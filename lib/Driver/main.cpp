#include <iostream>
#include <string>
#include "llvm/ADT/StringSwitch.h"

using namespace std;

int main() {
    string str = "func";
    int i = llvm::StringSwitch<int>(str)
    .Case("func", 4)
    .Case("class", 2)
    .Default(3);

    cout << "hello world!!!" << endl;
    cout << i << endl;
    return 0;
}
