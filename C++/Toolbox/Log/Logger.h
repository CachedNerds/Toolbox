#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <Toolbox/Log/Level.h>
#include <Toolbox/Sink/BasicSink.h>
#include <Toolbox/Conversion/Stringifiable.h>

namespace Toolbox::Log
{

class Logger
{
using StringSink = Sink::BasicSink<std::string>;
public:
  explicit Logger (StringSink & sink);

  // logs message at default log level
  void log (const std::string & message) const;
  void log (const Level & level, const std::string & message) const;
  
  void trace (const std::string & message) const;
  void debug (const std::string & message) const;
  void info (const std::string & message) const;
  void warning (const std::string & message) const;
  void error (const std::string & message) const;
  void fatal (const std::string & message) const;

  Level getThreshold (void) const;
  void setThreshold (const Level & level);

  Level getDefault (void) const;
  void setDefault (const Level & level);

private:
  Level _default;
  Level _threshold;
  StringSink & _sink;

  void logIfAboveThreshold (const Level & level, const std::string & message) const;
  bool isAboveThreshold (const Level & level) const;
  const std::string createLogMessage (const Level & level, const std::string & message) const;
  const std::string getCurrentTime (void) const;
};

} // namespace Toolbox::Log

#endif // _LOGGER_H_