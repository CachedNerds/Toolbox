#include <Toolbox/catch.hpp>
#include <Toolbox/Option/Option.h>
#include "TestWidget.h"

TEST_CASE("create a Some")
{
  using namespace toolbox;
  using toolbox::option::test::Widget;

  // create a widget with index 10
  auto widgetOption = option::Some<Widget>(10);

  int x = 0;
  widgetOption.ifPresent([&x](const Widget& widget) {
    x = widget.getIndex();
  });

  REQUIRE(x == 10);

  bool isSome = static_cast<bool>(widgetOption);
  REQUIRE(isSome);
}

TEST_CASE("Create a Some from a new instance")
{
  using namespace toolbox;
  using toolbox::option::test::Widget;

  auto pWidget = new Widget{5};
  // widgetOption now owns pWidget
  auto widgetOption = option::Option(pWidget);

  int x = 0;
  widgetOption.ifPresent([&x](const Widget& widget) {
    x = widget.getIndex();
  });

  REQUIRE(x == 5);
  bool isSome = static_cast<bool>(widgetOption);
  REQUIRE(isSome);
}

TEST_CASE("Create a None from a nullptr")
{
  using namespace toolbox;
  using toolbox::option::test::Widget;

  Widget* pWidget = nullptr;
  auto widgetOption = option::Option(pWidget);

  int x = 0;
  widgetOption.ifPresent([&x](const Widget& widget) {
    x = widget.getIndex();
  });

  // forEach fails so x never changes
  REQUIRE(x == 0);
  bool isNone = !static_cast<bool>(widgetOption);
  REQUIRE(isNone);
}

TEST_CASE("Map a widget with index 5 to index 10")
{
  using namespace toolbox;
  using toolbox::option::test::Widget;

  // create a widget with index 5
  int widgetIndex = 5;
  auto widgetOption = option::Some<Widget>(widgetIndex);
  // reset this variable for later
  widgetIndex = 0;

  // map the widget, there is now a new widgetOption 
  auto newWidgetOption = widgetOption.map([](Widget widget) { 
    widget.setIndex(10);
    return widget; 
  });

  // assign the new widget index so we can compare it later
  int newWidgetIndex = 0;
  newWidgetOption.ifPresent([&newWidgetIndex](const Widget& widget) {
    newWidgetIndex = widget.getIndex();
  });


  // check the old widget to make sure it hasn't changed
  widgetOption.ifPresent([&widgetIndex](const Widget& widget) {
    widgetIndex = widget.getIndex();
  });

  // widget still has index 5
  REQUIRE(widgetIndex == 5);

  // new widget has updated index 10
  REQUIRE(newWidgetIndex == 10);
}

TEST_CASE("Filter an option by index") 
{
  using namespace toolbox;
  using toolbox::option::test::Widget;

  // create a widget with index 5
  int widgetIndex = 5;
  auto widgetOption = option::Some<Widget>(widgetIndex);

  // filter by a condition that retains the value, e.g. index 5 is greater than 0
  widgetOption = widgetOption.filter([](const Widget& widget) {
    auto& index = widget.getIndex();
    if (index > 0) {
      return true;
    }
    else {
      return false;
    }
  });

  // still some
  bool isSome = static_cast<bool>(widgetOption);
  REQUIRE(isSome == true);

  // filter by a non-retaining condition e.g. index 5 is less than 0
  widgetOption = widgetOption.filter([](const Widget& widget) {
    auto& index = widget.getIndex();
    if (index < 0) {
      return true;
    }
    else {
      return false;
    }
  });

  // now none
  bool isNone = !static_cast<bool>(widgetOption);

  REQUIRE(isNone == true);
}
