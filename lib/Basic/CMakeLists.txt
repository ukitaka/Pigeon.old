file( GLOB SRCS *.cpp )
file( GLOB HEADERS
    ${CMAKE_SOURCE_DIR}/include/pigeon/Basic/*.hpp)

add_pigeon_library(NAME "pigeonBasic"
    SRCS ${SRCS} ${HEADERS}
    LINK_LIBRARIES LLVMCore LLVMSupport
)

