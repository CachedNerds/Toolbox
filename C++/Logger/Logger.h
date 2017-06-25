#ifndef LOGGER_H
#define LOGGER_H

#include "Severity.h"
#include <string>
#include <iostream>

class Logger
{
public:
  Logger (void);

  void log (Severity::Level level, const std::string& message);
  void setThreshold (Severity::Level threshold);
private:
  std::ostream os_;
  Severity::Level threshold_ = Severity::Level::TRACE;
};

#endif // LOGGER_H