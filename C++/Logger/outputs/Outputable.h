#ifndef _OUTPUTABLE_H_
#define _OUTPUTABLE_H_

namespace Toolbox::Log::Outputs
{

template <typename OutputType>
class Outputable
{
public:
  virtual const OutputType toOutput (void) const = 0;
};

} // namespace Toolbox::Log::Outputs

#endif // _OUTPUTABLE_H_