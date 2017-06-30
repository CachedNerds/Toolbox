#define BOOST_TEST_MODULE Severity
#include <boost/test/included/unit_test.hpp>
#include "../Severity.h"

using namespace Toolbox::Log::Severity;

BOOST_AUTO_TEST_CASE (level_to_string)
{
  BOOST_TEST (toString (Level::INFO) == "INFO");
}