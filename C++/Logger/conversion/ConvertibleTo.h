#ifndef _CONVERTIBLE_TO_H_
#define _CONVERTIBLE_TO_H_

namespace Toolbox::Log::Conversion
{

#include "../metaprogramming/value_type_is.h"

template <typename ... ResultType>
class ConvertibleTo { };

template <typename ResultType, typename ... ResultTypes>
class ConvertibleTo <ResultType, ResultTypes ...> : public ConvertibleTo <ResultTypes ...>
{
public:
  virtual operator ResultType (void) const = 0;
};

} // namespace Toolbox::Log::Conversion

#endif // _CONVERTIBLE_TO_H_
