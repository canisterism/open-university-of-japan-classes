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

int find_node(NODE_TYPE **head, int data)
{
  NODE_TYPE *tmp = *head;

  // 長さ0ならスキップ
  if (tmp->next == NULL)
  {
    printf("The list is empty. %d is not found.\n", data);
  }

  // ノードを走査してデータを探す
  while (tmp->next != NULL)
  {
    if (tmp->data == data)
    {
      return tmp->data;
    }
    tmp = tmp->next;
  }

  // データが見つからない場合
  printf("%d is not found.\n", data);
  return NOT_FOUND;
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

NODE_TYPE *find_last_node(NODE_TYPE **head)
{
  NODE_TYPE *tmp = *head;
  while (tmp->next != NULL)
  {
    tmp = tmp->next;
  }
  return tmp;
}

void append_linked_list(NODE_TYPE **head, int data)
{
  NODE_TYPE *new_node;
  NODE_TYPE *last_node;

  // 新しいノードを作成してメモリを確保する
  new_node = malloc(sizeof(NODE_TYPE));
  new_node->data = data;
  new_node->next = NULL;

  // リストが空なら先頭をnew_nodeにする
  if (*head == NULL)
  {
    *head = new_node;
    return;
  }

  // リスト内の最後のノードのポインタを新しいノードに向ける
  last_node = find_last_node(head);
  last_node->next = new_node;
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
  NODE_TYPE *head;
  int data;

  head = NULL;
  prepend_linked_list(&head, 0);
  prepend_linked_list(&head, 100);
  prepend_linked_list(&head, 200);
  prepend_linked_list(&head, 300);
  print_linked_list(head);

  printf("returned data is: %d\n", find_node(&head, 1));

  remove_first_node(&head);

  print_linked_list(head);
  printf("This linked list's length is %d\n", length(&head));

  append_linked_list(&head, 1000);
  print_linked_list(head);
  return 0;
}
