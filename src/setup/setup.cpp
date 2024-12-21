#include "setup/setup.hpp"
#include "logger/consoleLogger.hpp"
#include "logger/fileLogger.hpp"
#include <memory>

Setup::Setup::Setup() {
  CreateDirectories();
  CreateFiles();
  SetupLoggers();
}

void Setup::Setup::CreateDirectories() {
  // create directories
}

void Setup::Setup::CreateFiles() {
  // create files
}

void Setup::Setup::SetupLoggers() {
  std::cout << "Setting up loggers" << std::endl;
  Setup::Setup::consoleLogger = std::make_shared<Logger::ConsoleLogger>();
  Setup::Setup::fileLogger = std::make_shared<Logger::FileLogger>("log.txt");
}
