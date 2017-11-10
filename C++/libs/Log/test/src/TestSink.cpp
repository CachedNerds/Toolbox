#include "TestSink.h"

namespace toolbox::log::test
{

Sink::Sink (std::string & resource)
: _resource(resource)
{

}

void Sink::output (const std::string & output)
{
  _resource = output;
}

} // namespace toolbox::log::test