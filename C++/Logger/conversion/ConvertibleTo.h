#ifndef _CONVERTIBLE_TO_H_
#define _CONVERTIBLE_TO_H_

namespace Toolbox::Log::Conversion
{

#include "../ValueTypeIs.h"

template <typename ResultType>
class ConvertibleTo : public ValueTypeIs <ResultType>
{
public:
  virtual operator ResultType (void) const = 0;
};

} // namespace Toolbox::Log::Conversion

#endif // _OUTPUTABLE_H_
