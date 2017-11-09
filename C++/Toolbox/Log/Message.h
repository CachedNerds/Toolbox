#pragma once

#include <Toolbox/Conversion/Stringifiable.h>
#include <string>

using toolbox::conversion::Stringifiable;

namespace toolbox::log
{

class Message : public Stringifiable
{
public:
  Message (const std::string & message);

  virtual const std::string toString (void) const override;

private:
  const std::string _message;
};

} // namespace toolbox::log