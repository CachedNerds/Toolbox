#include "Sink.h"

namespace Toolbox::Log::Sinks
{

Sink & Sink::operator << (const std::string & message)
{
  this->output (message);
  return *this;
}

} // namespace Toolbox::Log::Sinks