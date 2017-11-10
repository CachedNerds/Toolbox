#pragma once

#include <functional>
#include <memory>
#include <type_traits>

// is_copy_constructible_v alias for older compilers like GCC 6.4
namespace std
{
  template<typename T>
  constexpr bool is_copy_constructible_v = std::is_copy_constructible<T>::value;
} // namespace std

namespace toolbox::option
{

/* The fundamental class describing an Option. Users only collect the Opt<T> as a result and do
   do not instantiate this class directly. The static methods Some, None, and Option have 
   standalone function aliases for convenience.

   The underlying data structure is a std::unique_ptr. An Opt<T> is move only. 

   The fundamental operations are forEach, map, and filter. `forEach` simply allows access to the
   underlying data if it is Some. `map` and `filter` allow access and modification of the Opt<T>.
*/ 
template<typename T>
class Opt
{
public:
  // forward arguments to construct a Some<T>
  template<typename... Args>
  static Opt Some(Args... args)
  {
    return Opt<T>(std::make_unique<T>(std::forward<Args>(args)...));
  }

  // Create a None<T>
  static Opt None()
  {
    return Opt<T>();
  }

  // Create an Option from a pointer
  // None<T> if is nullptr
  // Else Some<T>
  static Opt Option(T* t)
  {
    return Opt<T>(std::move(std::unique_ptr<T>(t)));
  }

private:
  // Hidden constructors - one can't instantiate an Opt directly, only the class can
  Opt(void) = default;
  Opt(std::unique_ptr<T> p) : _data(std::move(p)) {};

public:
  // No copy constructor available, explicitly delete so that it so intent is clear
  Opt(const Opt&) = delete;
  Opt(Opt&&) = default;

  // prevent implicit deletion by being explicit
  Opt& operator=(const Opt& other) = delete;
  Opt& operator=(Opt&& other) = default;

public:
  // operator bool for quick check
  operator bool() const {
    return (_data != nullptr);
  };

public:
  // ifPresent - read the value if it exists
  void ifPresent(std::function<void(const T&)> ifPresentFunction) {
    if (_data)
      ifPresentFunction(*_data.get());
  };

  // map - concrete for mapping to the same type, saves one from typing the template parameter
  Opt<T> map(std::function<T(T t)> mapFunction) {
    return Opt::map<T>(mapFunction);
  };

  // map<T,U>  - map from an Opt<T> to an Opt<U>
  // Not available if the type T is not copy constructible
  // if is None<T>, then returns None<U>
  // else returns Some<U>
  template<typename U, typename = typename std::enable_if<std::is_copy_constructible_v<T> == true>::type>
  Opt<U> map(std::function<U(T)> mapFunction) {
    static_assert(std::is_copy_constructible_v<U> == true, "Target type must be copy constructible.");
    if (_data) {
      auto u = mapFunction(*_data);
      U* pU = new U(u);
      return Opt<U>::Option(pU);
    }
    else {
      return Opt<U>::None();
    }
  };

  // filter<T> - retains the option based on a predicate. Returns a new option. 
  Opt<T> filter(std::function<bool(const T&)> filterFunction) {
    if (_data) {
      bool retain = filterFunction(*_data);
      return (retain) ? Opt<T>::Option(new T(*_data)) : Opt<T>::None();
    }
    else {
      return Opt<T>::None();
    }
  };

private:
  // the underlying data as a unique_ptr
  std::unique_ptr<T> _data;

}; // end of class Opt<T>

// The Some<T> function alias for Opt<T>::Some
template<typename T, typename... Args>
Opt<T> Some(Args&&... args) {
  return Opt<T>::Some(std::forward<Args>(args)...);
}

// The None<T> function alias for Opt<T>::None
template<typename T>
Opt<T> None() {
  return Opt<T>::None();
}

// The Option<T> function alias for Opt<T>::Option
template<typename T>
Opt<T> Option(T* t) {
  return Opt<T>::Option(t);
}

} // namespace toolbox::option