#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "conversions/Stringifiable.h"

#include <string>

namespace Toolbox::Log
{
using Conversion::Stringifiable;
class Message : public Stringifiable
{
public:
  Message (const std::string & message);

  virtual const std::string toString (void) const override;

private:
  const std::string _message;
};

} // namespace Toolbox::Log

#endif // _MESSAGE_H_