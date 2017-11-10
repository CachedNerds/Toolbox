#pragma once

#include <string>

namespace toolbox::environment
{

class Environment
{
public:
  virtual std::string getEnvironment (void) = 0;
};

} // namespace toolbox::environment