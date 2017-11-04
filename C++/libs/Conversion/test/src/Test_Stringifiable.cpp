#include <Toolbox/catch.hpp>
#include <Toolbox/Conversion/Stringifiable.h>

namespace Toolbox::Conversion::Test
{

class Stringifiable : public Toolbox::Conversion::Stringifiable
{
public:
  explicit Stringifiable (const std::string & message) : _message (message) {}

  const std::string toString (void) const override
  {
    return _message;
  }

private:
  const std::string _message;
};

} // namespace Toolbox::Conversion::Test

using namespace Toolbox::Conversion;

TEST_CASE ("toString result matches the input")
{
  const std::string message = "test";
  Test::Stringifiable testStringifiable (message);
  REQUIRE (testStringifiable.toString () == message);
}

TEST_CASE ("toString result matches the converted value")
{
  const std::string message = "test";
  Test::Stringifiable testStringifiable (message);
  const std::string convertedValue = testStringifiable;

  REQUIRE (testStringifiable.toString () == convertedValue);
}