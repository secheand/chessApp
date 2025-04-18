cmake_minimum_required(VERSION 3.28)

project(GuiBoardLibrary)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        src/guiBoard.cpp
        include/guiBoard.hpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)


target_link_libraries(${PROJECT_NAME}
PUBLIC

PRIVATE
PieceManagerLibrary
)
