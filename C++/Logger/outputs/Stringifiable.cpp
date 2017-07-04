#include "Stringifiable.h"

namespace Toolbox::Log::Outputs
{

const std::string Stringifiable::toOutput (void) const
{
  return toString ();
}

} // namespace Toolbox::Log::Outputs