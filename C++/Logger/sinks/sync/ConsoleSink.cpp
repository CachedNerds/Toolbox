#include "ConsoleSink.h"

#include <iostream>

namespace Toolbox::Log::Sinks::Sync
{

void ConsoleSink::output (const std::string & message)
{
  this->_mut.lock ();
  std::cout << message;
  this->_mut.unlock ();
}

} // namespace Toolbox::Log::Sinks::Sync