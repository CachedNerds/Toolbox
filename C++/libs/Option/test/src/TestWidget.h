#ifndef _OPTION_TEST_WIDGET_H_
#define _OPTION_TEST_WIDGET_H_

namespace Toolbox {
namespace Option {
namespace Test {

class Widget {

public:
  Widget(void) = default;
  Widget(int index);

  const int& getIndex(void) const;
  void setIndex(const int& index);

private:
  int m_index;

};

} // Test
} // Option
} // Toolbox


#endif // _OPTION_TEST_WIDGET_H_
 

