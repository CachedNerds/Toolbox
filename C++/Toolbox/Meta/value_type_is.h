#pragma once

#include "type_is.h"

namespace toolbox::meta
{

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

} // namespace toolbox::meta