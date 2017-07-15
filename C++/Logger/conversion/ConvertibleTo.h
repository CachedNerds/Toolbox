#ifndef _CONVERTIBLE_TO_H_
#define _CONVERTIBLE_TO_H_

namespace Toolbox::Log::Conversion
{

#include "../value_type_is.h"

template <typename ResultType>
class ConvertibleTo : public value_type_is <ResultType>
{
public:
  virtual operator ResultType (void) const = 0;
};

} // namespace Toolbox::Log::Conversion

#endif // _CONVERTIBLE_TO_H_
