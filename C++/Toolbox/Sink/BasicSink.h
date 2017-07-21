#ifndef _BASIC_SINK_H_
#define _BASIC_SINK_H_

#include <Toolbox/Conversion/ConvertibleTo.h>

namespace Toolbox::Log::Sink
{

template <typename OutputType>
class BasicSink
{
public:
  BasicSink<OutputType> & operator << (const OutputType & output)
  {
    this->output (output);

    return *this;
  }

  virtual void output (const OutputType & output) = 0;
};

} // namespace Toolbox::Log::Sink

#endif // _BASIC_SINK_H_