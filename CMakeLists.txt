cmake_minimum_required(VERSION 3.0)

project(farm_project)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Binarnik main.cpp animal.cpp farm.cpp  market.hpp player.hpp resources.hpp
animal.hpp  farm.hpp  market.cpp  player.cpp resources.cpp  test.cpp
)

target_link_libraries(Binarnik sfml-graphics sfml-audio)