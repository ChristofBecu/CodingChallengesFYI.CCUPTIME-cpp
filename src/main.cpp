#include "cliArgs/options.hpp"
#include "daemon/daemon.hpp"
#include "daemon/daemonOptions.hpp"
#include "setup/setup.hpp"
#include <cstdlib>
#include <iostream>
int main(int argc, char *argv[]) {
  auto options = CliArguments::Options(argc, argv);

  Setup::Setup setup;

  switch (options.mode) {
  case CliArguments::Options::Mode::Daemon: {
    Daemon::Daemon daemon(Daemon::DaemonOptions::OptionType::START,
                          setup.consoleLogger);
    return (EXIT_SUCCESS);
  }
  case CliArguments::Options::Mode::Terminal: {
    setup.consoleLogger->log("INFO", "Starting as terminal");
    return (EXIT_SUCCESS);
  }
  default: {
    setup.consoleLogger->log("ERROR", "Unknown mode");
    std::cerr << "Unknown mode\n";
    return (EXIT_FAILURE);
  }
  }

  std::cout << "Hello World!" << std::endl;
}