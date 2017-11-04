#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include <string>

namespace Toolbox::Environment
{

class Environment
{
public:
  virtual std::string getEnvironment (void) = 0;
};

} // namespace Toolbox::Environment

#endif // _ENVIRONMENT_H_
