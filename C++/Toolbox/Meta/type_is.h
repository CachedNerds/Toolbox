#pragma once

namespace toolbox::meta
{

template <typename T>
struct type_is
{
  using type = T;
};

template <template <typename> typename TT, typename T>
struct type_is <TT <T>>
{
  using type = TT <T>;
};

template <template <typename ...> typename TT, typename T, typename ... Ts>
struct type_is <TT <T, Ts ...>>
{
  using type = TT <T, Ts ...>;
};

template <typename ... Ts>
using type_is_t = typename type_is <Ts ...>::type;

} // namespace toolbox::meta