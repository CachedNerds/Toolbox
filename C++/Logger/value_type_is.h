#ifndef _VALUE_TYPE_H_
#define _VALUE_TYPE_H_

#include "type_is.h"

template <typename T>
struct value_type
{
  using value_type = type_is <T>::type;
};

template <template <typename> typename TT, typename T>
struct value_type <TT<T>>
{
  using value_type = type_is <T>::type;
};

template <template <typename ...> typename TT, typename T, typename ... Ts>
struct value_type <TT<T, Ts ...>>
{
  using value_type = type_is <T>::type;
};

#endif // _VALUE_TYPE_H_
