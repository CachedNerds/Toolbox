#include "TestStringifiable.h"

namespace toolbox::conversion::test
{

Stringifiable::Stringifiable (const std::string & message)
: _message(message)
{

}

const std::string Stringifiable::toString (void) const
{
  return _message;
}

} // namespace toolbox::conversion::test