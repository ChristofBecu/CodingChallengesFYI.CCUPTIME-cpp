#include "logger/fileLogger.hpp"
#include "logger/logger.hpp"
#include "utils/dateTimeUtils.hpp"
#include <fstream>
#include <iostream>

namespace Logger {

FileLogger::FileLogger(const std::string &logFile) : logFile(logFile) {}

void FileLogger::log(LogLevel level, const std::string &message) {
  std::ofstream file(logFile, std::ios::app);
  file << logStringBuilder(level, message) << std::endl;
  file.close();
}

} // namespace Logger
