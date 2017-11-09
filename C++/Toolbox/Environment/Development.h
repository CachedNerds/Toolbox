#pragma once

#include "Environment.h"

namespace toolbox::environment
{

class Development : public Environment
{
public:
  std::string getEnvironment (void);

private:
  constexpr static const char * env = "DEVELOPMENT";
};

} // namespace toolbox::environment