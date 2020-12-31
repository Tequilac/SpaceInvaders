cmake_minimum_required(VERSION 3.1)

project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 17)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "C:/C++/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SpaceInvaders src/Main.cpp src/Object.cpp src/Object.h src/Laser.cpp src/Laser.h src/Entity.cpp src/Entity.h src/Player.cpp src/Player.h src/MoveDirection.h)
target_link_libraries(SpaceInvaders sfml-graphics sfml-audio)