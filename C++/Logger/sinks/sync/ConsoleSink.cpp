#include "ConsoleSink.h"

#include <iostream>

namespace Toolbox::Log::Sinks::Sync
{

void ConsoleSink::output (const std::string & message)
{
  std::lock_guard<std::mutex> guard(this->_mut);
  std::cout << message;
}

} // namespace Toolbox::Log::Sinks::Sync