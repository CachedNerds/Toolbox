#pragma once

#include <Toolbox/Sink/BasicSink.h>

#include <string>

using Toolbox::Sink::BasicSink;

namespace Toolbox::Log::Test
{

class Sink : public BasicSink<std::string>
{
public:
  Sink (std::string & resource);

  void output (const std::string & output) override;

private:
  std::string & _resource;
};

} // namespace Toolbox::Log::Test