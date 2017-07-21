#include <Toolbox/catch.hpp>

#include "fixtures/TestSink.h"

using namespace Toolbox::Log::Sink;

TEST_CASE ("stream operator accepts the message")
{
  TestSink sink;
  const std::string message = "test";
  sink << message;

  REQUIRE (message == sink.getMessage ());
}

TEST_CASE ("output method outputs the message")
{
  TestSink sink;
  const std::string message = "test";
  sink.output (message);

  REQUIRE (message == sink.getMessage ());
}