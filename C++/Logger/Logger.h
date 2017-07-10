#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "Level.h"
#include "sink/BasicSink.h"
#include "conversion/Stringifiable.h"
#include "conversion/Result.h"

namespace Toolbox::Log
{

class Logger
{
using String = Conversion::Result<std::string>;
using StringSink = Sink::BasicSink<std::string>;
public:
  explicit Logger (StringSink & sink);

  // logs message at default log level
  void log (const String::Variant & message) const;
  void log (const Level & level, const String::Variant & message) const;
  
  void trace (const String::Variant & message) const;
  void debug (const String::Variant & message) const;
  void info (const String::Variant & message) const;
  void warning (const String::Variant & message) const;
  void error (const String::Variant & message) const;
  void fatal (const String::Variant & message) const;

  Level getThreshold (void) const;
  void setThreshold (const Level & level);

  Level getDefault (void) const;
  void setDefault (const Level & level);

private:
  Level _default;
  Level _threshold;
  StringSink & _sink;

  void logIfAboveThreshold (const Level & level, const String::Variant & message) const;
  bool isAboveThreshold (const Level & level) const;
  const std::string createLogMessage (const Level & level, const String::Variant & message) const;
  const std::string getCurrentTime (void) const;
  const std::string removeTrailingNewline (const std::string & text) const;
};

} // namespace Toolbox::Log

#endif // _LOGGER_H_