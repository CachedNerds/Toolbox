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
