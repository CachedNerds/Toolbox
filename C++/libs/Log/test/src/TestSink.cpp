#include "TestSink.h"

namespace Toolbox::Log::Test
{

Sink::Sink (std::string & resource)
: _resource (resource)
{

}

void Sink::output (const std::string & output)
{
  _resource = output;
}

} // namespace Toolbox::Log::Test