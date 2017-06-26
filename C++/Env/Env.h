#ifndef _ENV_H_
#define _ENV_H_

#include <string>

class Env
{
public:
  virtual std::string getEnv (void) = 0;
  
private:
};

#endif
