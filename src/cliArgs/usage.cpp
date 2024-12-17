#include "cliArgs/usage.hpp"

CliArguments::Usage::Usage() {
  usage = "Usage: ";
  usage += "ccuptime <mode> [command] [options]\n";
  usage += "Modes:\n";
  usage += "  daemon\t\tStart as background process\n";
  usage += "  terminal\t\tStart as terminal application\n";
  usage += "Commands:\n";
  usage += "  ccuptime kill\t\tKill background process\n";
  usage += "  ccuptime status\tCheck background process status\n";

  usage += "Options:\n";
  usage += "  -h, --help\t\tShow this help message\n";
  usage += "  -l, --list\t\tList websites to monitor\n";
}

void CliArguments::Usage::showUsage() { std::cout << usage << std::endl; }