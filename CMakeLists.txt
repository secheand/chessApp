cmake_minimum_required(VERSION 3.28)
project(chessApp LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)


add_executable(main src/main.cpp)

add_subdirectory(guiBoard)

target_link_libraries(main
  PRIVATE
    GuiBoardLibrary
  )
