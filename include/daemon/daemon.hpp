#ifndef DAEMON_HPP
#define DAEMON_HPP

#include "daemonOptions.hpp"
#include <csignal>
#include <cstdlib>
#include <cstring>
#include <dirent.h>
#include <fcntl.h>
#include <iostream>
#include <sched.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

namespace Daemon {

class Daemon {

public:
  Daemon(DaemonOptions::OptionType option =
             DaemonOptions::OptionType::START); // default start
  void kill();
  void status();

private:
  void daemonize();
};

} // namespace Daemon

#endif // DAEMON_HPP