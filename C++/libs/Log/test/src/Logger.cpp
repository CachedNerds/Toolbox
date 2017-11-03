#include <Toolbox/catch.hpp>

#include "TestSink.h"
#include "TestMessage.h"
#include <Toolbox/Sink/ThreadSafeProxySink.h>
#include <Toolbox/Sink/FileSink.h>
#include <Toolbox/Log/Level.h>
#include <Toolbox/Log/Logger.h>

using namespace Toolbox::Log;

const std::string createMessage (const Level & level, const std::string & message)
{
  return levelToString (level) + ": " + message + "\n";
}

TEST_CASE ("get and set default log level")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));
 
  Level level = Level::DEBUG;
  logger.setDefault (level);

  REQUIRE (logger.getDefault () == level);
}

TEST_CASE ("get and set threshold log level")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));
  
  Level level = Level::DEBUG;
  logger.setThreshold (level);

  REQUIRE (logger.getThreshold () == level);
}

TEST_CASE ("log with default level")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));
  
  const std::string message = "message";
  logger.log (message);

  REQUIRE (rc == createMessage (logger.getDefault (), message));
}

TEST_CASE ("log with specific level")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));
  
  const std::string message = "message";
  Level level = Level::INFO;
  logger.log (level, message);

  REQUIRE (rc == createMessage (level, message));
}

TEST_CASE ("can log strings")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));

  const std::string message = "message";
  logger.log (message);

  REQUIRE (rc == createMessage (logger.getDefault (), message));
}

TEST_CASE ("can log ConvertibleTo<string> objects")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));

  const std::string message = "message";
  const TestMessage testMessage (message);
  logger.log (testMessage);

  REQUIRE (rc == createMessage (logger.getDefault (), message));
}

TEST_CASE ("logger.trace logs at trace log level")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));
 
  const std::string message = "message";
  logger.trace (message);

  const std::string level = levelToString (Level::TRACE);
  std::string result = rc;
  REQUIRE (result.find (level) != std::string::npos);
}

TEST_CASE ("logger.debug logs at debug log level")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));
  
  const std::string message = "message";
  logger.debug (message);

  const std::string level = levelToString (Level::DEBUG);
  std::string result = rc;
  REQUIRE (result.find (level) != std::string::npos);
}

TEST_CASE ("logger.info logs at info log level")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));
  
  const std::string message = "message";
  logger.info (message);

  const std::string level = levelToString (Level::INFO);
  std::string result = rc;
  REQUIRE (result.find (level) != std::string::npos);
}

TEST_CASE ("logger.warning logs at warning log level")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));
  
  const std::string message = "message";
  logger.warning (message);

  const std::string level = levelToString (Level::WARNING);
  std::string result = rc;
  REQUIRE (result.find (level) != std::string::npos);
}

TEST_CASE ("logger.error logs at error log level")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));
  
  const std::string message = "message";
  logger.error (message);

  const std::string level = levelToString (Level::ERROR);
  std::string result = rc;
  REQUIRE (result.find (level) != std::string::npos);
}

TEST_CASE ("logger.fatal logs at fatal log level")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));
  
  const std::string message = "message";
  logger.fatal (message);

  const std::string level = levelToString (Level::FATAL);
  std::string result = rc;
  REQUIRE (result.find (level) != std::string::npos);
}

TEST_CASE ("doesn't log below threshold")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));
  
  const std::string previousMessage = "previous message";
  logger.log (Level::ERROR, previousMessage);
  
  logger.setThreshold (Level::INFO);

  const std::string newMessage = "new message";
  Level level = Level::TRACE;
  logger.log (level, newMessage);

  REQUIRE (rc != createMessage (level, newMessage));
}

TEST_CASE ("does_log_above_threshold")
{
  std::string rc;
  Logger logger (std::make_unique<Test::Sink> (rc));
  
  const std::string previousMessage = "previous message";
  logger.log (Level::ERROR, previousMessage);
  
  logger.setThreshold (Level::INFO);

  const std::string newMessage = "new message";
  Level level = Level::INFO;
  logger.log (level, newMessage);

  REQUIRE (rc == createMessage (level, newMessage));
}

TEST_CASE ("Logging to a thread safe sink")
{
  using namespace Toolbox::Sink;

  std::string rc;
  Logger logger (make_unique_thread_safe<Test::Sink> (rc));
  std::string message = "test";
  logger.info (message);

  REQUIRE (rc == createMessage (Level::INFO, message));
}

TEST_CASE ("Logging to a file")
{
  using namespace Toolbox::Sink;

  std::string filename = "test.txt";
  Logger logger (std::make_unique<FileSink>(filename));
  std::string message = "test";
  logger.info (message);

  std::remove (filename.c_str ());
}