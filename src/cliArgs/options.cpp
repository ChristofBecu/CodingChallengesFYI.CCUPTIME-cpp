
#include "cliArgs/options.hpp"
#include "cliArgs/usage.hpp"
#include <cstdlib>
#include <getopt.h>

auto usage = CliArguments::Usage();

CliArguments::Options::Options(int argc, char *argv[]) {
  optionsMap.insert({"-h", HELP});
  optionsMap.insert({"--help", HELP});
  optionsMap.insert({"daemon", DAEMONSTART});
  optionsMap.insert({"terminal", TERMINALSTART});
  optionsMap.insert({"kill", DAEMONKILL});
  optionsMap.insert({"status", DAEMONSTATUS});
  optionsMap.insert({"-l", LISTWEBSITES});
  optionsMap.insert({"--list", LISTWEBSITES});

  parseArguments(argc, argv);
}

void CliArguments::Options::parseArguments(int argc, char *argv[]) {
  if (argc < 2) {
    mode = Mode::Terminal;
  }
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];

    if (optionsMap.find(arg) != optionsMap.end()) {
      handleOption(arg);
    } else {
      std::cerr << "Unknown option: " << arg << "\n";
      usage.showUsage();
      exit(EXIT_FAILURE);
    }
  }
}

void CliArguments::Options::handleOption(std::string &arg) {
  switch (optionsMap.at(arg)) {
  case HELP:
    usage.showUsage();
    exit(EXIT_SUCCESS);
  case DAEMONSTART:
    mode = Mode::Daemon;
    break;
  case DAEMONKILL:
    mode = Mode::Daemon;
    break;
  case DAEMONSTATUS:
    mode = Mode::Daemon;
    break;
  case TERMINALSTART:
    mode = Mode::Terminal;
    break;
  case LISTWEBSITES:
    std::cout << "Listing websites\n";
    break;
  }
}

const std::unordered_map<std::string, CliArguments::Options::OptionType> &
CliArguments::Options::getOptionsMap() {
  return optionsMap;
}
