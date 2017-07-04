#include "Message.h"

namespace Toolbox::Log::Outputs
{
  
Message::Message (const std::string & message)
: _message (message)
{

}

const std::string Message::toString (void) const
{
  return _message;
}

} // namespace Toolbox::Log::Outputs