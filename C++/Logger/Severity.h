#ifndef SEVERITY_H
#define SEVERITY_H

namespace Toolbox::Log::Severity
{

enum Level
{
  TRACE,
  DEBUG,
  INFO,
  WARNING,
  ERROR,
  FATAL
};

const char * toString (Level level);

} // namespace Toolbox::Log::Severity

#endif // SEVERITY_H