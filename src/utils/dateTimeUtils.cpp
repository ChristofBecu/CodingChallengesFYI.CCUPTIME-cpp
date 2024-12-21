#include "utils/dateTimeUtils.hpp"

std::string DateTimeHelper::getFormattedLocalDateTime() {
  // Get current time_point
  auto now = std::chrono::system_clock::now();

  // Convert time_point to time_t for local time conversion
  std::time_t now_c = std::chrono::system_clock::to_time_t(now);

  // Convert time_t to tm structure for local time representation
  std::tm local_tm = *std::localtime(&now_c);

  // Format tm structure to string
  std::stringstream oss;
  oss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
  return oss.str();
}