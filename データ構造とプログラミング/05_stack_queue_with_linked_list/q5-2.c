#include <stdio.h>
#include <stdlib.h>
#define STACK_UNDERFLOW -1

typedef struct node
{
  int data;
  struct node *next;
} NODE_TYPE;

void enqueue(NODE_TYPE **head, NODE_TYPE **tail, int data)
{
  NODE_TYPE *new_node;
  new_node = malloc(sizeof(NODE_TYPE));
  new_node->data = data;
  new_node->next = NULL;

  // キューが空のとき
  if (*tail == NULL)
  {
    *head = *tail = new_node;
  }
  else
  {
    (*tail)->next = new_node; // 古い末尾ノードのnextはnew_nodeに向ける
    *tail = new_node;         // tailのポインタはnew_nodeに向ける
  }
}

int dequeue(NODE_TYPE **head, NODE_TYPE **tail)
{
  NODE_TYPE *tmp;
  int data;
  if (*head == NULL)
  {
    return STACK_UNDERFLOW;
  }

  tmp = *head;          // 取り出すノード
  data = (*head)->data; // 取り出すデータ

  // 取り出した結果キューが空になるとき（headとtailが同じノードを指す=1つしかノードがないとき）
  if (*head == *tail)
  {
    // NULLに向けておく
    *head = *tail = NULL;
  }
  else // 取り出しても1つ以上ノードが残るとき
  {
    *head = (*head)->next; // headの向け先を2つ目のノードに変える
  }

  free(tmp);
  return data;
}

void print_queue(NODE_TYPE *head)
{
  printf("queue: [ ");
  while (head != NULL)
  {
    printf("%d ", head->data);
    head = (head)->next;
  }
  printf("]\n");
}

int main()
{
  NODE_TYPE *head, *tail;
  int data, i;
  head = NULL;
  tail = NULL;
  for (i = 0; i < 5; i++)
  {
    data = (int)rand() % 100;
    enqueue(&head, &tail, data);
  }

  print_queue(head);

  for (i = 0; i < 2; i++)
  {
    printf("%d dequeued,\n", dequeue(&head, &tail));
  }

  print_queue(head);
  return 0;
}
