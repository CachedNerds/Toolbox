#ifndef SYNC_FILE_SINK_H
#define SYNC_FILE_SINK_H

#include "Sink.h"
#include <mutex>

namespace Toolbox::Log::Sinks
{

class SyncFileSink
{
public:
  SyncFileSink (const std::string & filename);

  // Sink
  void output (const std::string & message);

private:
  std::string filename_;
  std::mutex mut_;
};

} // namespace Toolbox::Log::Sinks

#endif // SYNC_FILE_SINK_H