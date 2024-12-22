#include "logger/consoleLogger.hpp"
#include "logger/logger.hpp"
#include "utils/dateTimeUtils.hpp"

namespace Logger {
ConsoleLogger::ConsoleLogger() {}

void ConsoleLogger::log(LogLevel level, const std::string &message) {
  std::cout << logStringBuilder(level, message) << std::endl;
}

} // namespace Logger