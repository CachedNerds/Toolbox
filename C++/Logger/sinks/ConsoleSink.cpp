#include "ConsoleSink.h"

#include <iostream>

namespace Toolbox::Log::Sinks
{

void ConsoleSink::output (const std::string & output)
{
  std::cout << output;
}

} // namespace Toolbox::Log::Sinks