#ifndef _DEVELOPMENT_H_
#define _DEVELOPMENT_H_

#include "Environment.h"

class Development : public Environment
{
public:
  std::string getEnvironment (void);

private:
  constexpr static const char * env = "DEVELOPMENT";
};

#endif // _DEVELOPMENT_H_
