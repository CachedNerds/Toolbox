#include "TestMessage.h"

 TestMessage::TestMessage (const std::string & message)
 : _message (message)
 {

 }

TestMessage::operator std::string (void) const
{
  return _message;
}

TestMessage::operator int (void) const
{
  return _message.length();
}
