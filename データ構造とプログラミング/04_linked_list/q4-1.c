#include <stdio.h>
#include <stdlib.h>
#define DATA_SIZE 6

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

void prepend_linked_list(NODE_TYPE **head, int data)
{
  NODE_TYPE *new_node;
  new_node = malloc(sizeof(NODE_TYPE));
  new_node->data = data;
  if (*head == NULL)
  {
    new_node->next = NULL;
    *head = new_node;
  }
  else
  {
    new_node->next = *head;
    *head = new_node;
  }
}

int main()
{
  NODE_TYPE *head;
  int i, data;

  head = NULL;

  for (i = 0; i < DATA_SIZE; i++)
  {
    printf("i is %d \n", i);

    data = (int)rand() % 100;
    printf("prepending %d \n", data);
    prepend_linked_list(&head, data);
  }
  print_linked_list(head);
  return 0;
}
