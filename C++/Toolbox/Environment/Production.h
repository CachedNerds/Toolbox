#pragma once

#include "Environment.h"

namespace toolbox::environment
{

class Production : public Environment
{
public:
  std::string getEnvironment (void);

private:
  constexpr static const char * env = "PRODUCTION";
};

} // namespace toolbox::environment