#include "TestWidget.h"

namespace Toolbox {
namespace Option {
namespace Test {
  
    Widget::Widget(int index) : m_index(index) 
    { 
    }

    const int& Widget::getIndex(void) const {
      return m_index;
    }

    void Widget::setIndex(const int& index) {
      m_index = index;
    } 
  
} // Test
} // Option
} // Toolbox
  
