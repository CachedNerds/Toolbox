#include <Toolbox/Sink/ConsoleSink.h>
#include <iostream>

namespace toolbox::sink
{

void ConsoleSink::output (const std::string & output)
{
  std::cout << output;
}

} // namespace toolbox::sink