#ifndef _CONVERTIBLE_TO_H_
#define _CONVERTIBLE_TO_H_

namespace Toolbox::Log::Conversion
{

#include "../type_is.h"

template <typename ResultType>
class ConvertibleTo : public type_is <ResultType>
{
public:
  virtual const operator ResultType (void) const = 0;
};

} // namespace Toolbox::Log::Conversion

#endif // _OUTPUTABLE_H_
