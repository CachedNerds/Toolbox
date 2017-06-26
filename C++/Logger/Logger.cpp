#include "Logger.h"
#include <sstream>

namespace Toolbox::Log
{

Logger::Logger (Sink & sink)
: sink_ (sink)
{}

void Logger::log (const Severity::Level & level, const std::string & message)
{
  if (level >= this->threshold_)
  {
    std::stringstream ss;
    ss << Severity::toString (level) << ": " << message << "\n";
    this->sink_.output (ss.str ());
  }
}

void Logger::setThreshold (const Severity::Level & threshold)
{
  this->threshold_ = threshold;
}

} // Toolbox::Log