#include <Toolbox/Environment/Production.h>

std::string Production::getEnvironment (void)
{
  return std::string { env };
}
