/*
Given the binary Tree and the two nodes say ‘a’ and ‘b’, determine whether the
two nodes are cousins of each other or not. Two nodes are cousins of each other
if they are at same level and have different parents.

Example:

     6
   /   \
  3     5
 / \   / \
7   8 1   3
Say two node be 7 and 1, result is TRUE.
Say two nodes are 3 and 5, result is FALSE.
Say two nodes are 7 and 5, result is FALSE.

The idea is to find level of one of the nodes. Using the found level, check if
‘a’ and ‘b’ are at this level. If ‘a’ and ‘b’ are at given level, then finally
check if they are not children of same parent. Following is the implementation
of the above approach.

*/
#include "BinaryTree.h"
using namespace std;

// Assumption No node label is repeated all discrete and different

bool isSibling(Node *root, int a, int b) {
  if (root == NULL)
    return false;
  return (root->left != NULL && root->right != NULL) &&
         ((root->left->data == a && root->right->data == b) ||
          (root->left->data == b && root->right->data == a) ||
          isSibling(root->left, a, b) || isSibling(root->right, a, b));
}

int atlevel(Node *root, int a, int level) {
  if (root == NULL)
    return 0;
  if (root->data == a)
    return level;
  int l = atlevel(root->left, a, level + 1);
  if (l != 0)
    return l;
  return atlevel(root->right, a, level + 1);
}

bool isCousin(Node *root, int c1, int c2) {
  return ((atlevel(root, c1, 1) == atlevel(root, c2, 1)) &&
          !(isSibling(root, c1, c2)));
}

int main(int argc, const char **argv) {

  Node *R;
  makeR1(&R);

  isCousin(R, 4, 5) ? cout << "\nYES, Cousin!!\n"
                    : cout << "\nNo is also an answer!!\n";

  return 0;
}