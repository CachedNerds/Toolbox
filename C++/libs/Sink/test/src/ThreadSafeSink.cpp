#include <Toolbox/catch.hpp>
#include "TestSink.h"
#include <Toolbox/Sink/ThreadSafeProxySink.h>

using namespace toolbox::sink;

TEST_CASE ("ThreadSafeProxySink with lvalue Sink")
{
  std::string rc;
  test::Sink sink(rc);
  ThreadSafeProxySink<test::Sink> proxySink(std::move(sink));
  std::string message = "test";
  proxySink << message;
  
  REQUIRE(rc == message);
}

TEST_CASE ("ThreadSafeProxySink with rvalue Sink")
{
  std::string rc;
  ThreadSafeProxySink<test::Sink> proxySink(test::Sink{rc});
  std::string message = "test";
  proxySink << message;
  
  REQUIRE(rc == message);
}

TEST_CASE ("Instantiate ThreadSafeProxySink using make_thread_safe")
{
  std::string rc;
  auto proxySink = make_thread_safe<test::Sink>(rc);
  std::string message = "test";
  proxySink << message;

  REQUIRE(rc == message);
}

TEST_CASE ("Instantiate a unique_ptr<ThreadSafeProxySink> using make_unique_thread_safe")
{
  std::string rc;
  auto proxySink = make_unique_thread_safe<test::Sink>(rc);
  std::string message = "test";
  (*proxySink) << message;

  REQUIRE(rc == message);
}

TEST_CASE ("ThreadSafeSink")
{
  std::string rc;
  test::SafeSink safeSink(rc);
  std::string message = "test";
  safeSink << message;

  REQUIRE(rc == message);
}