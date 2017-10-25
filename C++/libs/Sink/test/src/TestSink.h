#ifndef _TEST_SINK_H_
#define _TEST_SINK_H_

#include <Toolbox/Sink/BasicSink.h>
#include <Toolbox/Sink/ThreadSafeSink.h>

#include <string>

using Toolbox::Sink::BasicSink;

namespace Toolbox::Sink::Test
{

class Sink : public BasicSink<std::string>
{
public:
  Sink (void);
  Sink (const std::string & message);

  void output (const std::string & message) override;

  const std::string getMessage (void) const;

private:
  std::string _message;
};

class SyncSink : public ThreadSafeSink<std::string>
{
public:
  void output (const std::string & message) override;
  
  const std::string getMessage (void) const;

private:
  std::string _message;
};

} // namespace Toolbox::Sink::Test

#endif // _TEST_SINK_H_