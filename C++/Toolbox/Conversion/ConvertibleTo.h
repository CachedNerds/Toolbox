#pragma once

#include <Toolbox/Meta/value_type_is.h>

namespace toolbox::conversion
{

template <typename ... ResultType>
class ConvertibleTo { };

template <typename ResultType, typename ... ResultTypes>
class ConvertibleTo <ResultType, ResultTypes ...> : public ConvertibleTo <ResultTypes ...>
{
public:
  using value_type = toolbox::meta::type_is_t <ResultType>;

  virtual operator ResultType (void) const = 0;
};

} // namespace toolbox::conversion