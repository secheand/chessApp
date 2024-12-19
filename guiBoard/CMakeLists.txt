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
        # ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # where top-level project will look for the library's public headers
        # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        # $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)


include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)


target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET GuiBoardLibrary
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()
