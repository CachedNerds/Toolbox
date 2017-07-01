#include "Message.h"

namespace Toolbox::Log::Sinks
{

Message::Message (const char * message)
: _message (message)
{

}

Message::Message (const std::string & message)
: _message (message)
{

}

const std::string Message::getOutput (void) const
{
  return this->_message;
}

} // namespace Toolbox::Log::Sinks