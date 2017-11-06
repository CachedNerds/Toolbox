#include <Toolbox/catch.hpp>
#include "TestMessage.h"

#include <string>

using namespace Toolbox::Conversion;

TEST_CASE ("Implementation of ConvertibleTo string converts to string")
{
  const std::string message = "test";
  Test::Message testMessage (message);
  const std::string convertedValue = testMessage;

  REQUIRE (message == convertedValue);
}

TEST_CASE ("Implementation of ConvertibleTo string converts to size_t")
{
  const std::string message = "test";
  Test::Message testMessage (message);
  const size_t messageLength = testMessage;

  REQUIRE (message.length() == messageLength);
}