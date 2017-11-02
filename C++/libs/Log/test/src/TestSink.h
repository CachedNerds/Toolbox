#ifndef _TEST_SINK_H_
#define _TEST_SINK_H_

#include <Toolbox/Sink/BasicSink.h>

#include <string>

using Toolbox::Sink::BasicSink;

namespace Toolbox::Logger::Test
{

class Sink : public BasicSink<std::string>
{
public:
  Sink (std::string & resource);

  void output (const std::string & output) override;

private:
  std::string & _resource;
};

} // namespace Toolbox::Logger::Test

#endif // _TEST_SINK_H_