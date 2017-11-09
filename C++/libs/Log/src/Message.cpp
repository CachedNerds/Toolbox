#include <Toolbox/Log/Message.h>

namespace toolbox::log
{
  
Message::Message (const std::string & message)
: _message (message)
{

}

const std::string Message::toString (void) const
{
  return _message;
}

} // namespace toolbox::log