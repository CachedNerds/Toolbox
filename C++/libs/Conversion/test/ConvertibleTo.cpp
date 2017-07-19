#define BOOST_TEST_MODULE ConvertibleTo
#include <boost/test/included/unit_test.hpp>

#include "fixtures/TestMessage.h"

#include <string>

BOOST_AUTO_TEST_CASE (convert_matches_input)
{
  const std::string message = "test";
  TestMessage testMessage (message);
  const std::string convertedValue = testMessage;

  BOOST_TEST (convertedValue == message);
}