#include "ConsoleSink.h"

#include <iostream>

namespace Toolbox::Log::Sinks::Sync
{

void ConsoleSink::output (const std::string & output)
{
  std::lock_guard<std::mutex> guard(this->_mut);
  std::cout << output;
}

} // namespace Toolbox::Log::Sinks::Sync