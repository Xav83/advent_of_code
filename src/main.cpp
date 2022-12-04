#include "2022/day_1_calorie_counting.hpp"
#include <iostream>

int main() {

  aoc_2022::Day1Solver day1Solver;
  auto exampleSolutionPart1 = day1Solver.computeFirstPartSolution(
      getFileContext("../res/2022_day_1_example_input.txt"));
  std::cout << "[2022-12-01] Solution of the example for the part 1: "
            << exampleSolutionPart1
            << (exampleSolutionPart1 == 24000 ? " [Success]" : " [FAIL]")
            << std::endl;

  auto part1Solution = day1Solver.computeFirstPartSolution(
      getFileContext("../res/2022_day_1_part_1_input.txt"));
  std::cout << "[2022-12-01] Solution of the part 1: " << part1Solution
            << std::endl;

  auto exampleSolutionPart2 = day1Solver.computeSecondPartSolution(
      getFileContext("../res/2022_day_1_example_input.txt"));
  std::cout << "[2022-12-01] Solution of the example for the part 2: "
            << exampleSolutionPart2
            << (exampleSolutionPart2 == 45000 ? " [Success]" : " [FAIL]")
            << std::endl;

  return 0;
}
