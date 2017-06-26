#include "SyncStdOutSink.h"
#include <iostream>

namespace Toolbox::Log::Sinks
{

void SyncStdOutSink::output (const std::string & message)
{
  this->mut_.lock ();
  std::cout << message;
  this->mut_.unlock ();
}

} // namespace Toolbox::Log::Sinks