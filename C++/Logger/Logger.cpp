#include "Logger.h"
#include <sstream>

namespace Toolbox::Log
{

Logger::Logger (Sink & sink)
: sink_ (sink)
{}

void Logger::log (const Severity::Level & level, const std::string & message) const
{
  if (level >= this->threshold_)
  {
    std::stringstream ss;
    ss << Severity::toString (level) << ": " << message << "\n";
    this->sink_.output (ss.str ());
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
  this->threshold_ = threshold;
}

} // Toolbox::Log