cmake_minimum_required(VERSION 3.7)

include(cmake/modules/AddPigeon.cmake)

project (pigeon)

execute_process (COMMAND 
    llvm-config --cxxflags
    OUTPUT_VARIABLE CXXFLAGS_)

execute_process (COMMAND 
    llvm-config --ldflags --system-libs 
    OUTPUT_VARIABLE LINKER_FLAGS_)

string (REPLACE "\n" " " CXXFLAGS ${CXXFLAGS_})
string (REPLACE "\n" " " LINKER_FLAGS ${LINKER_FLAGS_})

set (CMAKE_CXX_FLAGS "-g ${CXXFLAGS}")
set (CMAKE_EXE_LINKER_FLAGS "-g ${LINKER_FLAGS}")

add_subdirectory(lib)


# clang-format
execute_process (COMMAND 
    which clang-format
    OUTPUT_VARIABLE CLANG_FMT_PATH)

file(GLOB_RECURSE ALL_SOURCE_FILES RELATIVE ${PROJECT_BINARY_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/lib/*.cpp
    ${CMAKE_CURRENT_LIST_DIR}/include/*.hpp) 

add_custom_target( clangformat COMMAND ${CLANG_FMT_PATH} -style=LLVM -i ${ALL_SOURCE_FILES} )
