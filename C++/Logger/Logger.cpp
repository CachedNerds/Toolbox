#include <ctime>

template <typename OutputType>
Logger<OutputType>::Logger (BasicSink<OutputType> & sink)
: _sink (sink)
{
  
}

template <typename OutputType>
void Logger<OutputType>::log (const Severity::Level & level, const OutputType & output) const
{
  if (level >= this->_threshold)
  {
    std::string timestamp = this->getCurrentTime ();
    this->_sink << "{" << "timestamp: " << timestamp << ", "
                       << "level: " << Severity::toString (level) << ", "
                       << "message: " << output << "}\n";
  }
}

template <typename OutputType>
void Logger<OutputType>::log (const Severity::Level & level, const Output<OutputType> & output) const
{
  if (level >= this->_threshold)
  {
    std::string timestamp = this->getCurrentTime ();
    this->_sink << "{" << "timestamp: " << timestamp << ", "
                       << "level: " << Severity::toString (level) << ", "
                       << "message: " << output << "}\n";
  }
}

template <typename OutputType>
void Logger<OutputType>::trace (const OutputType & output) const
{
  this->log (Severity::Level::TRACE, output);
}

template <typename OutputType>
void Logger<OutputType>::trace (const Output<OutputType> & output) const
{
  this->log (Severity::Level::TRACE, output);
}

template <typename OutputType>
void Logger<OutputType>::debug (const OutputType & output) const
{
  this->log (Severity::Level::DEBUG, output);
}

template <typename OutputType>
void Logger<OutputType>::debug (const Output<OutputType> & output) const
{
  this->log (Severity::Level::DEBUG, output);
}

template <typename OutputType>
void Logger<OutputType>::info (const OutputType & output) const
{
  this->log (Severity::Level::INFO, output);
}

template <typename OutputType>
void Logger<OutputType>::info (const Output<OutputType> & output) const
{
  this->log (Severity::Level::INFO, output);
}

template <typename OutputType>
void Logger<OutputType>::warning (const OutputType & output) const
{
  this->log (Severity::Level::WARNING, output);
}

template <typename OutputType>
void Logger<OutputType>::warning (const Output<OutputType> & output) const
{
  this->log (Severity::Level::WARNING, output);
}

template <typename OutputType>
void Logger<OutputType>::error (const OutputType & output) const
{
  this->log (Severity::Level::ERROR, output);
}

template <typename OutputType>
void Logger<OutputType>::error (const Output<OutputType> & output) const
{
  this->log (Severity::Level::ERROR, output);
}

template <typename OutputType>
void Logger<OutputType>::fatal (const OutputType & output) const
{
  this->log (Severity::Level::FATAL, output);
}

template <typename OutputType>
void Logger<OutputType>::fatal (const Output<OutputType> & output) const
{
  this->log (Severity::Level::FATAL, output);
}

template <typename OutputType>
void Logger<OutputType>::setThreshold (const Severity::Level & threshold)
{
  this->_threshold = threshold;
}

template <typename OutputType>
Severity::Level Logger<OutputType>::getThreshold (void) const
{
  return this->_threshold;
}

template <typename OutputType>
std::string Logger<OutputType>::getCurrentTime (void) const
{
  std::time_t now = std::chrono::system_clock::to_time_t (std::chrono::system_clock::now ());
  std::string timestamp (std::ctime (&now));
  return timestamp.substr (0, timestamp.length () - 1);
}