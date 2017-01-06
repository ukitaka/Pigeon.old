file( GLOB SRCS *.cpp )
file( GLOB HEADERS
    ${CMAKE_SOURCE_DIR}/include/pigeon/Parse/*.hpp
    ${CMAKE_SOURCE_DIR}/include/pigeon/Parse/*.def
    )

add_pigeon_library(NAME "pigeonParser"
    SRCS ${SRCS} ${HEADERS}
    LINK_LIBRARIES LLVMCore
)

