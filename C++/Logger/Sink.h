#ifndef SINK_H
#define SINK_H

#include <string>

namespace Toolbox::Log::Sinks
{

class Sink
{
public:
  Sink (void) = default;
  Sink (const Sink& sink) = delete;
  Sink& operator= (const Sink& sink) = delete;
  virtual void output (const std::string& value) = 0;
};

} // namespace Toolbox::Log::Sinks

#endif // SINK_H