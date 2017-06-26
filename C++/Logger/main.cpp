#include "Logger.h"
#include "SyncStdOutSink.h"
#include <thread>
#include <functional>

using namespace Toolbox::Log;

int main (void)
{
  SyncStdOutSink syncStdOutSink;
  Logger logger (syncStdOutSink);

  std::thread threads[7];
  std::string messages[] {"My", "name", "is", "DJ", "Scrum", "Master", "Peck"};

  // spawn 7 threads:
  for (int i=0; i < 7; ++i)
    threads[i] = std::thread (&Logger::log, logger, Severity::Level::INFO, messages[i]);

  for (auto & th : threads) th.join ();

  return 0;
}