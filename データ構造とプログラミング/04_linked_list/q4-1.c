#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} NODE_TYPE;

void print_linked_list(NODE_TYPE *node)
{
  while (node != NULL)
  {
    printf("%d\n", node->data);
    node = node->next;
  }
}

int main()
{
  NODE_TYPE *head;
  head = malloc(sizeof(NODE_TYPE));
  head->data = 100;
  head->next = malloc(sizeof(NODE_TYPE));
  head->next->data = 200;
  head->next->next = malloc(sizeof(NODE_TYPE));
  head->next->next->data = 300;

  print_linked_list(head);
  return 0;
}
