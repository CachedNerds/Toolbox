#include <Toolbox/Log/Logger.h>
#include <Toolbox/Time/Time.h>

#include <memory>

namespace Toolbox::Log
{

Logger::Logger (StringSink sink)
: _default (Level::INFO)
, _threshold (Level::TRACE)
, _sink (std::move (sink))
{
  
}

void Logger::log (const std::string & message)
{
  logIfAboveThreshold (_default, message);
}

void Logger::log (const Level & level, const std::string & message)
{
  logIfAboveThreshold (level, message);
}

void Logger::trace (const std::string & message)
{
  logIfAboveThreshold (Level::TRACE, message);
}

void Logger::debug (const std::string & message)
{
  logIfAboveThreshold (Level::DEBUG, message);
}

void Logger::info (const std::string & message)
{
  logIfAboveThreshold (Level::INFO, message);
}

void Logger::warning (const std::string & message)
{
  logIfAboveThreshold (Level::WARNING, message);
}

void Logger::error (const std::string & message)
{
  logIfAboveThreshold (Level::ERROR, message);
}

void Logger::fatal (const std::string & message)
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

void Logger::logIfAboveThreshold (const Level & level, const std::string & message)
{
  if (isAboveThreshold (level))
    _sink << createLogMessage (level, message);
}

bool Logger::isAboveThreshold (const Level & level) const
{
  return level >= _threshold;
}

std::string Logger::createLogMessage (const Level & level, const std::string & message) const
{
  return levelToString (level) + ": " + message + "\n";
}

std::string Logger::getCurrentTime (void) const
{
  return Time::getCurrentTime();
}

} // namespace Toolbox::Log
