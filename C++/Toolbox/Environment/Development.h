#ifndef _DEVELOPMENT_H_
#define _DEVELOPMENT_H_

#include "Environment.h"

namespace Toolbox::Environment
{

class Development : public Environment
{
public:
  std::string getEnvironment (void);

private:
  constexpr static const char * env = "DEVELOPMENT";
};

} // namespace Toolbox::Environment

#endif // _DEVELOPMENT_H_
