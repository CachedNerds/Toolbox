#ifndef _BASIC_SINK_H_
#define _BASIC_SINK_H_

#include "Output.h"

namespace Toolbox::Log::Sinks
{

template <typename OutputType>
class BasicSink
{

public:
  virtual BasicSink & operator << (const OutputType & output);
  virtual BasicSink & operator << (const Output<OutputType> & output);

  virtual void output (const OutputType & output) = 0;
};

#include "BasicSink.cpp"

using StringSink = BasicSink<std::string>;

} // namespace Toolbox::Log::Sinks

#endif // _BASIC_SINK_H_