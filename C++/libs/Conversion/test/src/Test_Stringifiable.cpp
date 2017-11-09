#include <Toolbox/catch.hpp>
#include "TestStringifiable.h"

using namespace toolbox::conversion;

TEST_CASE ("toString result matches the input")
{
  const std::string message = "test";
  test::Stringifiable testStringifiable(message);
  REQUIRE(testStringifiable.toString() == message);
}

TEST_CASE ("toString result matches the converted value")
{
  const std::string message = "test";
  test::Stringifiable testStringifiable(message);
  const std::string convertedValue = testStringifiable;

  REQUIRE(testStringifiable.toString() == convertedValue);
}