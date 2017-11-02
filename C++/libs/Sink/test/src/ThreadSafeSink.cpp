#include <Toolbox/catch.hpp>

#include "TestSink.h"
#include <Toolbox/Sink/ThreadSafeProxySink.h>
#include <thread>
#include <sstream>

using namespace Toolbox::Sink;

TEST_CASE ("ThreadSafeProxySink with lvalue Sink")
{
  std::string rc;
  Test::Sink sink (rc);
  ThreadSafeProxySink<Test::Sink> proxySink (std::move (sink));
  std::string message = "test";
  proxySink << message;
  
  REQUIRE (rc == message);
}

TEST_CASE ("ThreadSafeProxySink with rvalue Sink")
{
  std::string rc;
  ThreadSafeProxySink<Test::Sink> proxySink (Test::Sink {rc});
  std::string message = "test";
  proxySink << message;
  
  REQUIRE (rc == message);
}

TEST_CASE ("Instantiate ThreadSafeProxySink using make_thread_safe")
{
  std::string rc;
  ThreadSafeProxySink<Test::Sink> proxySink = make_thread_safe<Test::Sink>(rc);
  std::string message = "test";
  proxySink << message;

  REQUIRE (rc == message);
}

TEST_CASE ("ThreadSafeSink")
{
  std::string rc;
  Test::SafeSink safeSink (rc);
  std::string message = "test";
  safeSink << message;

  REQUIRE (rc == message);
}