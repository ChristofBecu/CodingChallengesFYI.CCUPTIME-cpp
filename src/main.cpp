#include "cliArgs/options.hpp"
#include "daemon/daemon.hpp"
#include "daemon/daemonOptions.hpp"
#include "logger/consoleLogger.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  auto options = CliArguments::Options(argc, argv);
  auto logger = std::make_shared<Logger::ConsoleLogger>();

  switch (options.mode) {
  case CliArguments::Options::Mode::Daemon: {
    Daemon::Daemon daemon(Daemon::DaemonOptions::OptionType::START, logger);
    return (EXIT_SUCCESS);
  }
  case CliArguments::Options::Mode::Terminal: {
    std::cout << "Starting as terminal" << std::endl;
    return (EXIT_SUCCESS);
  }
  default: {
    std::cerr << "Unknown mode\n";
    return (EXIT_FAILURE);
  }
  }

  std::cout << "Hello World!" << std::endl;
}