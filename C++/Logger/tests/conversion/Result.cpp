#define BOOST_TEST_MODULE Result
#include <boost/test/included/unit_test.hpp>

#include "../../conversion/Result.h"
#include "../test_types/TestMessage.h"

using namespace Toolbox::Log::Conversion;
using TestString = Result<std::string>;

BOOST_AUTO_TEST_CASE (VariantVisitor_visits_primative)
{
  const std::string message = "test";
  TestString::Variant testVariant = message;

  BOOST_TEST (TestString::get (testVariant) == message);
}

BOOST_AUTO_TEST_CASE (VariantVisitor_visits_ConvertibleTo)
{
  const std::string message = "test";
  TestMessage testMessage (message);
  TestString::Variant testVariant = testMessage;

  BOOST_TEST (TestString::get (testVariant) == message);
}