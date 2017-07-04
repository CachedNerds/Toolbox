#ifndef _BASIC_SINK_H_
#define _BASIC_SINK_H_

#include "../outputs/Outputable.h"
#include "../outputs/OutputVisitor.h"

#include <boost/variant.hpp>

namespace Toolbox::Log::Sinks
{

using Toolbox::Log::Outputs::Outputable;
using Toolbox::Log::Outputs::OutputVisitor;

template <typename OutputType>
class BasicSink
{
using Output = boost::variant<const OutputType &, const Outputable<OutputType> &>;
public:
  BasicSink (void);
  virtual BasicSink<OutputType> & operator << (const Output & output);
  virtual void output (const OutputType & output) = 0;

protected:
  // properties
  const OutputVisitor<OutputType> _outputVisitor;
};

#include "BasicSink.cpp"

using StringSink = BasicSink<std::string>;

} // namespace Toolbox::Log::Sinks

#endif // _BASIC_SINK_H_