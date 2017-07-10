#define BOOST_TEST_MODULE ConvertibleTo
#include <boost/test/included/unit_test.hpp>

#include "test_types/TestSink.h"
#include "test_types/TestMessage.h"
#include "../Level.h"
#include "../Logger.h"

using Toolbox::Log::Level;
using Toolbox::Log::Logger;

BOOST_AUTO_TEST_CASE (default_level_accessors)
{
  TestSink testSink;
  Logger logger (testSink);
 
  Level level = Level::DEBUG;
  logger.setDefault (level);

  BOOST_TEST (logger.getDefault () == level);
}

BOOST_AUTO_TEST_CASE (threshold_level_accessors)
{
  TestSink testSink;
  Logger logger (testSink);
  
  Level level = Level::DEBUG;
  logger.setThreshold (level);

  BOOST_TEST (logger.getThreshold () == level);
}

BOOST_AUTO_TEST_CASE (logger_log_with_default_level)
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  logger.log (message);

  const std::string resultMessage = levelToString (logger.getDefault ()) + ": " + message;
  BOOST_TEST (testSink.getMessage () == resultMessage);
}

BOOST_AUTO_TEST_CASE (logger_log_with_specific_level)
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  Level level = Level::INFO;
  logger.log (level, message);

  const std::string resultMessage = levelToString (level) + ": " + message;
  BOOST_TEST (testSink.getMessage () == resultMessage);
}

BOOST_AUTO_TEST_CASE (logger_can_log_strings_and_ConvertibleToStrings)
{
  TestSink testSink;
  Logger logger (testSink);

  const std::string message = "message";
  logger.log (message);

  const std::string resultMessage = levelToString (logger.getDefault ()) + ": " + message;
  BOOST_TEST (testSink.getMessage () == resultMessage);

  const std::string newMessage = "newMessage";
  const TestMessage testMessage (newMessage);
  logger.log (testMessage);

  const std::string newResultMessage = levelToString (logger.getDefault ()) + ": " + newMessage;
  BOOST_TEST (testSink.getMessage () == newResultMessage);
}

BOOST_AUTO_TEST_CASE (logger_trace)
{
  TestSink testSink;
  Logger logger (testSink);
 
  const std::string message = "message";
  logger.trace (message);

  const std::string testMessage = testSink.getMessage ();
  const std::string level = levelToString (Level::TRACE);
  BOOST_TEST (testMessage.find (level) != std::string::npos);
}

BOOST_AUTO_TEST_CASE (logger_debug)
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  logger.debug (message);

  const std::string testMessage = testSink.getMessage ();
  const std::string level = levelToString (Level::DEBUG);
  BOOST_TEST (testMessage.find (level) != std::string::npos);
}

BOOST_AUTO_TEST_CASE (logger_info)
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  logger.info (message);

  const std::string testMessage = testSink.getMessage ();
  const std::string level = levelToString (Level::INFO);
  BOOST_TEST (testMessage.find (level) != std::string::npos);
}

BOOST_AUTO_TEST_CASE (logger_warning)
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  logger.warning (message);

  const std::string testMessage = testSink.getMessage ();
  const std::string level = levelToString (Level::WARNING);
  BOOST_TEST (testMessage.find (level) != std::string::npos);
}

BOOST_AUTO_TEST_CASE (logger_error)
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  logger.error (message);

  const std::string testMessage = testSink.getMessage ();
  const std::string level = levelToString (Level::ERROR);
  BOOST_TEST (testMessage.find (level) != std::string::npos);
}

BOOST_AUTO_TEST_CASE (logger_fatal)
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string message = "message";
  logger.fatal (message);

  const std::string testMessage = testSink.getMessage ();
  const std::string level = levelToString (Level::FATAL);
  BOOST_TEST (testMessage.find (level) != std::string::npos);
}

BOOST_AUTO_TEST_CASE (logger_doesnt_log_below_threshold)
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string previousMessage = "previous message";
  logger.log (Level::ERROR, previousMessage);
  
  logger.setThreshold (Level::INFO);

  const std::string newMessage = "new message";
  Level level = Level::TRACE;
  logger.log (level, newMessage);

  const std::string resultMessage = levelToString (level) + ": " + newMessage;
  BOOST_TEST (testSink.getMessage () != resultMessage);
}

BOOST_AUTO_TEST_CASE (logger_does_log_above_threshold)
{
  TestSink testSink;
  Logger logger (testSink);
  
  const std::string previousMessage = "previous message";
  logger.log (Level::ERROR, previousMessage);
  
  logger.setThreshold (Level::INFO);

  const std::string newMessage = "new message";
  Level level = Level::INFO;
  logger.log (level, newMessage);

  const std::string resultMessage = levelToString (level) + ": " + newMessage;
  BOOST_TEST (testSink.getMessage () == resultMessage);
}