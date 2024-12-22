#ifndef CONSOLELOGGER_HPP
#define CONSOLELOGGER_HPP

#include "logger.hpp"
#include <iostream>

namespace Logger {

class ConsoleLogger : public Logger {
public:
  ConsoleLogger();
  void log(LogLevel level, const std::string &message) override;
};

} // namespace Logger

#endif // CONSOLELOGGER_HPP