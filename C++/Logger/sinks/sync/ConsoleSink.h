#ifndef _SYNC_CONSOLE_SINK_H_
#define _SYNC_CONSOLE_SINK_H_

#include "../Sink.h"

#include <string>
#include <mutex>

namespace Toolbox::Log::Sinks::Sync
{

class ConsoleSink : public Sink
{
public:
  // Sink
  void output (const std::string & message);

private:
  std::mutex _mut;
};

} // namespace Toolbox::Log::Sinks::Sync

#endif // _SYNC_CONSOLE_SINK_H_