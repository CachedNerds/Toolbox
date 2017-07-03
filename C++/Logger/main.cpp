#include "Logger.h"
#include "sinks/ConsoleSink.h"
#include "sinks/Message.h"

using namespace Toolbox::Log;

int main (void)
{
  ConsoleSink consoleSink;
  Logger logger (consoleSink);

  logger.log (Level::INFO, "message!"); // logs on default level
  logger.warning ("warning!"); // succeeds

  logger.setThreshold (Level::INFO); // changes log level

  logger.debug ("debug?"); // fails
  logger.info ("info!"); // succeeds

  Message message ("error!");
  logger.error (message); // logs stringifiable successfully

  return 0;
}