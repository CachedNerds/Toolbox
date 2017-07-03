#ifndef _STRINGIFIABLE_H_
#define _STRINGIFIABLE_H_

#include "Output.h"

namespace Toolbox::Log::Sinks
{

class Stringifiable : public Output<std::string>
{
public:
  virtual const std::string toString (void) const = 0;
  const std::string getOutput (void) const override final;
};

} // namespace Toolbox::Log::Sinks

#endif // _STRINGIFIABLE_H_