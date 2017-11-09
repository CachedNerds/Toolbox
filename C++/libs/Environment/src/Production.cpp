#include <Toolbox/Environment/Production.h>

namespace toolbox::environment
{

std::string Production::getEnvironment (void)
{
  return std::string { env };
}

} // namespace toolbox::environment