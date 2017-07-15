#ifndef _STRINGIFIABLE_H_
#define _STRINGIFIABLE_H_

#include "ConvertibleTo.h"
#include "../metaprogramming/value_type_is.h"

#include <string>

namespace Toolbox::Log::Conversion
{

class Stringifiable
  : public ConvertibleTo<std::string>
  , value_type_is <std::string>
{
public:
  virtual const std::string toString (void) const = 0;
  operator std::string (void) const;
};

} // namespace Toolbox::Log::Conversion

#endif // _STRINGIFIABLE_H_
