#include "2022/day_1_calorie_counting.hpp"
#include <fmt/core.h>

using Day = short;
using Year = unsigned int;

void printSolutionsOfDay(Day day, Year year, auto solver,
                         PuzzleSolution expectedExamplePart1Solution,
                         PuzzleSolution expectedExamplePart2Solution) {
  auto exampleLocation =
      fmt::format("../res/{}_day_{}_example_input.txt", year, day);
  auto exampleSolutionPart1 =
      solver.computeFirstPartSolution(getFileContext(exampleLocation));
  fmt::print("[{}-12-{}] Solution of the example for the part 1: {} [{}]\n",
             year, day, exampleSolutionPart1,
             (exampleSolutionPart1 == expectedExamplePart1Solution ? "Success"
                                                                   : "FAIL"));

  auto inputLocation = fmt::format("../res/{}_day_{}_input.txt", year, day);
  auto part1Solution =
      solver.computeFirstPartSolution(getFileContext(inputLocation));
  fmt::print("[{}-12-{}] Solution of the part 1: {}\n", year, day,
             part1Solution);

  auto exampleSolutionPart2 =
      solver.computeSecondPartSolution(getFileContext(exampleLocation));
  fmt::print("[{}-12-{}] Solution of the example for the part 2: {} [{}]\n",
             year, day, exampleSolutionPart2,
             (exampleSolutionPart2 == expectedExamplePart2Solution ? "Success"
                                                                   : "FAIL"));

  auto part2Solution =
      solver.computeSecondPartSolution(getFileContext(inputLocation));
  fmt::print("[{}-12-{}] Solution of the part 2: {}\n", year, day,
             part2Solution);
}

int main() {

  printSolutionsOfDay(01, 2022, aoc_2022::Day1Solver(), 24000, 45000);

  return 0;
}
