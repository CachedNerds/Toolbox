#ifndef _TYPE_IS_H_
#define _TYPE_IS_H_

template <typename T>
struct type_is
{
  using type = T;
};

template <template <typename> typename TT, typename T>
struct type_is <TT<T>>
{
  using type = T;
};

template <template <typename ...> typename TT, typename T, typename ... Ts>
struct type_is <TT<T, Ts ...>>
{
  using type = T;
};

#endif
