#include "Logger.h"

#include <ctime>

namespace Toolbox::Log
{

Logger::Logger (Sink & sink)
: _sink (sink)
{
  
}

void Logger::log (const Severity::Level & level, const std::string & message) const
{
  if (level >= this->_threshold)
  {
    std::string timestamp = this->getCurrentTime ();
    this->_sink << "{" << "timestamp: " << timestamp << ", "
                       << "level: " << Severity::toString (level) << ", "
                       << "message: " << message << "}\n";
  }
}

void Logger::trace (const std::string & message) const
{
  this->log (Severity::Level::TRACE, message);
}

void Logger::debug (const std::string & message) const
{
  this->log (Severity::Level::DEBUG, message);
}

void Logger::info (const std::string & message) const
{
  this->log (Severity::Level::INFO, message);
}

void Logger::warning (const std::string & message) const
{
  this->log (Severity::Level::WARNING, message);
}

void Logger::error (const std::string & message) const
{
  this->log (Severity::Level::ERROR, message);
}

void Logger::fatal (const std::string & message) const
{
  this->log (Severity::Level::FATAL, message);
}

void Logger::setThreshold (const Severity::Level & threshold)
{
  this->_threshold = threshold;
}

Severity::Level Logger::getThreshold (void) const
{
  return this->_threshold;
}

std::string Logger::getCurrentTime (void) const
{
  std::time_t now = std::chrono::system_clock::to_time_t (std::chrono::system_clock::now ());
  std::string timestamp (std::ctime (&now));
  return timestamp.substr (0, timestamp.length () - 1);
}

} // Toolbox::Log