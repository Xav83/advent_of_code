#include "day_1_calorie_counting.hpp"
#include <string>

using aoc_2022::Day1Solver;

using Calories = size_t;

PuzzleSolution
Day1Solver::computeFirstPartSolution(const std::string_view input) {
  auto it = input.begin();
  Calories maxCaloriesCarryByOneElf = 0;
  Calories caloriesCarriedByCurrentElf = 0;

  while (it != input.end()) {
    if (*it == '\n') {
      maxCaloriesCarryByOneElf =
          std::max(maxCaloriesCarryByOneElf, caloriesCarriedByCurrentElf);
      caloriesCarriedByCurrentElf = 0;
      ++it;
      continue;
    }
    auto endOfNumber = std::find(it, input.end(), '\n');
    caloriesCarriedByCurrentElf += std::stoi(std::string(it, endOfNumber));
    it = std::next(endOfNumber);
  }

  return maxCaloriesCarryByOneElf;
}

PuzzleSolution
Day1Solver::computeSecondPartSolution(const std::string_view input) {
  return 0;
}
