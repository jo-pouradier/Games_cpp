# The minimum version of CMake required
cmake_minimum_required(VERSION 3.15)
# The project name
project(MyProject)
project(Pong)
# The C++ standard version. Can be 98 11 14 or 17
set(CMAKE_CXX_STANDARD 14)
set(SFML_INCLUDE_DIR "./SFML/include")
set(SFML_LIBRARY_DIR "./SFML/build/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(MyProject main.cpp)
add_executable(Pong mainPong.cpp classPong.cpp classPong.h input.cpp input.h)
add_executable(Snacks mainSnacks.cpp)
add_executable(cSnakes Snakes.cpp classSnake.cpp classSnake.h)

target_link_libraries (MyProject sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries (Pong sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries (Snacks sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries (cSnakes sfml-graphics sfml-window sfml-system sfml-audio sfml-network)