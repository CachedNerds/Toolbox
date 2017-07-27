#ifndef _STRINGIFIABLE_H_
#define _STRINGIFIABLE_H_

#include "ConvertibleTo.h"

#include <string>

namespace Toolbox::Log::Conversion
{

class Stringifiable : public ConvertibleTo<std::string>
{
public:
  virtual const std::string toString (void) const = 0;
  operator std::string (void) const override;
};

} // namespace Toolbox::Log::Conversion

#endif // _STRINGIFIABLE_H_
