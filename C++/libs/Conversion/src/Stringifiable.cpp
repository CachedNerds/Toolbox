#include <Toolbox/Conversion/Stringifiable.h>

namespace Toolbox::Conversion
{

Stringifiable::operator std::string (void) const
{
  return toString ();
}

} // namespace Toolbox::Conversion
