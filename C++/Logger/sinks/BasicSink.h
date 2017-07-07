#ifndef _BASIC_SINK_H_
#define _BASIC_SINK_H_

#include "../conversions/ConvertibleTo.h"
#include "../conversions/ConversionVisitor.h"

#include <boost/variant.hpp>

namespace Toolbox::Log::Sinks
{

using Toolbox::Log::Conversion::ConvertibleTo;
using Toolbox::Log::Conversion::ConversionVisitor;

template <typename OutputType>
class BasicSink
{
using Output = boost::variant<const OutputType &, const ConvertibleTo<OutputType> &>;
using OutputVisitor = ConversionVisitor<OutputType>;
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