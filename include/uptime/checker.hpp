#ifndef CHECKER_HPP
#define CHECKER_HPP

#include "logger/logger.hpp"
#include <memory>

namespace Uptime {

class Checker {

public:
  Checker(std::shared_ptr<Logger::Logger> logger);
  void checkUptime();

private:

    std::shared_ptr<Logger::Logger> logger;
    };
    
    } // namespace Uptime

#endif // CHECKER_HPP