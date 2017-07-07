#ifndef _BASIC_SINK_H_
#define _BASIC_SINK_H_

#include "../conversions/ConvertibleTo.h"
#include "../conversions/VariantVisitor.h"
#include "../conversions/Variant.h"

#include <boost/variant.hpp>

namespace Toolbox::Log::Sinks
{

template <typename OutputType>
class BasicSink
{
using OutputVariant = Toolbox::Log::Conversion::Variant<OutputType>;
using Output = typename OutputVariant::type;
using OutputVisitor = Toolbox::Log::Conversion::VariantVisitor<OutputType>;
public:
  BasicSink (void);
  virtual BasicSink<OutputType> & operator << (const Output & output);
  virtual void output (const OutputType & output) = 0;

private:
  OutputVisitor _outputVisitor;
};

#include "BasicSink.cpp"

} // namespace Toolbox::Log::Sinks

#endif // _BASIC_SINK_H_