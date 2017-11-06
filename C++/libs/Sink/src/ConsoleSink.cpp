#include <Toolbox/Sink/ConsoleSink.h>

#include <iostream>

namespace Toolbox::Sink
{

void ConsoleSink::output (const std::string & output)
{
  std::cout << output;
}

} // namespace Toolbox::Sink