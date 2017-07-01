#include "Logger.h"
#include "sinks/sync/ConsoleSink.h"
#include "sinks/Message.h"

#include <thread>
#include <functional>
#include <memory>
#include <map>

using namespace Toolbox::Log;

int main (void)
{
  using namespace Sinks::Sync;

  ConsoleSink consoleSink;
  Logger<std::string> logger (consoleSink);
  logger.info ("test");
  
  Message message ("message");
  logger.info (message);

  return 0;
}