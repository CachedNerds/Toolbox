#ifndef LOGGER_H
#define LOGGER_H

#include "Severity.h"
#include "Sink.h"
#include "SyncStdOutSink.h"
#include <string>
#include <iostream>

namespace Toolbox::Log
{

using namespace Sinks;

class Logger
{
public:
  Logger (Sink & sink);

  void log (const Severity::Level & level, const std::string & message);
  void setThreshold (const Severity::Level & threshold);

private:
  Sink & sink_;
  Severity::Level threshold_ = Severity::Level::TRACE;
};

} // namespace Toolbox::Log

#endif // LOGGER_H