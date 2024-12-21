#include "logger/consoleLogger.hpp"

namespace Logger {

ConsoleLogger::ConsoleLogger() {}

void ConsoleLogger::log(const std::string &message) {
  std::cout << message << std::endl;
}

} // namespace Logger   