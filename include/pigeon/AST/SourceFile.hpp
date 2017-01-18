//
//  SourceFile.hpp
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/17.
//
//

#ifndef PIGEON_AST_SOURCE_H
#define PIGEON_AST_SOURCE_H

#include <memory>

namespace pigeon {
class SourceFile {
public:
  SourceFile(unsigned BufferID);
};
}

#endif /* PIGEON_AST_SOURCE_H */
