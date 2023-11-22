#include <stdio.h>
#include "prototype/logic_a/logic_a.hpp"

int main()
{
  int a;
  sandbox::prototype::LogicA logic_a;
  logic_a.aFunction(3);
  printf("Hola");
  return 0;
}
