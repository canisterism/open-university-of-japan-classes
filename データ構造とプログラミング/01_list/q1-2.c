#include <stdio.h>

int main(void)
{
  int i, j, k;
  int a[2][3][4] = {
      {
          {1, 2, 3, 4},
          {5, 6, 7, 8},
          {9, 10, 11, 12},
      },
      {
          {2, 4, 6, 8},
          {10, 12, 14, 16},
          {18, 20, 22, 24},
      }};
  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 3; j++)
    {
      for (k = 0; k < 4; k++)
      {
        printf("array[%d][%d][%d]=%4d\n", i, j, k, a[i][j][k]);
      }
    }
  }
  return 0;
}
