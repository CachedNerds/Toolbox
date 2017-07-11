#include "Stringifiable.h"

namespace Toolbox::Log::Conversion
{

const Stringifiable::operator std::string (void) const
{
  return toString ();
}

} // namespace Toolbox::Log::Conversion