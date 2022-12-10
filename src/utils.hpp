#pragma once
#include <string_view>

std::string getFileContext(const std::string_view filename);

using PuzzleSolution = size_t;

struct PuzzleSolver {
  virtual ~PuzzleSolver() = default;

  virtual PuzzleSolution
  computeFirstPartSolution(const std::string_view input) = 0;
  virtual PuzzleSolution
  computeSecondPartSolution(const std::string_view input) = 0;
};
