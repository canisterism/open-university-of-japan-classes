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
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

void remove_first_node(NODE_TYPE **head)
{
  NODE_TYPE *tmp;
  if (head == NULL || *head == NULL)
  {
    return;
  }
  tmp = *head;
  *head = (*head)->next;

  free(tmp);
}

void remove_last_node(NODE_TYPE **head)
{
  NODE_TYPE *tmp = *head;
  NODE_TYPE *previous;

  if (head == NULL || *head == NULL)
  {
    printf("The list is empty. Nothing to delete.");
    return;
  }

  if (tmp->next == NULL)
  {
    printf("The last node was deleted.: %d \n", tmp->data);
    *head = NULL;
    free(tmp);
    return;
  }

  while (tmp->next != NULL)
  {
    previous = tmp;
    tmp = tmp->next;
  }
  previous->next = NULL;
  printf("The last node deleted.: %d \n", tmp->data);
  free(tmp);
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
    data = (int)rand() % 100;
    printf("prepending %d \n", data);
    prepend_linked_list(&head, data);
  }
  print_linked_list(head);
  remove_first_node(&head);
  print_linked_list(head);
  remove_first_node(&head);
  print_linked_list(head);
  remove_first_node(&head);
  print_linked_list(head);

  remove_last_node(&head);
  print_linked_list(head);
  // remove_last_node(&head);
  // print_linked_list(head);
  // remove_last_node(&head);
  // print_linked_list(head);
  // remove_last_node(&head);
  // print_linked_list(head);

  return 0;
}
