#include "daemon/daemon.hpp"
#include "logger/logger.hpp"
#include "uptime/checker.hpp"
#include <iostream>

namespace Daemon {

Daemon::Daemon(DaemonOptions::OptionType option,
               std::shared_ptr<Logger::Logger> logger)
    : logger(logger) {
  switch (option) {
  case DaemonOptions::OptionType::START: {
    // check if the daemon is already running
    // if not, start the daemon
    logger->log(Logger::LogLevel::INFO, "Starting daemon");
    daemonize();
    // save the pid to a file ??
    // run the uptimechecker loop
    Uptime::Checker checker(logger);
    break;
  }
  case DaemonOptions::OptionType::KILL: {

    kill();
    break;
  }
  case DaemonOptions::OptionType::STATUS: {
    status();
    break;
  }
  }
}

void handleError(const std::string &message) {
  std::cerr << message << ": " << strerror(errno) << "\n";
  exit(EXIT_FAILURE);
}

void closeFileDescriptors(int start) {
  for (int fd = sysconf(_SC_OPEN_MAX); fd >= start; --fd) {
    close(fd);
  }
}

void setupSignals() {
  // prevent accumulation of zombie processes
  if (signal(SIGCHLD, SIG_IGN) == SIG_ERR) {
    handleError("Failed to ignore SIGCHLD");
  }
  // ensure the daemon continues running after closing the terminal where it was
  // started
  if (signal(SIGHUP, SIG_IGN) == SIG_ERR) {
    handleError("Failed to ignore SIGHUP");
  }
}

void Daemon::kill() {
  // kill the daemon
}

void Daemon::status() {
  // check the status of the daemon
}

void redirectFileDescriptors() {
  // standard input, output, error are redirected to /dev/null
  for (int fd = 0; fd <= 2; ++fd) {
    int devNull = open("/dev/null", fd == 0 ? O_RDONLY : O_WRONLY);
    if (devNull == -1) {
      handleError("Failed to open /dev/null");
    }
    if (dup2(devNull, fd) == -1) {
      handleError("Failed to redirect file descriptor");
    }
    close(devNull);
  }
}

void Daemon::daemonize() {
  pid_t pid = fork(); // clone the calling process to create a child process

  if (pid < 0) {
    handleError("Fork failed");
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS); // Exit parent process
  }

  // Child process becomes the calling process
  if (setsid() < 0) {
    handleError("Failed to create a new session");
  }

  setupSignals();

  // Set file permissions
  umask(0);

  // change working directory to root
  if (chdir("/") < 0) {
    handleError("Failed to change working directory to root");
  }

  redirectFileDescriptors();

  // 0, 1, 2 are standard input, output, error,
  // they are now redirected to /dev/null
  closeFileDescriptors(3);
}

} // namespace Daemon