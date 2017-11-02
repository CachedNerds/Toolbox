#ifndef _CONSOLE_SINK_H_
#define _CONSOLE_SINK_H_

#include <Toolbox/Sink/ThreadSafeSink.h>

#include <string>

namespace Toolbox::Sink
{

class ConsoleSink : public ThreadSafeSink<std::string>
{
public:
  void output (const std::string & output) override;
};

} // namespace Toolbox::Sink

#endif // _CONSOLE_SINK_H_