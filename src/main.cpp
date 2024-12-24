#include "cliArgs/options.hpp"
#include "daemon/daemon.hpp"
#include "daemon/daemonOptions.hpp"
#include "logger/logger.hpp"
#include "setup/setup.hpp"
#include "uptime/checker.hpp"
#include <cerrno>
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  auto options = CliArguments::Options(argc, argv);

  Setup::Setup setup;

  switch (options.mode) {
  case CliArguments::Options::Mode::Daemon: {
    Daemon::Daemon daemon(Daemon::DaemonOptions::OptionType::START,
                          setup.fileLogger);
    return (EXIT_SUCCESS);
  }
  case CliArguments::Options::Mode::Terminal: {
    setup.consoleLogger->log(Logger::LogLevel::INFO, "Starting as terminal");
    Uptime::Checker checker(setup.consoleLogger);

    return (EXIT_SUCCESS);
  }
  case CliArguments::Options::Mode::Kill: {
    Daemon::Daemon daemon(Daemon::DaemonOptions::OptionType::KILL,
                          setup.consoleLogger);
    return (EXIT_SUCCESS);
  }
  case CliArguments::Options::Mode::Status: {
    Daemon::Daemon daemon(Daemon::DaemonOptions::OptionType::STATUS,
                          setup.consoleLogger);
    return (EXIT_SUCCESS);
  }
  case CliArguments::Options::Mode::List: {
    setup.consoleLogger->log(Logger::LogLevel::INFO, "Listing websites");
    return (EXIT_SUCCESS);
  }
  default: {
    setup.consoleLogger->log(Logger::LogLevel::FATAL, "Unknown mode");
    std::cerr << "Unknown mode\n";
    return (EXIT_FAILURE);
  }
  }
}