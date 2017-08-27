#include <Toolbox/catch.hpp>
#include <Toolbox/Conversion/Stringifiable.h>

using Toolbox::Log::Conversion::Stringifiable;

class TestStringifiable : public Stringifiable
{
public:
  explicit TestStringifiable (const std::string & message) : _message (message) {}

  const std::string toString (void) const override
  {
    return _message;
  }

private:
  const std::string _message;
};

TEST_CASE ("toString result matches the input")
{
  const std::string message = "test";
  TestStringifiable testStringifiable (message);
  REQUIRE (testStringifiable.toString () == message);
}

TEST_CASE ("toString result matches the converted value")
{
  const std::string message = "test";
  TestStringifiable testStringifiable (message);
  const std::string convertedValue = testStringifiable;

  REQUIRE (testStringifiable.toString () == convertedValue);
}