# The minimum version of CMake required
cmake_minimum_required(VERSION 3.15)
# The project name
project(MyProject)
project(Games)

# The C++ standard version. Can be 98 11 14 or 17
set(CMAKE_CXX_STANDARD 14)
set(SFML_INCLUDE_DIR "./SFML/include")
set(SFML_LIBRARY_DIR "./SFML/build/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(MyProject main.cpp)
add_executable(Pong Pong.cpp classPong.cpp classPong.h )
add_executable(Snacks Snakes.cpp)
add_executable(cSnakes Snakes.cpp classSnake.cpp classSnake.h)
add_executable(Games Games.cpp classSnake.cpp classSnake.h classPong.cpp classPong.h classShooter.cpp classShooter.h classBullet.cpp classBullet.h classEnemy.cpp classEnemy.h)
add_executable(Shooter Shooter.cpp classShooter.cpp classShooter.h classBullet.cpp classBullet.h classEnemy.cpp classEnemy.h)

target_link_libraries (MyProject sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries (Pong sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries (Snacks sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries (cSnakes sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries (Games sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries(Shooter sfml-graphics sfml-window sfml-system sfml-audio sfml-network)