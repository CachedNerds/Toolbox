#pragma once

#include <Toolbox/Sink/BasicSink.h>
#include <string>

using toolbox::sink::BasicSink;

namespace toolbox::log::test
{

class Sink : public BasicSink<std::string>
{
public:
  Sink (std::string & resource);

  void output (const std::string & output) override;

private:
  std::string & _resource;
};

} // namespace toolbox::log::test