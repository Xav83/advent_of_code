#include "day_1_not_quite_lisp.hpp"
#include <algorithm>
#include <cassert>

using aoc_2015::Day1Solver;

PuzzleSolution
Day1Solver::computeFirstPartSolution(const std::string_view input) {
  const auto openParenthesisCount =
      std::count(std::begin(input), std::end(input), '(');
  const auto closeParenthesisCount =
      std::count(std::begin(input), std::end(input), ')');

  return openParenthesisCount - closeParenthesisCount;
}

PuzzleSolution
Day1Solver::computeSecondPartSolution(const std::string_view input) {
  auto floor{0};
  const auto firstEnteringInTheBasement = std::find_if(
      std::begin(input), std::end(input), [&floor](const auto &character) {
        if (character == '(') {
          ++floor;
        } else if (character == ')') {
          --floor;
        }
        return floor < 0;
      });
  assert(firstEnteringInTheBasement != std::end(input));

  return std::distance(std::begin(input), firstEnteringInTheBasement) + 1;
}
