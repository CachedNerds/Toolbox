#pragma once

namespace toolbox::meta
{

template <typename T>
struct inner_type
{
  using type = T;
};

template <template <typename> typename TT, typename T>
struct inner_type <TT <T>>
{
  using type = T;
};

template <template <typename ...> typename TT, typename T, typename ... Ts>
struct inner_type <TT <T, Ts ...>>
{
  using type = T;
};

template <typename ... Ts>
using inner_type_t = typename inner_type <Ts ...>::type;

} // namespace toolbox::meta