#ifndef _OUTPUTABLE_H_
#define _OUTPUTABLE_H_

#include <string>

namespace Toolbox::Log::Sinks
{

template <typename OutputType>
class Output
{
public:
  virtual const OutputType getOutput (void) const = 0;
};

} // namespace Toolbox::Log::Sinks

#endif // _OUTPUTABLE_H_