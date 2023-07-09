#include <stdio.h>
#include <stdlib.h>

int factorial(int num)
{
  printf("num: %d\n", num);
  int result;
  if (num <= 1)
  {
    return 1;
  }
  result = num * factorial(num - 1);
  return result;
}

int main()
{
  int target, result;
  target = 5;
  result = factorial(target);
  printf("factorial(%d)->%d\n", target, result);
}
