#include <Toolbox/Conversion/Stringifiable.h>

namespace Toolbox::Log::Conversion
{

Stringifiable::operator std::string (void) const
{
  return toString ();
}

} // namespace Toolbox::Log::Conversion
