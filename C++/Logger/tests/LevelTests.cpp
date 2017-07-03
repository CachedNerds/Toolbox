#define BOOST_TEST_MODULE Level
#include <boost/test/included/unit_test.hpp>

#include "../Level.h"

using namespace Toolbox::Log;

BOOST_AUTO_TEST_CASE (level_to_string)
{
  BOOST_TEST (levelToString (Level::INFO) == "INFO");
}