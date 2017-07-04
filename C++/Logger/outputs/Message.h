#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "Stringifiable.h"

#include <string>

namespace Toolbox::Log::Outputs
{

class Message : public Stringifiable
{
public:
  Message (const std::string & message);

  virtual const std::string toString (void) const override;

private:
  const std::string _message;
};

} // namespace Toolbox::Log::Outputs

#endif // _MESSAGE_H_