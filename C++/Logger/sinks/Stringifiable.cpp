#include "Stringifiable.h"

namespace Toolbox::Log::Sinks
{

const std::string Stringifiable::getOutput (void) const
{
  return toString ();
}

} // namespace Toolbox::Log::Sinks