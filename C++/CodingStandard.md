# Toolbox C++ Coding Standard

A few rules to follow while developing with C++17.

## Namespaces
  1. All projects will have a single entry point in the `::toolbox` namespace.
  ```
  // namespace for Logger
  namespace Toolbox::Log { }
  ```
  2. Namespace names will CamelCase.
  3. Prefer C++17 style nested namespaces.
  ```
  // namespace Foo { namespace Bar { namesapce Baz { /*...*/ }}}
  namespace Foo::Bar::Baz { /*...*/ }
  ```

## Control Flow
  1. There will be a space before an if/for condition.
  ```
  if (condition)
  {

  }
  ```
  ```
  for (condition)
  {

  }
  ```
  ```
  while (condition)
  {

  }
  ```
  ```
  do
  {

  } while (condition);
  ```

  2. Empty brackets shall contain a single empty line between them
  ```
  if (condition)
  {

  }
  ```

## Classes

  1. Prefer `class`es instead of `struct`s.
  2. No public member variables.
  3. Use PascalCase for `class` names.
  4. Use leading underscore for memeber variables names.
  ```
  class Foo
  {
    int _fooData;
  };
  ```
  5. camelCase class method names.
  ```
  class Foo
  {
  public:
    void doFooStuff (void) const;
  };
  ```
  6. Prefer `explicit` constructors. 
  7. Separate method name and argument list with space.
  ```
  class Foo
  {
  public:
    void doFooStuff (void) const;
  };
  ```
  8. Use `void` into parenthesis for methods with an empty parameter list.
  ```
  class Foo
  {
  public:
    void doFooStuff (void) const;
  };
  ```

## Templates and Template Metaprogramming
  1. `template` keyword and template arguments go on line above the template definition, declaration, or statement.
  ```
  template<typename FooType>
  class Foo;

  template<int N>
  class Bar;
  ```
  2. Prefer `typename` to `class` when writing templates.
  3. Template metafunctions will be `struct`s and use the `underscore_case`.
  ```
  template <typename T>
  struct value_type_is;
  ```

  4. Template parameter type names will be `PascalCase` and end with the word `Type` **when a descriptive name is required**. Otherwise normal type names will be a single letter starting e.g. `T`, `U`. 
  ```
  // explicit name required for template intent
  template<typename FooType>
  class Foo;

  template<typename T>
  class Bar;

  template<typename T, typename U>
  class Baz;
  ```
