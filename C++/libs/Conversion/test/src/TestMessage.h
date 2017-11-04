#pragma once

#include <Toolbox/Conversion/ConvertibleTo.h>

#include <string>

using Toolbox::Conversion::ConvertibleTo;

namespace Toolbox::Conversion::Test
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

} // namespace Toolbox::Conversion::Test