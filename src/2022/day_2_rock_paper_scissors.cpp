#include "day_2_rock_paper_scissors.hpp"
#include <algorithm>
#include <array>
#include <cassert>

using aoc_2022::Day2Solver;

using Hand = char;
using Score = size_t;

static constexpr Score LOST_SCORE = 0;
static constexpr Score DRAW_SCORE = 3;
static constexpr Score WIN_SCORE = 6;

static constexpr Score ROCK_SCORE = 1;
static constexpr Score PAPER_SCORE = 2;
static constexpr Score SCISSORS_SCORE = 3;

struct Match {
  Hand elf;
  Hand me;
  Score value;
};

constexpr std::array<Match, 9> matches{
    Match{'A', 'X', ROCK_SCORE + DRAW_SCORE},
    Match{'A', 'Y', PAPER_SCORE + WIN_SCORE},
    Match{'A', 'Z', SCISSORS_SCORE + LOST_SCORE},
    Match{'B', 'X', ROCK_SCORE + LOST_SCORE},
    Match{'B', 'Y', PAPER_SCORE + DRAW_SCORE},
    Match{'B', 'Z', SCISSORS_SCORE + WIN_SCORE},
    Match{'C', 'X', ROCK_SCORE + WIN_SCORE},
    Match{'C', 'Y', PAPER_SCORE + LOST_SCORE},
    Match{'C', 'Z', SCISSORS_SCORE + DRAW_SCORE}};

PuzzleSolution
Day2Solver::computeFirstPartSolution(const std::string_view input) {
  Score finalScore{0};
  for (auto it = input.begin(); it != input.end(); it = std::next(it, 4)) {
    assert(std::distance(it, std::find(it, input.end(), '\n')) == 3);

    const Hand elf = *it;
    const Hand me = *std::next(it, 2);

    auto currentMatch = std::find_if(
        matches.begin(), matches.end(), [&elf, &me](const auto &match) {
          return match.elf == elf and match.me == me;
        });
    assert(currentMatch != matches.end());
    finalScore += currentMatch->value;
  }
  return finalScore;
}

PuzzleSolution
Day2Solver::computeSecondPartSolution(const std::string_view input) {
  return 0;
}
