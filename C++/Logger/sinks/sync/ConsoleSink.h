#ifndef _SYNC_CONSOLE_SINK_H_
#define _SYNC_CONSOLE_SINK_H_

#include "../BasicSink.h"

#include <string>
#include <mutex>

namespace Toolbox::Log::Sinks::Sync
{

class ConsoleSink : public BasicSink<std::string>
{
public:
  // StringSink
  void output (const std::string & output) override;

private:
  std::mutex _mut;
};

} // namespace Toolbox::Log::Sinks::Sync

#endif // _SYNC_CONSOLE_SINK_H_