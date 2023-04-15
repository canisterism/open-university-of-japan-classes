#include <stdio.h>
#include <stdlib.h>
#define MAX 128

void stack_init(int *top)
{
  *top = 0;
}

// int pop(int stack[], int *top, int *data)
// {
//   if (*top > 0)
//   {
//     *data = stack[(*top) - 1];
//     (*top)--;
//     return POP_SUCCESS;
//   }
//   else
//   {＝＝
//     // empty stack
//     return POP_FAILURE;
//   }
// }

int main(void)
{
  int stack[MAX];
  int top, data;
  int i, length;
  char str[128];

  sprintf(str, "%s", "This is Open University of Japan.");

  length = strlen(str);

  stack_init(&top);
  for (i = 0; i < length; i++)
  {
    push(stack, &top, str[i]);
  }

  // stack_init(&top);
  // data = 300;
  // printf("push: %d\n", data);
  // push(stack, &top, data);
  // data = 400;
  // printf("push: %d\n", data);

  return 0;
}
