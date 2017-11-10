# Toolbox C++ Coding Standard

A few rules to follow while developing with C++17.

## Namespaces
  1. All namespaces will be snake_case. (e.g. `example_namespace`)
  2. All projects will have a single entry point in the `::toolbox` namespace.
  ```
  // namespace for Logger
  namespace toolbox::log { }
  ```
  3. Prefer C++17 style nested namespaces.
  ```
  // namespace foo { namespace bar { namespace baz { /*...*/ }}}
  namespace foo::bar::baz { /*...*/ }
  ```
  4. All namespaces will have the curly brace on the following line.
  ```
  namespace toolbox
  {
  
  } // namespace toolbox
  ```
  5. All namespaces will be followed by a ```// namespace name``` after the closing brace.
  ```
  namespace toolbox::sink
  {
  
  } // namespace toolbox::sink
  ```

## Control Flow
  1. There will be a space before a conditional statement
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

## Function calls
  1. There will be no space between function names and their parameter lists.
  ```
  int total = sum(4, 5);
  ```

## Classes

  1. Prefer `class`es instead of `struct`s.
  2. No public member variables.
  3. Use PascalCase for `class` names.
  4. Use leading underscore for member variables names.
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
  8. Add `void` in parenthesis for methods with an empty parameter list.
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
  3. Template metafunctions will be `struct`s and use the `snake_case`.
  ```
  template<typename T>
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
