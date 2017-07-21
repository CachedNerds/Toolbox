#include <Toolbox/catch.hpp>
#include "fixtures/TestMessage.h"

#include <string>

TEST_CASE ("Implementation of ConvertibleTo string converts to string")
{
  const std::string message = "test";
  TestMessage testMessage (message);
  const std::string convertedValue = testMessage;

  REQUIRE (message == convertedValue);
}