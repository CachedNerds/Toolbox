#ifndef _VALUE_TYPE_IS_H_
#define _VALUE_TYPE_IS_H_

#include "TypeIs.h"

template <typename T>
struct ValueTypeIs
{
  using value_type = typename TypeIs <T>::type;
};

template <template <typename> typename TT, typename T>
struct ValueTypeIs <TT<T>>
{
  using value_type = typename TypeIs <T>::type;
};

template <template <typename ...> typename TT, typename T, typename ... Ts>
struct ValueTypeIs <TT<T, Ts ...>>
{
  using value_type = typename TypeIs <T>::type;
};

#endif // _VALUE_TYPE_IS_H_
