#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "Severity.h"
#include "sinks/Sink.h"
#include "sinks/sync/ConsoleSink.h"

#include <string>
#include <iostream>

namespace Toolbox::Log
{

using namespace Sinks;

class Logger
{
public:
  Logger (Sink & sink);

  void log (const Severity::Level & level, const std::string & message) const;
  void trace (const std::string & message) const;
  void debug (const std::string & message) const;
  void info (const std::string & message) const;
  void warning (const std::string & message) const;
  void error (const std::string & message) const;
  void fatal (const std::string & message) const;

  void setThreshold (const Severity::Level & threshold);

private:
  Sink & _sink;
  Severity::Level _threshold = Severity::Level::TRACE;
};

} // namespace Toolbox::Log

#endif // _LOGGER_H_