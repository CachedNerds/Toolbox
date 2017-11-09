#include <Toolbox/Environment/Development.h>

namespace toolbox::environment
{

std::string Development::getEnvironment (void)
{
  return std::string { env };
}

} // namespace toolbox::environment