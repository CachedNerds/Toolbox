#include <Toolbox/Conversion/Stringifiable.h>

namespace toolbox::conversion
{

Stringifiable::operator std::string (void) const
{
  return toString ();
}

} // namespace toolbox::conversion
