#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include <string>

class Environment
{
public:
  virtual std::string getEnvironment (void) = 0;
};

#endif // _ENVIRONMENT_H_
