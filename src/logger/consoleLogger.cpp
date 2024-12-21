#include "logger/consoleLogger.hpp"
#include "utils/dateTimeUtils.hpp"

namespace Logger {

ConsoleLogger::ConsoleLogger() {}

void ConsoleLogger::log(const std::string &level, const std::string &message) {
  auto date = DateTimeHelper::getFormattedLocalDateTime();
  std::cout << date << " : [" << level << "] : " << message << std::endl;
}

} // namespace Logger