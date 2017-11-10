#pragma once

#include <Toolbox/Sink/BasicSink.h>
#include <Toolbox/Sink/ThreadSafeSink.h>
#include <string>

using toolbox::sink::BasicSink;

namespace toolbox::sink::test
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

} // namespace toolbox::sink::test