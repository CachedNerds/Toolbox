#ifndef _VALUE_TYPE_IS_H_
#define _VALUE_TYPE_IS_H_

#include "type_is.h"

template <typename T>
struct value_type_is
{
  using value_type = typename type_is <T>::type;
};

template <template <typename> typename TT, typename T>
struct value_type_is <TT <T>>
{
  using value_type = typename type_is <T>::type;
};

template <template <typename ...> typename TT, typename T, typename ... Ts>
struct value_type_is <TT <T, Ts ...>>
{
  using value_type = typename type_is <T>::type;
};

#endif // _VALUE_TYPE_IS_H_
