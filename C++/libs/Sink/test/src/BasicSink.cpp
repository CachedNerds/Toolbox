#include <Toolbox/catch.hpp>

#include "TestSink.h"

using namespace Toolbox::Sink;

TEST_CASE ("stream operator accepts the message")
{
  Test::Sink sink;
  const std::string message = "test";
  sink << message;

  REQUIRE (message == sink.getMessage ());
}

TEST_CASE ("output method outputs the message")
{
  Test::Sink sink;
  const std::string message = "test";
  sink.output (message);

  REQUIRE (message == sink.getMessage ());
}