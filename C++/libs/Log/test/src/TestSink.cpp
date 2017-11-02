#include "TestSink.h"

namespace Toolbox::Logger::Test
{

Sink::Sink (std::string & resource)
: _resource (resource)
{

}

void Sink::output (const std::string & output)
{
  _resource = output;
}

} // namespace Toolbox::Logger::Test