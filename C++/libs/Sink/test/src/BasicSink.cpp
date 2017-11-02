#include <Toolbox/catch.hpp>

#include "TestSink.h"

using namespace Toolbox::Sink;

TEST_CASE ("stream operator accepts the message")
{
  std::string rc;
  Test::Sink sink (rc);
  const std::string message = "test";
  sink << message;

  REQUIRE (rc == message);
}