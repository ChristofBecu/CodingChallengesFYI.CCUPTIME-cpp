#ifndef DATETIMEHELPER_HPP
#define DATETIMEHELPER_HPP

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

class DateTimeHelper {
public:
  static std::string getFormattedLocalDateTime();
};

#endif // DATETIMEHELPER_H
