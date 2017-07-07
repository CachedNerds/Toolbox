#define BOOST_TEST_MODULE Stringifiable
#include <boost/test/included/unit_test.hpp>

#include "../../conversions/Stringifiable.h"

using Toolbox::Log::Conversion::Stringifiable;

class TestMessage : public Stringifiable
{
public:
  explicit TestMessage (const std::string & message) : _message (message) {}

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
  TestMessage testMessage (message);
  BOOST_TEST (testMessage.toString () == message);
}

BOOST_AUTO_TEST_CASE (toString_matches_convert)
{
  const std::string message = "test";
  TestMessage testMessage (message);
  BOOST_TEST (testMessage.toString () == testMessage.convert ());
}