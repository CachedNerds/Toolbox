#ifndef _BASIC_SINK_H_
#define _BASIC_SINK_H_

#include "../conversion/ConvertibleTo.h"
#include "../conversion/Result.h"

namespace Toolbox::Log::Sink
{

template <typename OutputType>
class BasicSink
{
using Output = Toolbox::Log::Conversion::Result<OutputType>;
using OutputVisitor = typename Output::Variant;
public:
  virtual BasicSink<OutputType> & operator << (const OutputVisitor & output);
  virtual void output (const OutputType & output) = 0;
};

#include "BasicSink.cpp"

} // namespace Toolbox::Log::Sink

#endif // _BASIC_SINK_H_