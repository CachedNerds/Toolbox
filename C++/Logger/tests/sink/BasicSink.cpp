#define BOOST_TEST_MODULE BasicSink
#include <boost/test/included/unit_test.hpp>

#include "../../sink/BasicSink.h"

using namespace Toolbox::Log::Sink;

class TestSink : public BasicSink<std::string>
{
public:
  void output (const std::string & message) override
  {
    _message = message;
  }

  const std::string getMessage (void) const
  {
    return _message;
  }

private:
  std::string _message;
};

BOOST_AUTO_TEST_CASE (stream_operator_works)
{
  TestSink sink;
  const std::string message = "test";
  sink << message;

  BOOST_TEST (message == sink.getMessage ());
}

BOOST_AUTO_TEST_CASE (output_outputs_message)
{
  TestSink sink;
  const std::string message = "test";
  sink.output (message);

  BOOST_TEST (message == sink.getMessage ());
}