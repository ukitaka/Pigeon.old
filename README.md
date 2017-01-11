## Pigeon

Swift-like programming language using LLVM

## Developing in Xcode

First, install `llvm`, `cmake` and `clang-format`.

```
$ brew install llvm
$ brew install cmake
$ brew install clang-format
```

Clone `Pigeon` repository

```
$ git clone https://github.com/ukitaka/Pigeon.git
```

Make `build` dir and run `cmake`, and finally you can use `pigeon.xcodeproj`.

```
$ mkdir build
$ cd build
$ cmake .. -G "Xcode"
$ open pigeon.xcodeproj
```

## Coding Standards

See: [LLVM Coding Standards](http://llvm.org/docs/CodingStandards.html#name-types-functions-variables-and-enumerators-properly)

