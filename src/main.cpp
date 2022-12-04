#include "2022/day_1_calorie_counting.hpp"
#include <iostream>

int main() {

  aoc_2022::Day1Solver day1Solver;
  auto exampleSolution = day1Solver.computeFirstPartSolution(
      getFileContext("../res/2022_day_1_example_input.txt"));
  std::cout << "[2022-12-01] Solution of the example:" << exampleSolution
            << (exampleSolution == 24000 ? " [Success]" : "FAIL") << std::endl;

  return 0;
}
