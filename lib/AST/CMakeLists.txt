file( GLOB SRCS *.cpp )
file( GLOB HEADERS
    ${CMAKE_SOURCE_DIR}/include/pigeon/AST/*.hpp
    )

add_pigeon_library(NAME "pigeonAST"
    SRCS ${SRCS} ${HEADERS}
    LINK_LIBRARIES LLVMCore pigeonBasic
)

