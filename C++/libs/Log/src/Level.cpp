#include <Toolbox/Log/Level.h>

namespace toolbox::log
{

const std::string levelToString (const Level & level)
{
  switch (level)
  {
    case Level::TRACE: return "TRACE";
    case Level::DEBUG: return "DEBUG";
    case Level::INFO: return "INFO";
    case Level::WARNING: return "WARNING";
    case Level::ERROR: return "ERROR";
    case Level::FATAL: return "FATAL";
    default: return "NONE";
  }
}

} // namespace toolbox::log