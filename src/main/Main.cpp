#include <format>

#include "Util.hpp"

namespace rde {

int add(int a, int b) {
  reddit_logger(std::format("Adding {} + {}", a, b).c_str());
  return a + b;
}

} // namespace rde
