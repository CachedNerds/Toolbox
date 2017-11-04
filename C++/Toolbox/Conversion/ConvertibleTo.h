#ifndef _CONVERTIBLE_TO_H_
#define _CONVERTIBLE_TO_H_

#include <Toolbox/Meta/value_type_is.h>

using Toolbox::Meta::type_is_t;

namespace Toolbox::Conversion
{

template <typename ... ResultType>
class ConvertibleTo { };

template <typename ResultType, typename ... ResultTypes>
class ConvertibleTo <ResultType, ResultTypes ...> : public ConvertibleTo <ResultTypes ...>
{
public:
  using value_type = type_is_t <ResultType>;

  virtual operator ResultType (void) const = 0;
};

} // namespace Toolbox::Conversion

#endif // _CONVERTIBLE_TO_H_
