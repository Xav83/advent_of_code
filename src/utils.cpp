#include "utils.hpp"
#include <fstream>

std::string getFileContext(const std::string_view filename) {
  std::ifstream file(filename.data());
  return std::string((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
}
