#include "TestMessage.h"

namespace toolbox::log::test
{

 Message::Message (const std::string & message)
 : _message(message)
 {

 }

 Message::operator std::string (void) const
{
  return _message;
}

} // namespace toolbox::log::test