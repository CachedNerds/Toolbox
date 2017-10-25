#ifndef _TEST_SINK_H_
#define _TEST_SINK_H_

#include <Toolbox/Sink/BasicSink.h>

#include <string>

using Toolbox::Sink::BasicSink;

class TestSink : public BasicSink<std::string>
{
public:
  void output (const std::string & message) override;

  const std::string getMessage (void) const;

private:
  std::string _message;
};

#endif // _TEST_SINK_H_