#ifndef _OPTION_H_
#define _OPTION_H_

#include <functional>
#include <memory>
#include <type_traits>

namespace Toolbox::Option {

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
      return Option::Opt<T>(std::move(std::make_unique<T>(std::forward<Args>(args)...)));
    }

    // Create a None<T>
    static Opt None()
    {
      return Option::Opt<T>();
    }

    // Create an Option from a pointer
    // None<T> if is nullptr
    // Else Some<T>
    static Opt Option(T* t)
    {
      return Option::Opt<T>(std::move(std::unique_ptr<T>(t)));
    }

  private:
    // Hidden constructors - one can't instantiate an Opt directly, only the class can
    Opt(void) = default;
    Opt(std::unique_ptr<T> p) : m_pData(std::move(p)) {};

  public:
    // No copy constructor available, explicitly delete so that it so intent is clear
    Opt(const Opt&) = delete;

  public:
    // operator bool for quick check
    operator bool() const {
      return (m_pData != nullptr);
    };

  public:
    // forEach - read the value if it exists
    void forEach(std::function<void(const T&)> forEachFunction) {
      if (m_pData)
        forEachFunction(*m_pData.get());
    };

    // map - concrete for mapping to the same type, saves one from typing the template parameter
    Opt<T> map(std::function<T(T t)> mapFunction) {
      return Opt::map<T>(mapFunction);
    };

    // map<T,U>  - map from an Opt<T> to an Opt<U>
    // if is None<T>, then returns None<U>
    // else returns Some<U>
    template<typename U>
    Opt<U> map(std::function<U(T)> mapFunction) {
      static_assert(std::is_copy_constructible_v<U> == true, "Target type must be copy constructible.");
      if (m_pData) {
        auto u = mapFunction(*m_pData);
        U* pU = new U(u);
        return Opt<U>::Option(pU);
      }
      else {
        return Opt<U>::None();
      }
    };

    // filter<T> - retains the option based on a predicate. Returns a new option. 
    Opt<T> filter(std::function<bool(const T&)> filterFunction) {
      if (m_pData) {
        bool retain = filterFunction(*m_pData);
        return (retain) ? Opt<T>::Option(new T(*m_pData)) : Opt<T>::None();
      }
      else {
        return Opt<T>::None();
      }
    };

  private:
    // the underlying data as a unique_ptr
    std::unique_ptr<T> m_pData;

  }; // end of class Opt<T>

  // The Some<T> function alias for Opt<T>::Some
  template<typename T, typename... Args>
  Opt<T> Some(Args... args) {
    return Option::Opt<T>::Some(std::forward<Args>(args)...);
  }

  // The None<T> function alias for Opt<T>::None
  template<typename T>
  Opt<T> None() {
    return Option::Opt<T>::None();
  }
 
  // The Option<T> function alias for Opt<T>::Option
  template<typename T>
  Opt<T> Option(T* t) {
    return Option::Opt<T>::Option(t);
  }

} // Toolbox::Option

#endif // _OPTION_H_