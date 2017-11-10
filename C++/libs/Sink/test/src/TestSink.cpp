#include "TestSink.h"

namespace toolbox::sink::test
{

Sink::Sink (std::string & resource)
: _resource(resource)
{

}

void Sink::output (const std::string & output)
{
  _resource = output;
}

SafeSink::SafeSink (std::string & resource)
: _resource(resource)
{

}

void SafeSink::output (const std::string & output)
{
  _resource = output;
}

} // namespace toolbox::sink::test