#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include <unordered_map>

namespace CliArguments {

class Options {
private:
  enum OptionType {
    HELP,
    DAEMONSTART,
    DAEMONKILL,
    DAEMONSTATUS,
    TERMINALSTART,
    LISTWEBSITES
  };
  std::unordered_map<std::string, OptionType> optionsMap;
  void handleOption(std::string &arg);

public:
  Options(int argc, char *argv[]);

  void parseArguments(int argc, char *argv[]);
  const std::unordered_map<std::string, OptionType> &getOptionsMap();

  enum class Mode { Daemon, Terminal, Unknown };
  Mode mode;
};
} // namespace CliArguments

#endif