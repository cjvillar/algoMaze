
cmake_minimum_required(VERSION 3.10)

# set project name and the required C++ standard
project(MyProject VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add source files
add_executable(
MyProject
src/bfs.cpp
src/startScreen.cpp
src/main.cpp 
)

# include directories
target_include_directories(MyProject PRIVATE dependencies/include) 

# copy assets directory into build 
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# link SFML libraries
set(SFML_LIB_DIR "${CMAKE_SOURCE_DIR}/dependencies/lib")

find_library(SFML_AUDIO sfml-audio PATHS ${SFML_LIB_DIR})
find_library(SFML_GRAPHICS sfml-graphics PATHS ${SFML_LIB_DIR})
find_library(SFML_NETWORK sfml-network PATHS ${SFML_LIB_DIR})
find_library(SFML_SYSTEM sfml-system PATHS ${SFML_LIB_DIR})
find_library(SFML_WINDOW sfml-window PATHS ${SFML_LIB_DIR})

target_link_libraries(MyProject PRIVATE
    ${SFML_AUDIO}
    ${SFML_GRAPHICS}
    ${SFML_NETWORK}
    ${SFML_SYSTEM}
    ${SFML_WINDOW}
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreFoundation"
    "-framework CoreVideo"
)

# Optional: copy dynamic libraries to the output directory
add_custom_command(TARGET MyProject POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${SFML_LIB_DIR} $<TARGET_FILE_DIR:MyProject>
)