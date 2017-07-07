#include "Stringifiable.h"

namespace Toolbox::Log::Conversion
{

const std::string Stringifiable::convert (void) const
{
  return toString ();
}

} // namespace Toolbox::Log::Conversion