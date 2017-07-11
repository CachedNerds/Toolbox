#ifndef _CONVERTIBLE_TO_H_
#define _CONVERTIBLE_TO_H_

namespace Toolbox::Log::Conversion
{

template <typename ResultType>
class ConvertibleTo
{
public:
  using result_type = ResultType;

  virtual const operator ResultType (void) const = 0;
};

} // namespace Toolbox::Log::Conversion

#endif // _OUTPUTABLE_H_