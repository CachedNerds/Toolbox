#ifndef _SYNC_STD_OUT_SINK_H_
#define _SYNC_STD_OUT_SINK_H_

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

#endif // _SYNC_STD_OUT_SINK_H_