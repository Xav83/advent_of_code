#include "day_1_calorie_counting.hpp"
#include <numeric>
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

#include <iostream>

PuzzleSolution
Day1Solver::computeSecondPartSolution(const std::string_view input) {
  auto it = input.begin();
  std::vector<Calories> maxCaloriesCarryByTopThreeElves = {0, 0, 0};
  Calories caloriesCarriedByCurrentElf = 0;

  while (it != input.end()) {
    if (*it == '\n') {

      maxCaloriesCarryByTopThreeElves.emplace_back(caloriesCarriedByCurrentElf);
      maxCaloriesCarryByTopThreeElves.erase(
          std::min_element(maxCaloriesCarryByTopThreeElves.begin(),
                           maxCaloriesCarryByTopThreeElves.end()));
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
      std::min_element(maxCaloriesCarryByTopThreeElves.begin(),
                       maxCaloriesCarryByTopThreeElves.end()));

  std::cout << "Top " << maxCaloriesCarryByTopThreeElves.size() << ": "
            << maxCaloriesCarryByTopThreeElves[0] << ", "
            << maxCaloriesCarryByTopThreeElves[1] << ", "
            << maxCaloriesCarryByTopThreeElves[2] << std::endl;

  return std::accumulate(maxCaloriesCarryByTopThreeElves.begin(),
                         maxCaloriesCarryByTopThreeElves.end(), 0);
}
