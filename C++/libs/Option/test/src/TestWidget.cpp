#include "TestWidget.h"

namespace toolbox::option::test
{
  
Widget::Widget(int index)
: _index(index) 
{

}

const int& Widget::getIndex(void) const {
  return _index;
}

void Widget::setIndex(const int& index) {
  _index = index;
}

} // namespace toolbox::option::test
  
