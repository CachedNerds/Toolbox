#ifndef _OUTPUT_VISITOR_H_
#define _OUTPUT_VISITOR_H_

#include "Outputable.h"

#include <boost/variant.hpp>

namespace Toolbox::Log::Outputs
{

template <typename OutputType>
class OutputVisitor : public boost::static_visitor<OutputType>
{
public:
  virtual const OutputType operator () (const OutputType & output) const;
  virtual const OutputType operator () (const Outputable<OutputType> & output) const;
};

#include "OutputVisitor.cpp"

} // namespace Toolbox::Log::Outputs

#endif // _OUTPUT_VISITOR_H_