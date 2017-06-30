#ifndef _SINK_H_
#define _SINK_H_

#include <string>

namespace Toolbox::Log::Sinks
{

class Sink
{
public:
  Sink (void) = default;
  Sink (const Sink & sink) = delete;
  Sink & operator = (const Sink & sink) = delete;

  Sink & operator << (const std::string & message);
  virtual void output (const std::string & message) = 0;
};

} // namespace Toolbox::Log::Sinks

#endif // _SINK_H_