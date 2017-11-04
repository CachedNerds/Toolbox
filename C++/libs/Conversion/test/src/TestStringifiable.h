#pragma once

#include <Toolbox/Conversion/Stringifiable.h>

#include <string>

namespace Toolbox::Conversion::Test
{

class Stringifiable : public Toolbox::Conversion::Stringifiable
{
public:
  explicit Stringifiable (const std::string & message);

  const std::string toString (void) const override;

private:
  const std::string _message;
};

} // namespace Toolbox::Conversion::Test