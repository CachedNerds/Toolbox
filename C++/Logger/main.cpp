#include "Logger.h"
#include "sinks/sync/ConsoleSink.h"

#include <thread>
#include <functional>
#include <memory>
#include <map>

using namespace Toolbox::Log;

int main (void)
{
  using namespace Sinks::Sync;
  ConsoleSink consoleSink;
  Logger logger (consoleSink);

  std::string messages[] {"My", "name", "is", "Danny", "Peck", "The", "Third"};
  for (std::string word : messages)
  {
    logger.info (word);
  }

  logger.debug ("debug");
  logger.fatal ("fatal");

  return 0;
}