#include <stdio.h>
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void search(struct TreeNode *root, struct TreeNode **rs, int val) {
  if (root == NULL)
    return;
  if (root->val == val)
    *rs = root;
  search(root->left, rs, val);
  search(root->right, rs, val);
}
struct TreeNode *searchBST(struct TreeNode *root, int val) {
  struct TreeNode *rs = NULL;
  search(root, &rs, val);
  return rs;
}
