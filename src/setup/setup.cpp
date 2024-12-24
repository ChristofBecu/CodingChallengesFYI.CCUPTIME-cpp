#include "setup/setup.hpp"
#include <cerrno>

Setup::Setup::Setup() {
  Setup::homeDir = std::string(getenv("HOME"));
  Setup::workDir = homeDir + "/.ccuptime";
  Setup::logPath = workDir + "/ccuptime.log";
  Setup::configPath = workDir + "/config.yaml";
  CreateDirectories();
  CreateFiles();
  SetupLoggers();
}

void Setup::Setup::CreateDirectories() {
  if (!std::filesystem::exists(Setup::workDir)) {
    std::filesystem::create_directory(Setup::workDir);
  }
}

void Setup::Setup::CreateFiles() {
  if (!std::filesystem::exists(Setup::logPath)) {
    std::ofstream file(Setup::logPath);
    file.close();
  }
  if (!std::filesystem::exists(Setup::configPath)) {
    std::ofstream file(Setup::configPath);
    file.close();
  }
}

void Setup::Setup::SetupLoggers() {
  Setup::Setup::consoleLogger = std::make_shared<Logger::ConsoleLogger>();
  Setup::Setup::fileLogger =
      std::make_shared<Logger::FileLogger>(Setup::logPath);
}
