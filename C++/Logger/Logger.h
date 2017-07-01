#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "Severity.h"
#include "sinks/BasicSink.h"
#include "sinks/Output.h"

#include <string>
#include <iostream>

namespace Toolbox::Log
{

using namespace Sinks;

template <typename OutputType>
class Logger
{

public:
  Logger<OutputType> (BasicSink<OutputType> & sink);

  void log (const Severity::Level & level, const OutputType & output) const;
  void log (const Severity::Level & level, const Output<OutputType> & output) const;

  void trace (const OutputType & output) const;
  void trace (const Output<OutputType> & output) const;

  void debug (const OutputType & output) const;
  void debug (const Output<OutputType> & output) const;

  void info (const OutputType & output) const;
  void info (const Output<OutputType> & output) const;

  void warning (const OutputType & output) const;
  void warning (const Output<OutputType> & output) const;

  void error (const OutputType & output) const;
  void error (const Output<OutputType> & output) const;

  void fatal (const OutputType & output) const;
  void fatal (const Output<OutputType> & output) const;

  void setThreshold (const Severity::Level & threshold);
  Severity::Level getThreshold (void) const;

private:
  std::string getCurrentTime (void) const;

  BasicSink<OutputType> & _sink;
  Severity::Level _threshold = Severity::Level::TRACE;
};

#include "Logger.cpp"

} // namespace Toolbox::Log

#endif // _LOGGER_H_