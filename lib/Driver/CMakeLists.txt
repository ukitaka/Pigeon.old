add_executable(pigeonc main.cpp)

target_link_libraries(pigeonc 
    pigeonParser
    LLVMCore
)

