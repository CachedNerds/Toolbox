#include "TestSink.h"

void TestSink::output (const std::string & message)
{
  _message = message;
}

const std::string TestSink::getMessage (void) const
{
  return _message;
}