#include "logger/fileLogger.hpp"
#include <fstream>
#include <iostream>

namespace Logger {

FileLogger::FileLogger(const std::string &logFile) : logFile(logFile) {}

void FileLogger::log(const std::string &level, const std::string &message) {
  std::ofstream file(logFile, std::ios::app);
  file << level << " : " << message << std::endl;
  file.close();
}

} // namespace Logger
