#ifndef FILELOGGER_HPP
#define FILELOGGER_HPP

#include "logger.hpp"

namespace Logger {

class FileLogger : public Logger {
public:
  FileLogger(const std::string &logFile);
  void log(const std::string &level, const std::string &message) override;

private:
  std::string logFile;
};

} // namespace Logger

#endif // FILELOGGER_HPP