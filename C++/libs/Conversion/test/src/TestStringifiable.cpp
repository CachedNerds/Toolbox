#include "TestStringifiable.h"

namespace Toolbox::Conversion::Test
{

Stringifiable::Stringifiable (const std::string & message)
: _message (message)
{

}

const std::string Stringifiable::toString (void) const
{
  return _message;
}

} // namespace Toolbox::Conversion::Test