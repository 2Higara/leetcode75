#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int traverse(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q,
             struct TreeNode **rs) {
  if (root == NULL)
    return 0;
  int cnt = (root == p || root == q) + traverse(root->left, p, q, rs) +
            traverse(root->right, p, q, rs);
  if (cnt == 2) {
    *rs = root;
    cnt++;
  }
  return cnt;
}
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p,
                                      struct TreeNode *q) {
  struct TreeNode *rs = NULL;
  traverse(root, p, q, &rs);
  return rs;
}
int main() {
  struct TreeNode a = {1, NULL, NULL};
  return 0;
}
