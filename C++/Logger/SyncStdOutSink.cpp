#include "SyncStdOutSink.h"
#include <iostream>

namespace Toolbox::Log::Sinks
{

void SyncStdOutSink::output (const std::string & value)
{
  this->mut_.lock ();
  std::cout << value;
  this->mut_.unlock ();
}

} // namespace Toolbox::Log::Sinks