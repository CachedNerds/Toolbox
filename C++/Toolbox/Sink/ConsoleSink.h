#pragma once

#include <Toolbox/Sink/ThreadSafeSink.h>
#include <string>

namespace toolbox::sink
{

class ConsoleSink : public ThreadSafeSink<std::string>
{
public:
  void output (const std::string & output) override;
};

} // namespace toolbox::sink