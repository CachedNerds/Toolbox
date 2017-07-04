#ifndef _STRINGIFIABLE_H_
#define _STRINGIFIABLE_H_

#include "Outputable.h"

#include <string>

namespace Toolbox::Log::Outputs
{

class Stringifiable : public Outputable<std::string>
{
public:
  virtual const std::string toString (void) const = 0;
  const std::string toOutput (void) const override final;
};

} // namespace Toolbox::Log::Outputs

#endif // _STRINGIFIABLE_H_