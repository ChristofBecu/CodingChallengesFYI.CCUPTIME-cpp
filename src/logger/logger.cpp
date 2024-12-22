#include "logger/logger.hpp"
#include "utils/dateTimeUtils.hpp"

namespace Logger {

std::string logLevelToString(LogLevel level) {
  return logLevelNames[static_cast<std::size_t>(level)];
}

std::string logStringBuilder(LogLevel level, const std::string &message) {
  auto date = DateTimeHelper::getFormattedLocalDateTime();
  return date + " : [" + logLevelToString(level) + "] : " + message;
}

} // namespace Logger