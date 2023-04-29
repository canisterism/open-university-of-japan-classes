#include <stdio.h>
#include <stdlib.h>
#define DATA_SIZE 6
#define NOT_FOUND -1

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

void push(NODE_TYPE **head, int data)
{
  NODE_TYPE *new_node;
  new_node = malloc(sizeof(NODE_TYPE)); // 追加するノードのメモリ確保
  new_node->data = data;                // データを格納する
  new_node->next = *(head);             // 新しいノードのnextにもともとの先頭ノードを向ける
  *head = new_node;                     // 先頭ノードを新しいノードに向ける
}

int pop(NODE_TYPE **head)
{
  NODE_TYPE *tmp;
  int data;
  tmp = (*head);         // popされるノードを取り出す
  data = (*head)->data;  // popされたノードのデータを取り出す
  *head = (*head)->next; // 先頭のポインタを2つ目のノードに向ける
  free(tmp);
  return data;
}

int length(NODE_TYPE **head)
{
  NODE_TYPE *tmp = *head;
  int count = 0;
  while (tmp != NULL)
  {
    count++;
    tmp = tmp->next;
  }
  return count;
}

int main()
{
  NODE_TYPE *stack;
  int data;
  stack = NULL;
  push(&stack, 100);
  push(&stack, 200);
  push(&stack, 300);
  push(&stack, 400);

  print_linked_list(stack);

  printf("%d is popped.\n", pop(&stack));
  print_linked_list(stack);
  return 0;
}
