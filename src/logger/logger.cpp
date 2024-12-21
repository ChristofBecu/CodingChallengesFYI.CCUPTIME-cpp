#include "logger/logger.hpp"

namespace Logger {

class ConsoleLogger : public Logger {
public:
  void log(const std::string &message) override;
};

} // namespace Logger



