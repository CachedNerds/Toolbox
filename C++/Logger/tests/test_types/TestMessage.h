#ifndef _TEST_MESSAGE_H_
#define _TEST_MESSAGE_H_

#include "../../conversion/ConvertibleTo.h"

#include <string>

using Toolbox::Log::Conversion::ConvertibleTo;

class TestMessage : public ConvertibleTo<std::string, int>
{
public:
  explicit TestMessage (const std::string & message);

  operator std::string (void) const;

  operator int (void) const;

private:
  const std::string _message;
};

#endif // _TEST_MESSAGE_H_
