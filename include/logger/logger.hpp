#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <array>
#include <string>

namespace Logger {

enum class LogLevel { INFO, WARNING, ERROR, CRITICAL, FATAL, COUNT };

const std::array<std::string, static_cast<std::size_t>(LogLevel::COUNT)>
    logLevelNames = {"INFO", "WARNING", "ERROR", "CRITICAL", "FATAL"};

std::string logLevelToString(LogLevel level);
std::string logStringBuilder(LogLevel level, const std::string &message);

class Logger {
public:
  virtual void log(LogLevel level, const std::string &message) = 0;

  virtual ~Logger() = default;

private:
  std::string logFile;
};

} // namespace Logger

#endif // LOGGER_HPP