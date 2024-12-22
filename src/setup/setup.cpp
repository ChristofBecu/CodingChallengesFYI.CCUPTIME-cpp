#include "setup/setup.hpp"

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
  std::cout << Setup::workDir << "\n";
  if (!std::filesystem::exists(Setup::workDir)) {
    std::cout << "Creating work directory\n";
    std::filesystem::create_directory(Setup::workDir);
  }
}

void Setup::Setup::CreateFiles() {
  std::cout << Setup::logPath << "\n";
  if (!std::filesystem::exists(Setup::logPath)) {
    std::cout << "Creating log file\n";
    std::ofstream file(Setup::logPath);
    file.close();
  }
  if (!std::filesystem::exists(Setup::configPath)) {
    std::cout << "Creating config file\n";
    std::ofstream file(Setup::configPath);
    file.close();
  }
}

void Setup::Setup::SetupLoggers() {
  Setup::Setup::consoleLogger = std::make_shared<Logger::ConsoleLogger>();
  Setup::Setup::fileLogger =
      std::make_shared<Logger::FileLogger>(Setup::logPath);
}
