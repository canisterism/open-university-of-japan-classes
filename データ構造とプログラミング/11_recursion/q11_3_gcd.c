#include <stdio.h>
#include <stdlib.h>

// 最大公約数（Greater Common Divider）を算出する
int gcd(int x, int y)
{
  printf("x: %d y: %d\n", x, y);
  if (x % y == 0)
  {
    return y;
  }
  return gcd(y, x % y);
}

int main()
{
  int x, y, divider;
  x = 100;
  y = 68;
  divider = gcd(x, y);
  printf("gcd(%d, %d)->%d\n", x, y, divider);
}
