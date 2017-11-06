#pragma once

#include <string>

namespace Toolbox::Environment
{

class Environment
{
public:
  virtual std::string getEnvironment (void) = 0;
};

} // namespace Toolbox::Environment