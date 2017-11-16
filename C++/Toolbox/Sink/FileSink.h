#pragma once

#include <Toolbox/Sink/ThreadSafeSink.h>
#include <string>
#include <fstream>
#include <mutex>

namespace toolbox::sink
{

class FileSink : public ThreadSafeSink<std::string>
{
public:
  FileSink (const std::string & filename);

  bool isReady (void) const;
  bool changeFile (const std::string & filename);

protected:
  virtual void output (const std::string & output) override;

private:
  std::mutex _mutex;
  std::ofstream _file;
};

} // namespace toolbox::sink