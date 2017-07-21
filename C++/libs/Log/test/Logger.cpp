#include <Toolbox/catch.hpp>

#include "fixtures/TestSink.h"
#include "fixtures/TestMessage.h"
#include <Toolbox/Log/Level.h>
#include <Toolbox/Log/Logger.h>

using Toolbox::Log::Level;
using Toolbox::Log::Logger;

const std::string createMessage (const Level & level, const std::string & message)
{
  return levelToString (level) + ": " + message + "\n";
}

TEST_CASE ("get and set default log level")
{
  TestSink testSink;
  Logger logger (testSink);
 
  Level level = Level::DEBUG;
  logger.setDefault (level);

  REQUIRE (logger.getDefault () == level);
}

TEST_CASE ("get and set threshold log level")
{
  TestSink testSink;
  Logger logger (testSink);
  
  Level level = Level::DEBUG;
  logger.setThreshold (level);

  REQUIRE (logger.getThreshold () == level);
}

TEST_CASE ("log with default level")
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  logger.log (message);

  REQUIRE (testSink.getMessage () == createMessage (logger.getDefault (), message));
}

TEST_CASE ("log with specific level")
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  Level level = Level::INFO;
  logger.log (level, message);

  REQUIRE (testSink.getMessage () == createMessage (level, message));
}

TEST_CASE ("can log strings")
{
  TestSink testSink;
  Logger logger (testSink);

  const std::string message = "message";
  logger.log (message);

  REQUIRE (testSink.getMessage () == createMessage (logger.getDefault (), message));
}

TEST_CASE ("can log ConvertibleTo<string> objects")
{
  TestSink testSink;
  Logger logger (testSink);

  const std::string message = "message";
  const TestMessage testMessage (message);
  logger.log (testMessage);

  REQUIRE (testSink.getMessage () == createMessage (logger.getDefault (), message));
}

TEST_CASE ("logger.trace logs at trace log level")
{
  TestSink testSink;
  Logger logger (testSink);
 
  const std::string message = "message";
  logger.trace (message);

  const std::string testMessage = testSink.getMessage ();
  const std::string level = levelToString (Level::TRACE);
  REQUIRE (testMessage.find (level) != std::string::npos);
}

TEST_CASE ("logger.debug logs at debug log level")
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  logger.debug (message);

  const std::string testMessage = testSink.getMessage ();
  const std::string level = levelToString (Level::DEBUG);
  REQUIRE (testMessage.find (level) != std::string::npos);
}

TEST_CASE ("logger.info logs at info log level")
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  logger.info (message);

  const std::string testMessage = testSink.getMessage ();
  const std::string level = levelToString (Level::INFO);
  REQUIRE (testMessage.find (level) != std::string::npos);
}

TEST_CASE ("logger.warning logs at warning log level")
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  logger.warning (message);

  const std::string testMessage = testSink.getMessage ();
  const std::string level = levelToString (Level::WARNING);
  REQUIRE (testMessage.find (level) != std::string::npos);
}

TEST_CASE ("logger.error logs at error log level")
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  logger.error (message);

  const std::string testMessage = testSink.getMessage ();
  const std::string level = levelToString (Level::ERROR);
  REQUIRE (testMessage.find (level) != std::string::npos);
}

TEST_CASE ("logger.fatal logs at fatal log level")
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  logger.fatal (message);

  const std::string testMessage = testSink.getMessage ();
  const std::string level = levelToString (Level::FATAL);
  REQUIRE (testMessage.find (level) != std::string::npos);
}

TEST_CASE ("doesn't log below threshold")
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string previousMessage = "previous message";
  logger.log (Level::ERROR, previousMessage);
  
  logger.setThreshold (Level::INFO);

  const std::string newMessage = "new message";
  Level level = Level::TRACE;
  logger.log (level, newMessage);

  REQUIRE (testSink.getMessage () != createMessage (level, newMessage));
}

TEST_CASE ("does_log_above_threshold")
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string previousMessage = "previous message";
  logger.log (Level::ERROR, previousMessage);
  
  logger.setThreshold (Level::INFO);

  const std::string newMessage = "new message";
  Level level = Level::INFO;
  logger.log (level, newMessage);

  REQUIRE (testSink.getMessage () == createMessage (level, newMessage));
}