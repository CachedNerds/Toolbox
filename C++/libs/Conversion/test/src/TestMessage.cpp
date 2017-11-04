#include "TestMessage.h"

namespace Toolbox::Conversion::Test
{

Message::Message (const std::string & message)
: _message (message)
{

}

Message::operator std::string (void) const
{
  return _message;
}

Message::operator size_t (void) const
{
  return _message.length();
}

} // namespace Toolbox::Conversion::Test