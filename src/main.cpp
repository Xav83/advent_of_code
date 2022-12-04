#include "2022/day_1_calorie_counting.hpp"
#include <iostream>

using Day = short;
using Year = unsigned int;

void printSolutionsOfDay(Day day, Year year, auto solver) {
  auto exampleSolutionPart1 = solver.computeFirstPartSolution(
      getFileContext("../res/" + std::to_string(year) + "_day_" +
                     std::to_string(day) + "_example_input.txt"));
  std::cout << "[" << year << "-12-" << day
            << "] Solution of the example for the part 1: "
            << exampleSolutionPart1
            << (exampleSolutionPart1 == 24000 ? " [Success]" : " [FAIL]")
            << std::endl;

  auto part1Solution = solver.computeFirstPartSolution(
      getFileContext("../res/" + std::to_string(year) + "_day_" +
                     std::to_string(day) + "_input.txt"));
  std::cout << "[" << year << "-12-" << day
            << "] Solution of the part 1: " << part1Solution << std::endl;

  auto exampleSolutionPart2 = solver.computeSecondPartSolution(
      getFileContext("../res/" + std::to_string(year) + "_day_" +
                     std::to_string(day) + "_example_input.txt"));
  std::cout << "[" << year << "-12-" << day
            << "] Solution of the example for the part 2: "
            << exampleSolutionPart2
            << (exampleSolutionPart2 == 45000 ? " [Success]" : " [FAIL]")
            << std::endl;

  auto part2Solution = solver.computeSecondPartSolution(
      getFileContext("../res/" + std::to_string(year) + "_day_" +
                     std::to_string(day) + "_input.txt"));
  std::cout << "[" << year << "-12-" << day
            << "] Solution of the part 2: " << part2Solution << std::endl;
}

int main() {

  printSolutionsOfDay(01, 2022, aoc_2022::Day1Solver());

  return 0;
}
