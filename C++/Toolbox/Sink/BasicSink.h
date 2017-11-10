#pragma once

#include <Toolbox/Conversion/ConvertibleTo.h>

namespace toolbox::sink
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

} // namespace toolbox::sink