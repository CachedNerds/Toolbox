#pragma once

#include <Toolbox/Conversion/ConvertibleTo.h>
#include <string>

using toolbox::conversion::ConvertibleTo;

namespace toolbox::conversion::test
{

class Message : public ConvertibleTo<std::string, size_t>
{
public:
  explicit Message (const std::string & message);

  operator std::string (void) const override;

  operator size_t (void) const override;

private:
  const std::string _message;
};

} // namespace toolbox::conversion::test