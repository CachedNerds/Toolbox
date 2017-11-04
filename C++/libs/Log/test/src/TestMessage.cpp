#include "TestMessage.h"

namespace Toolbox::Log::Test
{

Message::Message (const std::string & message)
: _message (message)
{

}

Message::operator std::string (void) const
{
  return _message;
}

} // namespace Toolbox::Log::Test