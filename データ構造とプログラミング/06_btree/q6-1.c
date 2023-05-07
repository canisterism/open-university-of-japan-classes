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

int main()
{
  NODE_TYPE *root;

  root = malloc(sizeof(NODE_TYPE));
  root->data = 40;

  root->left = malloc(sizeof(NODE_TYPE));
  root->left->data = 30;

  root->right = malloc(sizeof(NODE_TYPE));
  root->right->data = 70;

  root->left->left = malloc(sizeof(NODE_TYPE));
  root->left->left->data = 10;
  root->left->right = NULL;

  root->left->left->left = NULL;
  root->left->left->right = malloc(sizeof(NODE_TYPE));
  root->left->left->right->data = 20;
  root->left->left->right->left = NULL;
  root->left->left->right->right = NULL;

  root->right->left = malloc(sizeof(NODE_TYPE));
  root->right->left->data = 60;
  root->right->left->left = NULL;
  root->right->left->right = NULL;

  root->right->right = malloc(sizeof(NODE_TYPE));
  root->right->right->data = 90;
  root->right->right->left = NULL;
  root->right->right->right = NULL;

  print_btree(root, 0);
  printf("\n");

  printf("traversal_preorder: ");
  traversal_preorder(root);
  printf("\n");
  printf("traversal_inorder: ");
  traversal_inorder(root);
  printf("\n");
  printf("traversal_postorder: ");
  traversal_postorder(root);
  printf("\n");

  return 0;
}
