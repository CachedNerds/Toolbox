#include "Logger.h"

#include <ctime>
#include <chrono>

namespace Toolbox::Log
{

Logger::Logger (StringSink & sink)
: _default (Level::INFO)
, _threshold (Level::TRACE)
, _sink (sink)
{
  
}

void Logger::log (const String::Variant & message) const
{
  logIfAboveThreshold (_default, message);
}

void Logger::log (const Level & level, const String::Variant & message) const
{
  logIfAboveThreshold (level, message);
}

void Logger::trace (const String::Variant & message) const
{
  logIfAboveThreshold (Level::TRACE, message);
}

void Logger::debug (const String::Variant & message) const
{
  logIfAboveThreshold (Level::DEBUG, message);
}

void Logger::info (const String::Variant & message) const
{
  logIfAboveThreshold (Level::INFO, message);
}

void Logger::warning (const String::Variant & message) const
{
  logIfAboveThreshold (Level::WARNING, message);
}

void Logger::error (const String::Variant & message) const
{
  logIfAboveThreshold (Level::ERROR, message);
}

void Logger::fatal (const String::Variant & message) const
{
  logIfAboveThreshold (Level::FATAL, message);
}

Level Logger::getThreshold (void) const
{
  return _threshold;
}

void Logger::setThreshold (const Level & threshold)
{
  _threshold = threshold;
}

Level Logger::getDefault (void) const
{
  return _default;
}

void Logger::setDefault (const Level & level)
{
  _default = level;
}

void Logger::logIfAboveThreshold (const Level & level, const String::Variant & message) const
{
  if (isAboveThreshold (level))
    _sink << createLogMessage (level, message);
}

bool Logger::isAboveThreshold (const Level & level) const
{
  return level >= _threshold;
}

const std::string Logger::createLogMessage (const Level & level, const String::Variant & message) const
{
  return levelToString (level) + ": " + String::get (message) + "\n";
}

const std::string Logger::getCurrentTime (void) const
{
  std::time_t now = std::chrono::system_clock::to_time_t (std::chrono::system_clock::now ());
  std::string timestamp = std::ctime (&now);
  return removeTrailingNewline (timestamp);
}

const std::string Logger::removeTrailingNewline (const std::string & text) const
{
  return text.substr (0, text.length () - 1);
}

} // namespace Toolbox::Log