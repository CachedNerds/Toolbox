#include "Production.h"
#include "Development.h"

#include <iostream>
#include <memory>

int main (void)
{
  auto env = Development();
  std::cout << env.getEnvironment() << "\n";

  return 0;
}
