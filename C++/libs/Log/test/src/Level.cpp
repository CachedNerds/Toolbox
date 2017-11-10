#include <Toolbox/catch.hpp>
#include <Toolbox/Log/Level.h>

using namespace toolbox::log;

TEST_CASE ("levelToString converts a Level to its string representation")
{
  REQUIRE(levelToString(Level::INFO) == "INFO");
}