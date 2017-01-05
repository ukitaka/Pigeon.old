## Pigeon

Swift-like programming language using LLVM

## Developing in Xcode

First, install `llvm` and `cmake`.

```
$ brew install llvm
$ brew install cmake
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

