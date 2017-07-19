#define BOOST_TEST_MODULE Stringifiable
#include <boost/test/included/unit_test.hpp>

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

BOOST_AUTO_TEST_CASE (toString_matches_input)
{
  const std::string message = "test";
  TestStringifiable testStringifiable (message);
  BOOST_TEST (testStringifiable.toString () == message);
}

BOOST_AUTO_TEST_CASE (toString_matches_convert)
{
  const std::string message = "test";
  TestStringifiable testStringifiable (message);
  const std::string convertedValue = testStringifiable;

  BOOST_TEST (testStringifiable.toString () == convertedValue);
}