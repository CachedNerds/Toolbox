#include "Prod.h"
#include "Dev.h"

#include <iostream>
#include <memory>

int main (void)
{
  auto env = std::make_unique <Prod>();

  std::cout << env->getEnv() << "\n";

  return 0;
}
