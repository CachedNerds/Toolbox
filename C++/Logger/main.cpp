#include "Logger.h"

int main (void)
{
  Logger logger;
  logger.log (Severity::Level::DEBUG, "test");
  logger.setThreshold (Severity::Level::INFO);
  logger.log (Severity::Level::TRACE, "don't log");
  logger.log (Severity::Level::ERROR, "log");

  return 0;
}