#ifndef _PRODUCTION_H_
#define _PRODUCTION_H_

#include "Environment.h"

class Production : public Environment
{
public:
  std::string getEnvironment (void);

private:
  constexpr static const char * env = "PRODUCTION";
};

#endif // _PRODUCTION_H_
