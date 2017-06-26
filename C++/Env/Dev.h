#ifndef _DEV_H_
#define _DEV_H_

#include "Env.h"

class Dev : public Env
{
public:
  std::string getEnv (void);

private:
  constexpr static const char * env = "DEVELOPMENT";
};

#endif
