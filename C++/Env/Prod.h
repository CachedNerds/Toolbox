#ifndef _PROD_H_
#define _PROD_H_

#include "Env.h"

class Prod : public Env
{
public:
  std::string getEnv (void);

private:
  constexpr static const char * env = "PRODUCTION";
};

#endif
