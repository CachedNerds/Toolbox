#pragma once

#include <Toolbox/Log/Level.h>
#include <Toolbox/Sink/BasicSink.h>
#include <Toolbox/Sink/ThreadSafeSink.h>
#include <Toolbox/Conversion/Stringifiable.h>
#include <memory>

namespace toolbox::log
{

class Logger
{
using StringSink = toolbox::sink::BasicSink<std::string>;
public:
  explicit Logger (std::unique_ptr<StringSink> sink);

  // logs message at default log level
  void log (const std::string & message);
  void log (const Level & level, const std::string & message);
  
  void trace (const std::string & message);
  void debug (const std::string & message);
  void info (const std::string & message);
  void warning (const std::string & message);
  void error (const std::string & message);
  void fatal (const std::string & message);

  Level getThreshold (void) const;
  void setThreshold (const Level & level);

  Level getDefault (void) const;
  void setDefault (const Level & level);

private:
  Level _default;
  Level _threshold;
  std::unique_ptr<StringSink> _sink;

  void logIfAboveThreshold (const Level & level, const std::string & message);
  bool isAboveThreshold (const Level & level) const;
  std::string createLogMessage (const Level & level, const std::string & message) const;
  std::string getCurrentTime (void) const;
};

} // namespace toolbox::log