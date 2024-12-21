#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

namespace Logger {

class Logger {
public:
  virtual void log(const std::string &level, const std::string &message) = 0;
  virtual ~Logger() = default;

private:
  std::string logFile;
};

} // namespace Logger

#endif // LOGGER_HPP