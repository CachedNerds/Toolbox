#ifndef _CONVERSION_RESULT_H_
#define _CONVERSION_RESULT_H_

#include "ConvertibleTo.h"

#include <boost/variant.hpp>

namespace Toolbox::Log::Conversion
{

template <typename ResultType>
class Result
{
protected:
  class VariantVisitor : public boost::static_visitor<const ResultType>
  {
  public:
    virtual const ResultType operator () (const ResultType & subject) const;
    virtual const ResultType operator () (const ConvertibleTo<ResultType> & subject) const;
  };

public:
  using Variant = boost::variant<const ResultType &, const ConvertibleTo<ResultType> &>;

  static const ResultType get (const Variant & result);
};

#include "Result.cpp"

} // namespace Toolbox::Log::Conversion

#endif // _CONVERSION_RESULT_H_