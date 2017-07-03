#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "Level.h"
#include "sinks/BasicSink.h"
#include "sinks/Stringifiable.h"

#include <string>
#include <boost/variant.hpp>

namespace Toolbox::Log
{

using namespace Sinks;

class Logger
{
using String = boost::variant<const std::string &, const Stringifiable &>;
public:
  Logger (StringSink & sink);

  void log (const Level & level, const String & message) const;
  void trace (const String & message) const;
  void debug (const String & message) const;
  void info (const String & message) const;
  void warning (const String & message) const;
  void error (const String & message) const;
  void fatal (const String & message) const;

  // accessors
  Level getThreshold (void) const;
  void setThreshold (const Level & level);

private:
  // helper classes
  class StringVisitor : public boost::static_visitor<std::string>
  {
  public:
    const std::string operator () (const std::string & message) const;
    const std::string operator () (const Stringifiable & message) const;
  };

  // properties
  Level _threshold;
  StringSink & _sink;
  const StringVisitor _stringVisitor;

    // helper functions
  void logAtLevel (const Level & level, const String & message) const;
  bool isAboveThreshold (const Level & level) const;
  const std::string createLogMessage (const Level & level, const String & message) const;
  const std::string getCurrentTime (void) const;
  const std::string removeTrailingNewline (const std::string & text) const;
};

} // namespace Toolbox::Log

#endif // _LOGGER_H_