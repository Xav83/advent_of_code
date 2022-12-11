#include "day_4_camp_cleanup.hpp"
#include <algorithm>
#include <cstdlib>
#include <string_view>

using aoc_2022::Day4Solver;

using SectionID = size_t;

constexpr char SECTION_DELIMITER = ',';
constexpr char RANGE_SEPARATOR = '-';

struct Section {
  [[nodiscard]] bool isContainedIn(const Section &other) const {
    return other.begin <= begin && end <= other.end;
  }

  [[nodiscard]] bool doesOverlapWith(const Section &other) const {
    return other.begin <= begin && begin <= other.end ||
           other.begin <= end && end <= other.end;
  }

  SectionID begin{0};
  SectionID end{0};
};

PuzzleSolution
Day4Solver::computeFirstPartSolution(const std::string_view input) {
  PuzzleSolution pairsOfSectionsContainingOneAnother{0};

  for (auto it = input.begin(); it != input.end();) {
    const auto endOfLine = std::find(it, input.end(), '\n');
    const auto sectionDelimiterIt = std::find(it, endOfLine, SECTION_DELIMITER);
    const auto firstRangeSeparatorIt =
        std::find(it, sectionDelimiterIt, RANGE_SEPARATOR);
    const auto secondRangeSeparatorIt =
        std::find(sectionDelimiterIt, endOfLine, RANGE_SEPARATOR);

    const auto firstNumberOfFirstRange =
        std::string_view(it, firstRangeSeparatorIt);
    const auto secondNumberOfFirstRange =
        std::string_view(std::next(firstRangeSeparatorIt), sectionDelimiterIt);
    const auto firstNumberOfSecondRange =
        std::string_view(std::next(sectionDelimiterIt), secondRangeSeparatorIt);
    const auto secondNumberOfSecondRange =
        std::string_view(std::next(secondRangeSeparatorIt), endOfLine);

    const Section firstSection(std::atoi(firstNumberOfFirstRange.data()),
                               std::atoi(secondNumberOfFirstRange.data()));
    const Section secondSection(std::atoi(firstNumberOfSecondRange.data()),
                                std::atoi(secondNumberOfSecondRange.data()));

    if (firstSection.isContainedIn(secondSection) ||
        secondSection.isContainedIn(firstSection)) {
      ++pairsOfSectionsContainingOneAnother;
    }

    it = std::next(endOfLine);
  }
  return pairsOfSectionsContainingOneAnother;
}

PuzzleSolution
Day4Solver::computeSecondPartSolution(const std::string_view input) {
  PuzzleSolution numberOfPairsOfOverlappingSection{0};

  for (auto it = input.begin(); it != input.end();) {
    const auto endOfLine = std::find(it, input.end(), '\n');
    const auto sectionDelimiterIt = std::find(it, endOfLine, SECTION_DELIMITER);
    const auto firstRangeSeparatorIt =
        std::find(it, sectionDelimiterIt, RANGE_SEPARATOR);
    const auto secondRangeSeparatorIt =
        std::find(sectionDelimiterIt, endOfLine, RANGE_SEPARATOR);

    const auto firstNumberOfFirstRange =
        std::string_view(it, firstRangeSeparatorIt);
    const auto secondNumberOfFirstRange =
        std::string_view(std::next(firstRangeSeparatorIt), sectionDelimiterIt);
    const auto firstNumberOfSecondRange =
        std::string_view(std::next(sectionDelimiterIt), secondRangeSeparatorIt);
    const auto secondNumberOfSecondRange =
        std::string_view(std::next(secondRangeSeparatorIt), endOfLine);

    const Section firstSection(std::atoi(firstNumberOfFirstRange.data()),
                               std::atoi(secondNumberOfFirstRange.data()));
    const Section secondSection(std::atoi(firstNumberOfSecondRange.data()),
                                std::atoi(secondNumberOfSecondRange.data()));

    if (firstSection.doesOverlapWith(secondSection) ||
        secondSection.doesOverlapWith(firstSection)) {
      ++numberOfPairsOfOverlappingSection;
    }

    it = std::next(endOfLine);
  }
  return numberOfPairsOfOverlappingSection;
}
