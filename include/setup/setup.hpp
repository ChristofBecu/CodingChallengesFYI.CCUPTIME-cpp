#ifndef SETUP_HPP
#define SETUP_HPP

#include "logger/consoleLogger.hpp"
#include "logger/fileLogger.hpp"
#include <memory>
#include <string>

namespace Setup {

class Setup {
public:
  Setup();
  std::shared_ptr<Logger::FileLogger> fileLogger;
  std::shared_ptr<Logger::ConsoleLogger> consoleLogger;
  const std::string home = std::string(getenv("HOME"));

private:
  void CreateDirectories();
  void CreateFiles();
  void SetupLoggers();
};

} // namespace Setup

#endif // SETUP_HPP