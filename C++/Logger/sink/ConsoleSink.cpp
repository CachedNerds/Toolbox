#include "ConsoleSink.h"

#include <iostream>

namespace Toolbox::Log::Sink
{

void ConsoleSink::output (const std::string & output)
{
  std::cout << output;
}

} // namespace Toolbox::Log::Sink