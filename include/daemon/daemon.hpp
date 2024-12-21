#ifndef DAEMON_HPP
#define DAEMON_HPP

#include "daemonOptions.hpp"
#include "logger/logger.hpp"
#include <csignal>
#include <cstdlib>
#include <cstring>
#include <dirent.h>
#include <fcntl.h>
#include <memory>
#include <sched.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

namespace Daemon {

class Daemon {
  std::shared_ptr<Logger::Logger> logger;

public:
  Daemon(DaemonOptions::OptionType option = DaemonOptions::OptionType::START,
         std::shared_ptr<Logger::Logger> logger = nullptr);

private:
  void kill();
  void status();
  void daemonize();
};

} // namespace Daemon

#endif // DAEMON_HPP
