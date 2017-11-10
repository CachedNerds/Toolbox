#pragma once

#include <Toolbox/Conversion/Stringifiable.h>
#include <string>

namespace toolbox::conversion::test
{

class Stringifiable : public toolbox::conversion::Stringifiable
{
public:
  explicit Stringifiable (const std::string & message);

  const std::string toString (void) const override;

private:
  const std::string _message;
};

} // namespace toolbox::conversion::test