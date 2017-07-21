#ifndef _TEST_MESSAGE_H_
#define _TEST_MESSAGE_H_

#include <Toolbox/Conversion/ConvertibleTo.h>

#include <string>

using Toolbox::Log::Conversion::ConvertibleTo;

class TestMessage : public ConvertibleTo<std::string>
{
public:
  explicit TestMessage (const std::string & message);

  const operator std::string (void) const override;

private:
  const std::string _message;
};

#endif // _TEST_MESSAGE_H_