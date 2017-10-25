#include <Toolbox/catch.hpp>

#include "TestSink.h"
#include <Toolbox/Sink/ThreadSafeProxySink.h>
#include <thread>

using namespace Toolbox::Sink;

TEST_CASE ("Instantiate ThreadSafeProxySink")
{
  std::string message = "test";

  Test::Sink sink (message);
  ThreadSafeProxySink<Test::Sink> proxySink (std::move (sink));

  ThreadSafeProxySink<Test::Sink> otherProxySink (Test::Sink {});

  auto threadSafeTestSink = make_thread_safe<Test::Sink>(message);
}

TEST_CASE ("Test that the ThreadSafeSink compiles")
{
  Test::SyncSink syncSink;
  std::string message = "test";
  syncSink << message;

  REQUIRE (message == syncSink.getMessage());
}