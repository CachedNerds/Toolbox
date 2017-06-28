#include "Logger.h"
#include "sinks/sync/StdOutSink.h"
#include <thread>
#include <functional>
#include <memory>
#include <map>

using namespace Toolbox::Log;

int main (void)
{
  Sinks::Sync::StdOutSink syncStdOutSink;
  Logger logger (syncStdOutSink);

  std::thread threads[7];
  std::string messages[] {"My", "name", "is", "DJ", "Scrum", "Master", "Peck"};

  // spawn 7 threads:
  for (int i=0; i < 7; ++i)
    threads[i] = std::thread (&Logger::log, logger, Severity::Level::INFO, messages[i]);

  for (auto & th : threads) th.join ();

  logger.debug ("debug");
  logger.fatal ("fatal");

  return 0;
}