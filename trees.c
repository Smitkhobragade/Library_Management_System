#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *createNode()
{
  TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
  if (new != NULL)
    return new;
  else
    return NULL;
}

TreeNode *search1(TreeNode *root, int key)
{
  if (root == NULL)
    return root;
  else if (root->data < key)
    return search1(root->right, key);
  else if (root->data > key)
    return search1(root->left, key);
  else if (root->data == key)
  {
    printf("THE DATA IS PRESENT\n");
    return (root);
  }
}

TreeNode *search(TreeNode *root, int key)
{
  TreeNode *temp = search1(root, key);
  if (temp == NULL)
    printf("THE DATA IS NOT PRESENT\n");
  return temp;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
  if (root == NULL)
    return NULL;
  else if (key < (root->data))
    root->left = deleteNode(root->left, key);
  else if (key > (root->data))
    root->right = deleteNode(root->right, key);
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      free(root);
      return NULL;
    }
    else if (root->left == NULL)
    {
      TreeNode *temp = root->right;
      free(root);
      return (temp);
    }
    else if (root->right == NULL)
    {
      TreeNode *temp = root->left;
      free(root);
      return (temp);
    }
    else
    {
      TreeNode *temp = root->right;
      while (temp->left != NULL)
        temp = temp->left;

      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  return (root);
}

TreeNode *insertNode(TreeNode *root, int key)
{
  if (root == NULL)
  {
    root = createNode();
    if (root == NULL)
    {
      printf("ALLOCATION FAILED\n");
      return (root);
    }
    else
    {
      root->data = key;
      root->left = NULL;
      root->right = NULL;
      return (root);
    }
  }
  else
  {
    if (key < (root->data))
      root->left = insertNode(root->left, key);
    else if (key > (root->data))
      root->right = insertNode(root->right, key);
  }
  return (root);
}
void inorder(TreeNode *root)
{
  if (root == NULL)
    return;

  inorder(root->left);
  printf("%d\t", root->data);
  inorder(root->right);
}
void preorder(TreeNode *root)
{
  if (root == NULL)
    return;

  printf("%d\t", root->data);
  preorder(root->left);
  preorder(root->right);
}
void postorder(TreeNode *root)
{
  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  printf("%d\t", root->data);
}
void print_inorder(TreeNode *root)
{
  printf("---------- INORDER SEQUENCE ----------\n");
  inorder(root);
  printf("\n");
}
void print_preorder(TreeNode *root)
{
  printf("---------- PREORDER SEQUENCE ----------\n");
  preorder(root);
  printf("\n");
}
void print_postorder(TreeNode *root)
{
  printf("---------- POSTORDER SEQUENCE ----------\n");
  postorder(root);
  printf("\n");
}
void print_level(TreeNode *root, int level)
{
  if (root == NULL)
    return;
  else if (level == 1)
    printf("%d\t", root->data);
  else if (level > 1)
  {
    print_level(root->left, level - 1);
    print_level(root->right, level - 1);
  }
}
int countNodes(TreeNode *root)
{
  if (root == NULL)
    return 0;
  else
    return countNodes(root->left) + countNodes(root->right) + 1;
}
int heightTree(TreeNode *root)
{
  if (root == NULL)
    return 0;
  else
  {
    int lh = heightTree(root->left);
    int rh = heightTree(root->right);

    if (lh < rh)
      return (rh + 1);
    else
      return (lh + 1);
  }
}
void print_Height(TreeNode *root)
{
  printf("The Height of the Tree is : %d\n", heightTree(root));
}
void print_Nodes(TreeNode *root)
{
  printf("The No. of Nodes in the Tree is : %d\n", countNodes(root));
}
void print_levelOrder(TreeNode *root)
{
  printf("---------- LEVEL-ORDER SEQUENCE ----------\n");
  int h = heightTree(root);
  for (int i = 1; i <= h; i++)
    print_level(root, i);
  printf("\n");
}