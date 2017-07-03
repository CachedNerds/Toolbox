#include "Logger.h"

#include <ctime>
#include <chrono>

namespace Toolbox::Log
{

Logger::Logger (StringSink & sink)
: _threshold (Level::TRACE)
, _sink (sink)
, _stringVisitor ()
{
  
}

void Logger::log (const Level & level, const String & message) const
{
  logAtLevel (level, message);
}

void Logger::trace (const String & message) const
{
  logAtLevel (Level::TRACE, message);
}

void Logger::debug (const String & message) const
{
  logAtLevel (Level::DEBUG, message);
}

void Logger::info (const String & message) const
{
  logAtLevel (Level::INFO, message);
}

void Logger::warning (const String & message) const
{
  logAtLevel (Level::WARNING, message);
}

void Logger::error (const String & message) const
{
  logAtLevel (Level::ERROR, message);
}

void Logger::fatal (const String & message) const
{
  logAtLevel (Level::FATAL, message);
}

Level Logger::getThreshold (void) const
{
  return _threshold;
}

void Logger::setThreshold (const Level & threshold)
{
  _threshold = threshold;
}

void Logger::logAtLevel (const Level & level, const String & message) const
{
  if (isAboveThreshold (level))
    _sink << createLogMessage (level, message);
}

bool Logger::isAboveThreshold (const Level & level) const
{
  return level >= _threshold;
}

const std::string Logger::createLogMessage (const Level & level, const String & message) const
{
  const std::string timestampField = "timestamp: " + getCurrentTime ();
  const std::string levelField = "level: " + levelToString (level);
  const std::string messageField = "message: " + boost::apply_visitor (_stringVisitor, message);

  return "{" + timestampField + ", " + levelField + ", " + messageField + "}" + "\n";
}

const std::string Logger::getCurrentTime (void) const
{
  std::time_t now = std::chrono::system_clock::to_time_t (std::chrono::system_clock::now ());
  std::string timestamp = std::ctime (&now);
  std::string timestampWithoutNewline = removeTrailingNewline (timestamp);
  return timestampWithoutNewline;
}

const std::string Logger::removeTrailingNewline (const std::string & text) const
{
  return text.substr (0, text.length () - 1);
}

// static string visitor
const std::string Logger::StringVisitor::operator () (const std::string & message) const
{
  return message;
}

const std::string Logger::StringVisitor::operator () (const Stringifiable & message) const
{
  return message.toString ();
}

} // namespace Toolbox::Log