#ifndef _CONVERSION_VARIANT_H_
#define _CONVERSION_VARIANT_H_

#include "ConvertibleTo.h"

#include <boost/variant.hpp>

namespace Toolbox::Log::Conversion
{

template <typename ResultType>
class ConversionVariant
{
public:
  using type = boost::variant<const ResultType &, const ConvertibleTo<ResultType> &>;
};

} // namespace Toolbox::Log::Conversion

#endif // _CONVERSION_VARIANT_H_