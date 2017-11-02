#ifndef _BASIC_SINK_H_
#define _BASIC_SINK_H_

#include <Toolbox/Conversion/ConvertibleTo.h>

namespace Toolbox::Sink
{

template <typename OutputType>
class BasicSink
{
public:
  using value_type = OutputType;

  BasicSink (void) = default;
  BasicSink (const BasicSink & rhs) = delete;
  BasicSink & operator= (const BasicSink & rhs) = delete;
  BasicSink (BasicSink && rhs) = default;
  BasicSink & operator= (BasicSink && rhs) = default;

  virtual ~BasicSink (void)
  {

  }

  virtual BasicSink<OutputType> & operator << (const OutputType & output)
  {
    this->output (output);
    return *this;
  }

protected:
  virtual void output (const OutputType & output) = 0;
};

} // namespace Toolbox::Sink

#endif // _BASIC_SINK_H_
