#include <print>

namespace rde {

void reddit_logger(const char* msg) {
  std::println("reddit-logger: {}", msg);
}

} // namespace rde
