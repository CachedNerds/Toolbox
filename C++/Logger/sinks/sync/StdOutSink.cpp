#include "StdOutSink.h"
#include <iostream>

namespace Toolbox::Log::Sinks::Sync
{

void StdOutSink::output (const std::string & message)
{
  this->mut_.lock ();
  std::cout << message;
  this->mut_.unlock ();
}

} // namespace Toolbox::Log::Sinks::Sync