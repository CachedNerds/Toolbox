#ifndef _TYPE_IS_H_
#define _TYPE_IS_H_

template <typename T>
struct TypeIs
{
  using type = T;
};

template <template <typename> typename TT, typename T>
struct TypeIs <TT<T>>
{
  using type = T;
};

template <template <typename ...> typename TT, typename T, typename ... Ts>
struct TypeIs <TT<T, Ts ...>>
{
  using type = T;
};

#endif // _TYPE_IS_H_
