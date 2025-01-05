#include <stdio.h>
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
#define MIN -10001
int cntGoodNodes(struct TreeNode *root, int max) {
  if (root == NULL)
    return 0;
  int is_good = 0;
  if (root->val >= max) {
    max = root->val;
    is_good = 1;
  }
  return is_good + cntGoodNodes(root->left, max) +
         cntGoodNodes(root->right, max);
}
int goodNodes(struct TreeNode *root) { return cntGoodNodes(root, MIN); }
