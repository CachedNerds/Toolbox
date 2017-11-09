#pragma once

#include <Toolbox/Conversion/ConvertibleTo.h>
#include <string>

using toolbox::conversion::ConvertibleTo;

namespace toolbox::log::test
{

class Message : public ConvertibleTo<std::string>
{
public:
  explicit Message (const std::string & message);

  operator std::string (void) const override;

private:
  const std::string _message;
};

} // namespace toolbox::log::test