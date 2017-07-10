#define BOOST_TEST_MODULE ConvertibleTo
#include <boost/test/included/unit_test.hpp>

#include "../test_types/TestMessage.h"

#include <string>

BOOST_AUTO_TEST_CASE (convert_matches_input)
{
  const std::string message = "test";
  TestMessage testMessage (message);

  BOOST_TEST (testMessage.convert () == message);
}