#include "day_3_rucksack_reorganization.hpp"
#include <algorithm>
#include <cctype>

using aoc_2022::Day3Solver;

using Item = char;
using ItemTypePriority = size_t;
using RucksackContent = std::string_view;

ItemTypePriority letterToPriority(const char letter) {
  if (std::islower(letter)) {
    return letter - 'a' + 1;
  }
  return letter - 'A' + 1 + 26;
}

PuzzleSolution
Day3Solver::computeFirstPartSolution(const std::string_view input) {
  ItemTypePriority propertySum{0};

  for (auto it = input.begin(); it != input.end();) {
    const auto endOfLine = std::find(it, input.end(), '\n');
    const auto secondCompartiment =
        std::next(it, std::distance(it, endOfLine) / 2);
    std::vector<Item> itemAlreadyChecked;
    for (; it != secondCompartiment; it = std::next(it)) {
      if (std::any_of(itemAlreadyChecked.begin(), itemAlreadyChecked.end(),
                      [&it](const auto letter) { return letter == *it; })) {
        continue;
      }
      const auto isItemInBothCompartiment =
          std::any_of(secondCompartiment, endOfLine,
                      [&it](const auto letter) { return letter == *it; });

      if (isItemInBothCompartiment) {
        propertySum += letterToPriority(*it);
        itemAlreadyChecked.emplace_back(*it);
      }
    }

    it = std::next(endOfLine);
  }

  return propertySum;
}

PuzzleSolution
Day3Solver::computeSecondPartSolution(const std::string_view input) {
  return 0;
}
