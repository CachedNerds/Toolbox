#ifndef SYNC_STD_OUT_SINK_H
#define SYNC_STD_OUT_SINK_H

#include "Sink.h"
#include <string>
#include <mutex>

namespace Toolbox::Log::Sinks
{

class SyncStdOutSink : public Sink
{
public:
  void output (const std::string & value);

private:
  std::mutex mut_;
};

} // namespace Toolbox::Log::Sinks

#endif // STD_OUT_SINK_H