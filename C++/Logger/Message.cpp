#include "Message.h"

namespace Toolbox::Log
{
  
Message::Message (const std::string & message)
: _message (message)
{

}

const std::string Message::toString (void) const
{
  return _message;
}

} // namespace Toolbox::Log