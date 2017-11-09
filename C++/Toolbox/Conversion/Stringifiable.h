#pragma once

#include "ConvertibleTo.h"
#include <string>

namespace toolbox::conversion
{

class Stringifiable : public ConvertibleTo<std::string>
{
public:
  virtual const std::string toString (void) const = 0;
  operator std::string (void) const override;
};

} // namespace toolbox::conversion