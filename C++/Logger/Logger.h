#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "Level.h"
#include "sinks/BasicSink.h"
#include "outputs/Stringifiable.h"
#include "outputs/OutputVisitor.h"

#include <string>
#include <boost/variant.hpp>

namespace Toolbox::Log
{

using namespace Sinks;
using Outputs::Stringifiable;
using Outputs::OutputVisitor;

class Logger
{
using String = boost::variant<const std::string &, const Stringifiable &>;
using StringVisitor = OutputVisitor<std::string>;
public:
  Logger (StringSink & sink);

  void log (const String & message) const;
  void trace (const String & message) const;
  void debug (const String & message) const;
  void info (const String & message) const;
  void warning (const String & message) const;
  void error (const String & message) const;
  void fatal (const String & message) const;

  // accessors
  Level getThreshold (void) const;
  void setThreshold (const Level & level);

  Level getDefault (void) const;
  void setDefault (const Level & level);

private:
  // properties
  Level _default;
  Level _threshold;
  StringSink & _sink;
  const StringVisitor _stringVisitor;

    // helper functions
  void logIfAboveThreshold (const Level & level, const String & message) const;
  bool isAboveThreshold (const Level & level) const;
  const std::string createLogMessage (const Level & level, const String & message) const;
  const std::string getCurrentTime (void) const;
  const std::string removeTrailingNewline (const std::string & text) const;
};

} // namespace Toolbox::Log

#endif // _LOGGER_H_