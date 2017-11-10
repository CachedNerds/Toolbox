#pragma once

namespace toolbox::option::test
{

class Widget
{
public:
  Widget (void) = default;
  Widget (int index);

  const int & getIndex (void) const;
  void setIndex (const int & index);

private:
  int _index;
};

} // namespace toolbox::option::test