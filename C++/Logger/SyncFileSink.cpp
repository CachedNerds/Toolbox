#include "SyncFileSink.h"
#include <exception>

namespace Toolbox::Log::Sinks
{

SyncFileSink::SyncFileSink (const std::string & filename)
: filename_ (filename)
{}

void SyncFileSink::output (const std::string & message)
{

}

} // namespace Toolbox::Log::Sinks