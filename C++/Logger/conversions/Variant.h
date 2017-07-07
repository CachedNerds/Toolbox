#ifndef _CONVERSION_VARIANT_H_
#define _CONVERSION_VARIANT_H_

#include "ConvertibleTo.h"
#include "VariantVisitor.h"

#include <boost/variant.hpp>

namespace Toolbox::Log::Conversion
{

template <typename ResultType>
class Variant
{
public:
  using type = boost::variant<const ResultType &, const ConvertibleTo<ResultType> &>;

  static const ResultType get (type variant)
  {
    VariantVisitor<ResultType> variantVisitor;
    return boost::apply_visitor (variantVisitor, variant);
  }
};

} // namespace Toolbox::Log::Conversion

#endif // _CONVERSION_VARIANT_H_