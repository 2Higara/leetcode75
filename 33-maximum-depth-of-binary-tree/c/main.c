
#include <stdio.h>
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// root->left && root->right 均为 NULL，返回 0
// 返回
int maxDepth(struct TreeNode *root) {
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL) {
    return 1;
  } else {
    if (root->left == NULL) {
      return 1 + maxDepth(root->right);
    } else if (root->right == NULL) {
      return 1 + maxDepth(root->left);
    } else {
      int l_dep = maxDepth(root->left), r_dep = maxDepth(root->right);
      return 1 + (l_dep > r_dep ? l_dep : r_dep);
    }
  }
}
