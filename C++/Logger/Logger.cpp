#include "Logger.h"

  Logger::Logger (void)
  : os_ (std::cout.rdbuf ())
  {
  }

  void Logger::log (Severity::Level level, const std::string& message)
  {
    if (level >= this->threshold_)
    {
      this->os_ << Severity::toString (level) << ": " << message << "\n";
    }
  }

  void Logger::setThreshold (Severity::Level threshold)
  {
    this->threshold_ = threshold;
  }