#ifndef _CONSOLE_SINK_H_
#define _CONSOLE_SINK_H_

#include "BasicSink.h"

#include <string>

namespace Toolbox::Log::Sink
{

using StringSink = BasicSink<std::string>;

class ConsoleSink : public StringSink
{
public:
  // StringSink
  void output (const std::string & output) override;
};

} // namespace Toolbox::Log::Sink

#endif // _CONSOLE_SINK_H_