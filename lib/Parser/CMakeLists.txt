file( GLOB SRCS *.cpp *.hpp )

execute_process (COMMAND 
      llvm-config --cxxflags
      OUTPUT_VARIABLE CXXFLAGS_)

execute_process (COMMAND 
      llvm-config --ldflags 
      OUTPUT_VARIABLE LINKER_FLAGS_)

string (REPLACE "\n" " " CXXFLAGS ${CXXFLAGS_})
string (REPLACE "\n" " " LINKER_FLAGS ${LINKER_FLAGS_})

set (CMAKE_CXX_FLAGS "-g ${CXXFLAGS}")
set (CMAKE_EXE_LINKER_FLAGS "-g ${LINKER_FLAGS}")

add_library(pigeonParser ${SRCS})

target_link_libraries(pigeonParser 
    LLVMCore
)

