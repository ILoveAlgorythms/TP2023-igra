cmake_minimum_required(VERSION 3.0)

project(farm_project)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(SadFarm main.cpp animal.cpp farm.cpp  market.hpp resources.hpp
animal.hpp  farm.hpp  market.cpp resources.cpp)

target_link_libraries(SadFarm sfml-graphics sfml-audio)