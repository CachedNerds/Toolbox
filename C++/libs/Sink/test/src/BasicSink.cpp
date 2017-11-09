#include <Toolbox/catch.hpp>
#include "TestSink.h"

using namespace toolbox::sink;

TEST_CASE ("stream operator accepts the message")
{
  std::string rc;
  test::Sink sink(rc);
  const std::string message = "test";
  sink << message;

  REQUIRE(rc == message);
}