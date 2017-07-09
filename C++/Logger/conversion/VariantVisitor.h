#ifndef _VARIANT_VISITOR_H_
#define _VARIANT_VISITOR_H_

#include "ConvertibleTo.h"

#include <boost/variant/static_visitor.hpp>

namespace Toolbox::Log::Conversion
{

template <typename ResultType>
class VariantVisitor : public boost::static_visitor<const ResultType>
{
public:
  virtual const ResultType operator () (const ResultType & subject) const;
  virtual const ResultType operator () (const ConvertibleTo<ResultType> & subject) const;
};

#include "VariantVisitor.cpp"

} // namespace Toolbox::Log::Conversion

#endif // _VARIANT_VISITOR_H_