cmake_minimum_required(VERSION 3.22.4 FATAL_ERROR)

project(
  advent_of_code
  VERSION 0.1.0
  DESCRIPTION "C++ solutions to Avent of Code puzzles"
  HOMEPAGE_URL "https://adventofcode.com/"
  LANGUAGES CXX)

set(AOC_SOURCE_FOLDER ${CMAKE_CURRENT_LIST_DIR}/src)

add_executable(
  advent_of_code
  ${AOC_SOURCE_FOLDER}/main.cpp
  ${AOC_SOURCE_FOLDER}/2022/day_1_calorie_counting.cpp
  ${AOC_SOURCE_FOLDER}/utils.cpp)
set_target_properties(advent_of_code PROPERTIES CXX_STANDARD 20)
target_include_directories(advent_of_code PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src)
