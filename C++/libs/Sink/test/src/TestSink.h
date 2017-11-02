#ifndef _TEST_SINK_H_
#define _TEST_SINK_H_

#include <Toolbox/Sink/BasicSink.h>
#include <Toolbox/Sink/ThreadSafeSink.h>

#include <string>
#include <sstream>

using Toolbox::Sink::BasicSink;

namespace Toolbox::Sink::Test
{

class Sink : public BasicSink<std::string>
{
public:
  Sink (std::string & resource);

protected:
  void output (const std::string & output) override;

private:
  std::string & _resource;
};

class SafeSink : public ThreadSafeSink<std::string>
{
public:
  SafeSink (std::string & resource);

protected:
  void output (const std::string & output) override;

private:
  std::string & _resource;
};

} // namespace Toolbox::Sink::Test

#endif // _TEST_SINK_H_