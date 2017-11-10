#pragma once

#include <Toolbox/Sink/BasicSink.h>
#include <mutex>

namespace toolbox::sink
{

template <typename OutputType>
class ThreadSafeSink : public BasicSink<OutputType>
{
public:
  virtual BasicSink<OutputType> & operator << (const OutputType & output) override
  {
    std::unique_lock<std::mutex> lock (_mutex);
    return BasicSink<OutputType>::operator << (output);
  }

protected:
  mutable std::mutex _mutex;
};

} // namespace toolbox::sink