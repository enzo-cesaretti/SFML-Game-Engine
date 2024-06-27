cmake_minimum_required(VERSION 3.22)
project(game-engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(APPLE)
    include_directories(/opt/homebrew/include)
    link_directories(/opt/homebrew/lib)
endif()

include_directories(include)
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(game ${SOURCES})
target_link_libraries(game sfml-graphics sfml-window sfml-system sfml-audio)
target_compile_options(game PRIVATE -W -Wall -Wextra -Werror)
