#include "TestMessage.h"

 TestMessage::TestMessage (const std::string & message)
 : _message (message)
 {

 }

const std::string TestMessage::convert (void) const
{
  return _message;
}