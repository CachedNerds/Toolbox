#define BOOST_TEST_MODULE ConvertibleTo
#include <boost/test/included/unit_test.hpp>

#include "../test_types/TestMessage.h"

#include <string>

BOOST_AUTO_TEST_CASE (convert_matches_input)
{
  const std::string message = "test";
  TestMessage testMessage (message);
  const std::string convertedValue = testMessage;

  BOOST_TEST (convertedValue == message);
}

BOOST_AUTO_TEST_CASE (convert_matches_input_size)
{
  const std::string message = "test";
  TestMessage testMessage (message);

  int testMessageSize = testMessage;

  BOOST_TEST (testMessageSize == message.length());
}
