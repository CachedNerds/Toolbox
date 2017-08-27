#include "TestMessage.h"

TestMessage::TestMessage (const std::string & message)
: _message (message)
{

}

TestMessage::operator std::string (void) const
{
  return _message;
}

TestMessage::operator size_t (void) const
{
  return _message.length();
}