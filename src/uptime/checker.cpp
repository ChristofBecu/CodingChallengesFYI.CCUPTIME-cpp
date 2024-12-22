#include "uptime/checker.hpp"
#include <chrono>
#include <thread>

namespace Uptime {

Checker::Checker(std::shared_ptr<Logger::Logger> logger) : logger(logger) {
  // get the type of the logger (console or file)
  logger->log(Logger::LogLevel::INFO, "Starting uptime checker");

  checkUptime();
}

void Checker::checkUptime() {
  while (true) {
    logger->log(Logger::LogLevel::INFO, "Checking uptime");
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
}

} // namespace Uptime