#ifndef USAGE_HPP
#define USAGE_HPP

#include <iostream>
#include <string>

namespace CliArguments {
class Usage {
private:
  std::string usage;

public:
  Usage();
  void showUsage();
};
} // namespace CliArguments

#endif