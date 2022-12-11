#include "day_3_rucksack_reorganization.hpp"
#include <algorithm>
#include <cctype>
#include <ranges>
#include <vector>

using aoc_2022::Day3Solver;

using Item = char;
using ItemTypePriority = size_t;
using RucksackContent = std::string_view;

ItemTypePriority letterToPriority(const Item letter) {
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
      if (std::ranges::any_of(itemAlreadyChecked, [&it](const auto letter) {
            return letter == *it;
          })) {
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
  ItemTypePriority propertySum{0};

  for (auto it = input.begin(); it != input.end();) {
    const auto endOfLineRucksack1 = std::find(it, input.end(), '\n');
    const auto startOfLineRucksack2 = std::next(endOfLineRucksack1);
    const auto endOfLineRucksack2 =
        std::find(startOfLineRucksack2, input.end(), '\n');
    const auto startOfLineRucksack3 = std::next(endOfLineRucksack2);
    const auto endOfLineRucksack3 =
        std::find(startOfLineRucksack3, input.end(), '\n');

    for (; it != endOfLineRucksack1; it = std::next(it)) {
      const auto isItemInRuckscak2 =
          std::any_of(startOfLineRucksack2, endOfLineRucksack2,
                      [&it](const auto letter) { return letter == *it; });
      const auto isItemInRuckscak3 =
          std::any_of(startOfLineRucksack3, endOfLineRucksack3,
                      [&it](const auto letter) { return letter == *it; });

      if (isItemInRuckscak2 && isItemInRuckscak3) {
        propertySum += letterToPriority(*it);
        break;
      }
    }

    it = std::next(endOfLineRucksack3);
  }

  return propertySum;
}
