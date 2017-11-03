#include <Toolbox/Sink/FileSink.h>
#include <exception>

namespace Toolbox::Sink
{

FileSink::FileSink (const std::string & filename)
: _mutex ()
, _file (filename)
{

}

bool FileSink::isReady (void) const
{
  bool isReady = false;
  try
  {
    isReady = _file.good () && _file.is_open ();
  } catch (const std::exception & e)
  {
    // isReady stays false
  }

  return isReady;
}

bool FileSink::changeFile (const std::string & filename)
{
  bool success = false;
  std::unique_lock<std::mutex> lock (_mutex);
  try
  {
    _file.close ();
    _file.open (filename);
    success = this->isReady ();
  } catch (const std::exception & e)
  {
    // absorb exception
  }

  return success;
}

void FileSink::output (const std::string & output)
{
  if (this->isReady ())
    _file << output;
}

} // namespace Toolbox::Sink