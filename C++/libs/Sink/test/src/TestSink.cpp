#include "TestSink.h"

namespace Toolbox::Sink::Test
{

Sink::Sink (void)
: _message ()
{

}

Sink::Sink (const std::string & message)
: _message (message)
{

}

void Sink::output (const std::string & message)
{
  _message = message;
}

const std::string Sink::getMessage (void) const
{
  return _message;
}

void SyncSink::output (const std::string & message)
{
  _message = message;
}

const std::string SyncSink::getMessage (void) const
{
  return _message;
}

} // namespace Toolbox::Sink::Test