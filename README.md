# Propolis
Contains common C/C++ libraries used in multiple SwarmUS projects. The libraries does not use heap and thus can be used in embedded development.

## Pheromones
A wrapper over nanopb for serialization and deserialization of messages

### Requirements
Note that you will need some requirements since we use protobuf and nanopb

* [Protoc](https://developers.google.com/protocol-buffers) and some python deps to build [Pheromones](https://github.com/SwarmUS/Pheromones). Check Pheromones repo for more info
* The python libraries for protobuf to generate the required files

Nanopb itself will be fetch at generation to allow compilation on embedded targets.
On Ubuntu 20.04 you can download these requirements using `apt install protobuf-compiler python3-protobuf`

### Libraries

#### Common
A shared code for pheromones sub libraries

#### Hivemind-host
A library used for communication between the Hivemind and its host. Note that as of now, there is some restrictions since the library does not use heap. Notably the length of the strings are maximum 32 characters, including the NULL terminating character. The arrays of arguments for a function call have a maximum of 16 arguments. The library does a lot of copies as of now, but it will be fixed eventually.


## Building

``` sh

git clone https://github.com/SwarmUS/Propolis
cd Propolis
mkdir build
cd build
cmake ..
make
```
`

## Development
We use a couple tools and static analyzers, to follow them use.

* [CMake](https://cmake.org/) 3.13

* [Gcc](https://gcc.gnu.org/) or any c++ 17 compiler 

* [Clang tools](https://clang.llvm.org/docs/ClangTools.html) are used to match the style and warnings used in the project
    * [clang-format](https://clang.llvm.org/docs/ClangFormat.html) to match the coding style
    * [clang-tidy](https://clang.llvm.org/extra/clang-tidy/) for additional compiler warnings
* [Doxygen](https://github.com/doxygen/doxygen) and [graphviz](https://gitlab.com/graphviz/graphviz/) to generate the documentation



``` sh
cmake -DENABLE_ERROR_ON_MISSING_TOOL=ON -DENABLE_WARNINGS_AS_ERROR=ON -DENABLE_WARNINGS=ON -DENABLE_CLANG_TIDY_CHECK=ON -DENABLE_TESTS=ON -DCMAKE_BUILD_TYPE=Debug ..
```

