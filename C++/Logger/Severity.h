#ifndef _SEVERITY_H_
#define _SEVERITY_H_

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

#endif // _SEVERITY_H_