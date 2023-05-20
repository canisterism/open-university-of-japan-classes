#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

int main()
{
  NODE_TYPE *root_a;
  NODE_TYPE *root_b;

  root_a = build_btree();
  root_b = build_btree();

  if (is_equal_tree(root_a, root_b))
  {
    printf("is_equal_tree: true");
  }
  else
  {
    printf("is_equal_tree: false");
  }

  return 0;
}
