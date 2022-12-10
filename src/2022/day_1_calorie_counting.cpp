#include "day_1_calorie_counting.hpp"
#include <algorithm>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

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
  // last elf
  maxCaloriesCarryByOneElf =
      std::max(maxCaloriesCarryByOneElf, caloriesCarriedByCurrentElf);

  return maxCaloriesCarryByOneElf;
}

PuzzleSolution
Day1Solver::computeSecondPartSolution(const std::string_view input) {
  auto it = input.begin();
  std::vector<Calories> maxCaloriesCarryByTopThreeElves = {0, 0, 0};
  Calories caloriesCarriedByCurrentElf = 0;

  while (it != input.end()) {
    if (*it == '\n') {

      maxCaloriesCarryByTopThreeElves.emplace_back(caloriesCarriedByCurrentElf);
      maxCaloriesCarryByTopThreeElves.erase(
          std::ranges::min_element(maxCaloriesCarryByTopThreeElves));
      caloriesCarriedByCurrentElf = 0;
      ++it;
      continue;
    }
    auto endOfNumber = std::find(it, input.end(), '\n');
    caloriesCarriedByCurrentElf += std::stoi(std::string(it, endOfNumber));
    it = std::next(endOfNumber);
  }

  // last elf
  maxCaloriesCarryByTopThreeElves.emplace_back(caloriesCarriedByCurrentElf);
  maxCaloriesCarryByTopThreeElves.erase(
      std::ranges::min_element(maxCaloriesCarryByTopThreeElves));

  return std::accumulate(maxCaloriesCarryByTopThreeElves.begin(),
                         maxCaloriesCarryByTopThreeElves.end(), 0);
}
