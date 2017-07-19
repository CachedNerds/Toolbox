#ifndef _BASIC_SINK_H_
#define _BASIC_SINK_H_

#include <Toolbox/Conversion/ConvertibleTo.h>

namespace Toolbox::Log::Sink
{

template <typename OutputType>
class BasicSink
{
public:
  virtual BasicSink<OutputType> & operator << (const OutputType & output);
  virtual void output (const OutputType & output) = 0;
};

#include <libs/Sink/src/BasicSink.cpp>

} // namespace Toolbox::Log::Sink

#endif // _BASIC_SINK_H_