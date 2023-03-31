#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10

int compare(const void *va, const void *vb)
{
  int a, b;
  a = *(const int *)va;
  b = *(const int *)vb;

  if (a < b)
  {
    return -1;
  }
  else if (a > b)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void print_array(int array[], int array_size)
{
  int i;
  for (i = 0; i < array_size; i++)
  {
    printf("%d", array[i]);
    printf("\n");
  }
}

// 二分探索する
int main(void)
{
  int array[ARRAY_SIZE] = {
      3,
      4,
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
  };
  int key = 12;
  int *result;

  print_array(array, ARRAY_SIZE);

  result = (int *)bsearch(&key, array, 10, sizeof(int), compare);

  if (result != NULL)
  {
    printf("Found %d", key);
  }
  else
  {
    printf("Not Found %d", key);
  }

  return 0;
}
