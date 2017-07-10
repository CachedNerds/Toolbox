#ifndef _TEST_MESSAGE_H_
#define _TEST_MESSAGE_H_

#include "../../conversion/ConvertibleTo.h"

#include <string>

using Toolbox::Log::Conversion::ConvertibleTo;

class TestMessage : public ConvertibleTo<std::string>
{
public:
  explicit TestMessage (const std::string & message);

  const std::string convert (void) const override;

private:
  const std::string _message;
};

#endif // _TEST_MESSAGE_H_