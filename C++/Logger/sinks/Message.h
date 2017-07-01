#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "Output.h"

#include <string>

namespace Toolbox::Log::Sinks
{

class Message : public Output<std::string>
{
public:
  Message (const char * message);
  Message (const std::string & message);

  virtual const std::string getOutput (void) const override;

private:
  const std::string _message;
};

} // namespace Toolbox::Log::Sinks

#endif // _MESSAGE_H_