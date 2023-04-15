#include <stdio.h>
#define TABLE 9

// 九九の表を作る
int main(void)
{
  int array[TABLE][TABLE];
  int i, j;

  for (i = 0; i < TABLE; i++)
  {
    for (j = 0; j < TABLE; j++)
    {
      array[i][j] = (i + 1) * (j + 1);
    }
  }
  for (i = 0; i < TABLE; i++)
  {
    for (j = 0; j < TABLE; j++)
    {
      printf("%2d ", array[i][j]);
    }
    printf("\n");
  }

  return 0;
}
