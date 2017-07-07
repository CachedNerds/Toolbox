#include "Logger.h"
#include "sinks/ConsoleSink.h"
#include "Message.h"

int main (void)
{
  using namespace Toolbox::Log;
  using namespace Sinks;
  using namespace Conversion;
  ConsoleSink consoleSink;
  Logger logger (consoleSink);

  logger.log ("message!"); // logs on default level
  logger.log (Level::FATAL, "fatal!"); // succeeds
  logger.warning ("warning!"); // succeeds
  logger.setDefault (Level::DEBUG); // sets default level the log method will log at
  logger.setThreshold (Level::INFO); // changes log level threshold

  logger.debug ("debug?"); // fails, below threshold
  logger.log ("default level!"); // fails, below threshold
  logger.info ("info!"); // succeeds

  logger.setThreshold (Level::DEBUG);
  logger.log ("default level!"); // succeeds, above threshold

  Message message ("error!");
  logger.error (message); // logs stringifiable successfully

  return 0;
}