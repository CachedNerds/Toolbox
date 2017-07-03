#ifndef _CONSOLE_SINK_H_
#define _CONSOLE_SINK_H_

#include "BasicSink.h"

#include <string>
#include <mutex>

namespace Toolbox::Log::Sinks
{

class ConsoleSink : public StringSink
{
public:
  // StringSink
  void output (const std::string & output) override;
};

} // namespace Toolbox::Log::Sinks

#endif // _CONSOLE_SINK_H_