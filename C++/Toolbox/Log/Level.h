#pragma once

#include <string>

namespace toolbox::log
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

} // namespace toolbox::log