#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <string>

namespace Toolbox::Log
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

const std::string levelToString (const Level & level);

} // namespace Toolbox::Log

#endif // _LEVEL_H_