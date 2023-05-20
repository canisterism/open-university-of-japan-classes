#include <stdio.h>
#include <stdlib.h>

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

// 行きがけ走査
// root→left→right
void traversal_preorder(NODE_TYPE *node)
{
  if (node == NULL)
  {
    return;
  }
  printf("%2d ", node->data);
  traversal_preorder(node->left);
  traversal_preorder(node->right);
}

// 通りがけ走査
// left→root→right
void traversal_inorder(NODE_TYPE *node)
{
  if (node == NULL)
  {
    return;
  }
  traversal_inorder(node->left);
  printf("%2d ", node->data);
  traversal_inorder(node->right);
}

// 帰りがけ走査
// left→right→root
void traversal_postorder(NODE_TYPE *node)
{
  if (node == NULL)
  {
    return;
  }
  traversal_postorder(node->left);
  traversal_postorder(node->right);
  printf("%2d ", node->data);
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

NODE_TYPE *find_max_node(NODE_TYPE *node)
{
  if (node->right == NULL)
  {
    return node;
  }
  return find_max_node(node->right);
}

NODE_TYPE *find_min_node(NODE_TYPE *node)
{
  if (node->left == NULL)
  {
    return node;
  }
  return find_min_node(node->left);
}

NODE_TYPE *delete_node(NODE_TYPE *node, int data)
{
  NODE_TYPE *tmp;
  printf("current node.data is %d\n", node->data);

  if (node == NULL)
  {
    printf("data %d is not found", data);
  }
  else if (data < node->data)
  {
    node->left = delete_node(node->left, data);
  }
  else if (data > node->data)
  {
    node->right = delete_node(node->right, data);
  }
  // 削除対象が現在のノードの時は子の数で処理を変える
  else
  {
    // 子が2つの時
    if (node->right && node->left)
    {
      // 左のmaxか右のminを昇格させる
      tmp = node;
      node = find_max_node(node->left);
      node->right = tmp->right;
      free(tmp);
    }
    // 子が right にだけいる時
    else if (node->right != NULL)
    {
      tmp = node->right;
      node = node->right;
      free(tmp);
    }
    // 子が left にだけいる時
    else if (node->left != NULL)
    {
      tmp = node->left;
      node = node->left;
      free(tmp);
    }
    // 子がいない時
    else
    {
      tmp = node->left;
      node = node->left;
      free(tmp);
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

int main()
{
  NODE_TYPE *root;
  int target_number;
  NODE_TYPE *found_node;

  root = build_btree();
  print_btree(root, 0);
  printf("\n");

  target_number = 40;
  printf("target number is %d\n", target_number);

  root = delete_node(root, target_number);
  print_btree(root, 0);
  printf("\n");
  return 0;
}
