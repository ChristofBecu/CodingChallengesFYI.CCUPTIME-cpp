#ifndef SETUP_HPP
#define SETUP_HPP

#include "logger/consoleLogger.hpp"
#include "logger/fileLogger.hpp"
#include <filesystem>
#include <fstream>
#include <memory>
#include <string>

namespace Setup {

class Setup {

public:
  Setup();
  std::shared_ptr<Logger::FileLogger> fileLogger;
  std::shared_ptr<Logger::ConsoleLogger> consoleLogger;
  std::string workDir;
  std::string logPath;
  std::string configPath;

private:
  std::string homeDir;
  void CreateDirectories();
  void CreateFiles();
  void SetupLoggers();
};

} // namespace Setup

#endif // SETUP_HPP