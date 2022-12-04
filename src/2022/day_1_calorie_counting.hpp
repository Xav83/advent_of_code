#pragma once
#include "utils.hpp"

namespace aoc_2022 {
struct Day1Solver : PuzzleSolver {
  PuzzleSolution
  computeFirstPartSolution(const std::string_view input) override;
  PuzzleSolution
  computeSecondPartSolution(const std::string_view input) override;
};
} // namespace aoc_2022
