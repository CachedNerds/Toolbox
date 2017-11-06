#pragma once

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