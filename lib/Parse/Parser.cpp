#include "pigeon/Parse/Parser.hpp"
#include "pigeon/Parse/Lexer.hpp"
#include "llvm/Support/SourceMgr.h"
#include <memory>

using namespace pigeon;

Parser::Parser(unsigned BufferID, llvm::SourceMgr &SourceMgr)
    : L(std::unique_ptr<Lexer>(new Lexer(BufferID, SourceMgr))) {}
