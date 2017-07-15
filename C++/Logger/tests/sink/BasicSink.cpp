#define BOOST_TEST_MODULE BasicSink
#include <boost/test/included/unit_test.hpp>

#include <TestSink.h>

using namespace Toolbox::Log::Sink;

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