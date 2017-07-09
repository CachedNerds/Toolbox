#ifndef _BASIC_SINK_H_
#define _BASIC_SINK_H_

#include "../conversion/ConvertibleTo.h"
#include "../conversion/Variant.h"

namespace Toolbox::Log::Sink
{

template <typename OutputType>
class BasicSink
{
using OutputVariant = Toolbox::Log::Conversion::Variant<OutputType>;
using Output = typename OutputVariant::type;
using OutputVisitor = Toolbox::Log::Conversion::VariantVisitor<OutputType>;
public:
  virtual BasicSink<OutputType> & operator << (const Output & output);
  virtual void output (const OutputType & output) = 0;
};

#include "BasicSink.cpp"

} // namespace Toolbox::Log::Sink

#endif // _BASIC_SINK_H_