#include "2015/day_1_not_quite_lisp.hpp"
#include "2015/day_2_I_was_told_there_would_be_no_math.hpp"
#include "2022/day_1_calorie_counting.hpp"
#include "2022/day_2_rock_paper_scissors.hpp"
#include "2022/day_3_rucksack_reorganization.hpp"
#include "2022/day_4_camp_cleanup.hpp"

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

  printSolutionsOfDay(01, 2015, aoc_2015::Day1Solver(), 3, 1);
  printSolutionsOfDay(02, 2015, aoc_2015::Day2Solver(), 58, 34);
  printSolutionsOfDay(01, 2022, aoc_2022::Day1Solver(), 24000, 45000);
  printSolutionsOfDay(02, 2022, aoc_2022::Day2Solver(), 15, 12);
  printSolutionsOfDay(03, 2022, aoc_2022::Day3Solver(), 157, 70);
  printSolutionsOfDay(04, 2022, aoc_2022::Day4Solver(), 2, -1);

  return 0;
}
