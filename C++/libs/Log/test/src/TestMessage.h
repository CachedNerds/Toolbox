#pragma once

#include <Toolbox/Conversion/ConvertibleTo.h>

#include <string>

using Toolbox::Conversion::ConvertibleTo;

namespace Toolbox::Log::Test
{

class Message : public ConvertibleTo<std::string>
{
public:
  explicit Message (const std::string & message);

  operator std::string (void) const override;

private:
  const std::string _message;
};

} // namespace Toolbox::Log::Test