#ifndef SEVERITY_H
#define SEVERITY_H

namespace Severity
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

const char * toString (Level severity);
}
#endif // SEVERITY_H