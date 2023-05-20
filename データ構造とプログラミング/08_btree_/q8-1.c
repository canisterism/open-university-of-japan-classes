#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

typedef struct Node NODE_TYPE;

void print_btree(NODE_TYPE *node, int level)
{
  int i;
  if (node == NULL)
  {
    return;
  }

  print_btree(node->right, level + 1);
  printf("\n");
  for (i = 0; i < level; i++)
  {
    printf("_");
  }
  printf("%d", node->data);
  print_btree(node->left, level + 1);
}

NODE_TYPE *find_tree_node(NODE_TYPE *node, int data)
{
  if (node == NULL)
  {
    return NULL;
  }

  printf("find_tree_node: Current node's data is: %d \n", node->data);

  // ほしいノードの数字が訪れたノードより小さければleft
  if (data < node->data)
  {
    return find_tree_node(node->left, data);
  }
  // ほしいノードの数字が訪れたノードより大きればright
  if (data > node->data)
  {
    return find_tree_node(node->right, data);
  }
  return node;
}

NODE_TYPE *insert_node(NODE_TYPE *node, int data)
{

  if (node == NULL)
  {
    node = malloc(sizeof(NODE_TYPE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
  }
  else
  {
    printf("comparing %d and %d ...\n", data, node->data);
    // 挿入したいデータが現在のノード値よりも小さい時
    if (data < node->data)
    {
      node->left = insert_node(node->left, data);
    }
    // 挿入したいデータが現在のノード値よりも大きい時
    else if (data > node->data)
    {
      node->right = insert_node(node->right, data);
    }
  }
  return node;
}
NODE_TYPE *build_btree()
{
  int data[] = {40, 30, 70, 10, 60, 90, 20, 15};
  int i;
  NODE_TYPE *root;
  root = NULL;

  for (i = 0; i < 8; i++)
  {
    root = insert_node(root, data[i]);
  }
  return root;
}

// 木全体を削除する。
// 帰りがけ走査で葉から順番に削除する。
void delete_tree(NODE_TYPE *node)
{
  if (node == NULL)
  {
    return;
  }

  delete_tree(node->left);
  delete_tree(node->right);
  free(node);
}

bool is_equal_tree(NODE_TYPE *a, NODE_TYPE *b)
{
  if (a == NULL && b == NULL)
  {
    return true;
  }
  else if (a->data == b->data)
  {
    return is_equal_tree(a->left, b->left) && is_equal_tree(a->right, b->right);
  }
  else
  {
    return false;
  }
}

void shuffle(int array[], int size)
{
  srand(time(NULL));
  int i, tmp, index;
  // 実装はランダムに2つの数字を交換し続けているだけ
  for (i = 0; i < size; i++)
  {
    index = rand() % size;   // 1. 交換する要素の添字をランダムに得る
    tmp = array[i];          // 2. iの添字の要素を取っておく
    array[i] = array[index]; // 3. 1で得た添字の要素をiの場所にコピーする
    array[index] = tmp;      // 4. iだったデータを1の場所にコピーして交換が完了する
  }
}

int main()
{
  NODE_TYPE *root;
  int *array;
  int array_size, i;

  array_size = 10;
  array = malloc(sizeof(int) * array_size);

  // 0~10000までを配列で作る
  for (i = 0; i < array_size; i++)
  {
    array[i] = i;
  }

  shuffle(array, array_size);

  root = malloc(sizeof(NODE_TYPE));
  root->data = 6;
  for (i = 0; i < array_size; i++)
  {
    printf("insert %d \n", array[i]);
    insert_node(root, array[i]);
  }

  print_btree(root, 0);

  // root_a = build_btree();
  // root_b = build_btree();

  return 0;
}
