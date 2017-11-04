#pragma once

#include "Environment.h"

namespace Toolbox::Environment
{

class Production : public Environment
{
public:
  std::string getEnvironment (void);

private:
  constexpr static const char * env = "PRODUCTION";
};

} // namespace Toolbox::Environment