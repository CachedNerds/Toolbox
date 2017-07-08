#define BOOST_TEST_MODULE VariantVisitor
#include <boost/test/included/unit_test.hpp>

#include "../../conversion/ConvertibleTo.h"
#include "../../conversion/Stringifiable.h"
#include "../../conversion/Variant.h"

using namespace Toolbox::Log::Conversion;
using TestStringVariant = Variant<std::string>;
using TestString = TestStringVariant::type;
using TestStringVisitor = VariantVisitor<std::string>;

class TestMessage : public ConvertibleTo<std::string>
{
public:
  explicit TestMessage (const std::string & message) : _message (message) {}

  const std::string toString (void) const
  {
    return _message;
  }

  const std::string convert (void) const
  {
    return toString ();
  }

private:
  const std::string _message;
};

BOOST_AUTO_TEST_CASE (VariantVisitor_visits_primative)
{
  const std::string message = "test";
  TestString testVariant = message;
  TestStringVisitor testVisitor;
  const std::string testValue = TestStringVariant::get (testVariant);

  BOOST_TEST (testValue == message);
}

BOOST_AUTO_TEST_CASE (VariantVisitor_visits_ConvertibleTo)
{
  const std::string message = "test";
  TestMessage testMessage (message);
  TestString testVariant = testMessage;
  TestStringVisitor testVisitor;
  const std::string testValue = TestStringVariant::get (testVariant);

  BOOST_TEST (testValue == message);
}