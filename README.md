## Pigeon

Swift-like programming language using LLVM

## Developing with Xcode

First, install `llvm` and `cmake`.

```
$ brew install llvm
$ brew install cmake
```

Clone `Pigeon` repository

```
$ git clone https://github.com/ukitaka/Pigeon.git
```

Make `xcode` dir and run `cmake`, and finally you can use `pigeon.xcodeproj`.

```
$ mkdir xcode
$ cd xcode
$ cmake .. -G "Xcode"
$ open pigeon.xcodeproj
```

