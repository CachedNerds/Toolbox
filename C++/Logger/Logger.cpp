#include "Logger.h"

namespace Toolbox::Log
{

Logger::Logger (Sink & sink)
: _sink (sink)
{
  
}

void Logger::log (const Severity::Level & level, const std::string & message) const
{
  if (level >= this->_threshold)
    this->_sink << Severity::toString (level) << ": " << message << "\n";
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

} // Toolbox::Log