#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "Level.h"
#include "sinks/BasicSink.h"
#include "conversions/Stringifiable.h"
#include "conversions/VariantVisitor.h"
#include "conversions/Variant.h"

#include <boost/variant.hpp>

namespace Toolbox::Log
{

class Logger
{
using StringVariant = Conversion::Variant<std::string>;
using String = StringVariant::type;
using StringVisitor = Conversion::VariantVisitor<std::string>;
using StringSink = Sinks::BasicSink<std::string>;
public:
  explicit Logger (StringSink & sink);

  // logs message at default log level
  void log (const String & message) const;
  void log (const Level & level, const String & message) const;
  
  void trace (const String & message) const;
  void debug (const String & message) const;
  void info (const String & message) const;
  void warning (const String & message) const;
  void error (const String & message) const;
  void fatal (const String & message) const;

  Level getThreshold (void) const;
  void setThreshold (const Level & level);

  Level getDefault (void) const;
  void setDefault (const Level & level);

private:
  Level _default;
  Level _threshold;
  StringSink & _sink;
  StringVisitor _stringVisitor;

  void logIfAboveThreshold (const Level & level, const String & message) const;
  bool isAboveThreshold (const Level & level) const;
  const std::string createLogMessage (const Level & level, const String & message) const;
  const std::string getCurrentTime (void) const;
  const std::string removeTrailingNewline (const std::string & text) const;
};

} // namespace Toolbox::Log

#endif // _LOGGER_H_