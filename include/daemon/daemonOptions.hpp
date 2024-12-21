#ifndef DAEMONOPTIONS_HPP
#define DAEMONOPTIONS_HPP

namespace Daemon {

class DaemonOptions {

public:
  enum class OptionType { START, KILL, STATUS };
};
} // namespace Daemon

#endif // DAEMONOPTIONS_HPP
