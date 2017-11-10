#pragma once

#include <Toolbox/Sink/BasicSink.h>
#include <Toolbox/Sink/ThreadSafeSink.h>
#include <memory>
#include <type_traits>

namespace toolbox::sink
{

template <typename SinkType,
          typename OutputType = typename SinkType::value_type,
          typename = typename std::enable_if<std::is_base_of<BasicSink<OutputType>, SinkType>::value>::type>
class ThreadSafeProxySink : public ThreadSafeSink<OutputType>
{
public:
ThreadSafeProxySink (SinkType sink)
: _sink (std::move (sink))
{

}

ThreadSafeProxySink (ThreadSafeProxySink && sink)
: _sink (std::move (sink._sink))
{

}

ThreadSafeProxySink & operator= (ThreadSafeProxySink && sink)
{
  _sink = std::move (sink._sink);
}

/**
 * Synchronization is performed within the ThreadSafeSink base class's operator << method.
 * Forward the output to the inner Sink.
 */
virtual void output (const OutputType & output) override
{
  _sink << output;
}

protected:
  SinkType _sink;
};

template <typename SinkType,
          typename OutputType = typename SinkType::value_type,
          typename... Args,
          typename = typename std::enable_if<std::is_base_of<BasicSink<OutputType>, SinkType>::value>::type>
auto make_thread_safe (Args&&... args)
{
  return ThreadSafeProxySink<SinkType> (SinkType (std::forward<Args> (args)...));
}

template <typename SinkType,
          typename OutputType = typename SinkType::value_type,
          typename... Args,
          typename = typename std::enable_if<std::is_base_of<BasicSink<OutputType>, SinkType>::value>::type>
auto make_unique_thread_safe (Args&&... args)
{
  return std::make_unique<ThreadSafeProxySink<SinkType>> (SinkType (std::forward<Args> (args)...));
}

} // namespace toolbox::sink