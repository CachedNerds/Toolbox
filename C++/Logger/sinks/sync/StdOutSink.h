#ifndef SYNC_STD_OUT_SINK_H
#define SYNC_STD_OUT_SINK_H

#include "../Sink.h"
#include <string>
#include <mutex>

namespace Toolbox::Log::Sinks::Sync
{

class StdOutSink : public Sink
{
public:
  // Sink
  void output (const std::string & message);

private:
  std::mutex mut_;
};

} // namespace Toolbox::Log::Sinks::Sync

#endif // SYNC_STD_OUT_SINK_H