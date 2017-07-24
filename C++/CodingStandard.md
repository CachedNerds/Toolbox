# Toolbox C++ Coding Standard

A few rules to follow while developing with C++17.

## Namespaces
  - 1. All projects will have a single entry point in the `::toolbox` namespace.
    ```
    // namespace for Logger
    namespace Toolbox::Log {

    }
    ```
  - 1. Namespace names will CamelCase.
  - 1. Prefer C++17 style nested namespaces.
    ```
    // namespace Foo { namespace Bar { namesapce Baz { /*...*/ }}}
    namespace Foo::Bar::Baz { /*...*/ }
    ```

## Control Flow
  - 1. There will be a space before an if/for condition.
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

  - 2. Empty brackets shall contain a single empty line between them
    ```
    if (condition)
    {

    }
    ```

## Classes

  - 1. Prefer `class`es instead of `struct`s.
  - 1. No public member variables.
  - 1. Use PascalCase for `class` names.
  - 1. Use leading underscore for memeber variables names.
    ```
    class Foo
    {
      int _fooData;
    };
    ```
  - 1. camelCase class method names.
    ```
    class Foo
    {
    public:
      void doFooStuff (void) const;
    };
    ```
  - 1. Prefer `explicit` constructors. 
  - 1. Separate method name and argument list with space.
    ```
    class Foo
    {
    public:
      void doFooStuff (void) const;
    };
    ```
  - 1. Use `void` into parenthesis for methods with an empty parameter list.
    ```
    class Foo
    {
    public:
      void doFooStuff (void) const;
    };
    ```
