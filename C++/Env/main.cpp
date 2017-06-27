#include "Production.h"
#include "Development.h"

#include <iostream>
#include <memory>

int main (void)
{
  auto env = std::make_unique <Production>();

  std::cout << env->getEnvironment() << "\n";

  return 0;
}
