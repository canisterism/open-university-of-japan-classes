#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND -1

// 双方向連結リストの実装

typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
} NODE_TYPE;

void print_from_head(NODE_TYPE *node)
{
  printf("list from head:[ ");
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("]\n");
}

void print_from_tail(NODE_TYPE *node)
{
  printf("list from tail:[ ");
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->prev;
  }
  printf("]\n");
}

// リストの末尾にノードを挿入する
void append(NODE_TYPE **head, NODE_TYPE **tail, int data)
{
  // 新しいノードを作る
  NODE_TYPE *new_node;
  new_node = malloc(sizeof(NODE_TYPE));
  new_node->data = data;
  new_node->next = NULL;

  // リストが空の場合
  if (*head == NULL)
  {
    *head = *tail = new_node;
    new_node->prev = NULL;
    return;
  }
  // 末尾のノードを取得する
  NODE_TYPE *last_node = *tail;

  // 新しいノードを末尾に連結する
  last_node->next = new_node;
  new_node->prev = last_node;

  // 末尾のポインタを新しいノードに向ける
  *tail = new_node;
}

// ノードを先頭に挿入する
void prepend(NODE_TYPE **head, NODE_TYPE **tail, int data)
{
  NODE_TYPE *new_node;
  new_node = malloc(sizeof(NODE_TYPE));
  new_node->data = data;

  // リストが空の場合
  if (*head == NULL)
  {
    *head = *tail = new_node;
    new_node->prev = NULL;
    return;
  }

  // 先頭のノードを取得する
  NODE_TYPE *first_node = *head;
  // 新しいノードを先頭に連結する
  first_node->prev = new_node;
  new_node->next = first_node;

  // 先頭のポインタを新しいノードに向ける
  *head = new_node;
}

int main()
{
  NODE_TYPE *head, *tail;
  int i, data;
  head = tail = NULL;

  for (i = 0; i < 5; i++)
  {
    data = (int)rand() % 100;
    printf("appending %d...\n", data);
    append(&head, &tail, data);
    print_from_head(head);
  }

  for (i = 0; i < 5; i++)
  {
    data = (int)rand() % 100;
    printf("prepending %d...\n", data);
    prepend(&head, &tail, data);
    print_from_head(head);
  }

  return 0;
}
