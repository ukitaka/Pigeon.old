include(CMakeParseArguments)

function(add_pigeon_library)
    cmake_parse_arguments(
        PGN 
        ""
        "NAME" 
        "SRCS;LINK_LIBRARIES"
        ${ARGN})

    add_library(${PGN_NAME} ${PGN_SRCS})

    target_link_libraries(${PGN_NAME} ${PGN_LINK_LIBRARIES})

    include_directories( ${CMAKE_SOURCE_DIR}/include )
endfunction(add_pigeon_library)

function(add_pigeon_executable)
    cmake_parse_arguments(
        PGN 
        ""
        "NAME" 
        "SRCS;LINK_LIBRARIES"
        ${ARGN})
    add_executable(${PGN_NAME} ${PGN_SRCS})

    target_link_libraries(${PGN_NAME} ${PGN_LINK_LIBRARIES})

    include_directories( ${CMAKE_SOURCE_DIR}/include )
endfunction(add_pigeon_executable)

