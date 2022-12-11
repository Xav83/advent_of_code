#include "day_2_I_was_told_there_would_be_no_math.hpp"
#include <algorithm>
#include <cassert>
#include <ranges>
#include <vector>

using aoc_2015::Day2Solver;

struct Dimensions {
  int length{0};
  int width{0};
  int height{0};

  std::vector<int> toAreas() const {
    return {length * width, width * height, height * length};
  }
};

Dimensions makeDimensionFromLine(const std::string_view input) {
  Dimensions dimensions;
  int counter{0};

  for (auto it = input.begin(); it != input.end();) {
    const auto delimiter = std::find(it, input.end(), 'x');
    std::string_view dimensionsStr(it, delimiter);

    switch (counter) {
    case 0:
      dimensions.length = atoi(dimensionsStr.data());
      break;
    case 1:
      dimensions.width = atoi(dimensionsStr.data());
      break;
    case 2:
      dimensions.height = atoi(dimensionsStr.data());
      break;
    default:
      assert(false);
      break;
    }
    ++counter;

    it = delimiter != input.end() ? std::next(delimiter) : delimiter;
  }

  return dimensions;
}

PuzzleSolution
Day2Solver::computeFirstPartSolution(const std::string_view input) {
  PuzzleSolution wrappingPaperArea{0};

  for (auto it = input.begin(); it != input.end();) {
    const auto endOfLine = std::find(it, input.end(), '\n');

    const auto dimension =
        makeDimensionFromLine(std::string_view(it, endOfLine));
    const auto areas = dimension.toAreas();
    const auto min = std::ranges::min_element(areas);
    wrappingPaperArea += 2 * areas[0] + 2 * areas[1] + 2 * areas[2] + *min;

    it = std::next(endOfLine);
  }

  return wrappingPaperArea;
}

PuzzleSolution
Day2Solver::computeSecondPartSolution(const std::string_view input) {
  PuzzleSolution ribbonLength{0};
  for (auto it = input.begin(); it != input.end();) {
    const auto endOfLine = std::find(it, input.end(), '\n');
    const auto dimension =
        makeDimensionFromLine(std::string_view(it, endOfLine));
    const auto max =
        std::max({dimension.length, dimension.width, dimension.height});
    ribbonLength += 2 * dimension.length + 2 * dimension.width +
                    2 * dimension.height - 2 * max +
                    dimension.length * dimension.width * dimension.height;
    it = std::next(endOfLine);
  }
  return ribbonLength;
}
