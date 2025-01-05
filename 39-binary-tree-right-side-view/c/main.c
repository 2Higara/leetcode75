#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
// 每层先左后右遍历，直接写入对应的数组层，最右边的数可以覆盖掉左边的数
void traverse(struct TreeNode *root, int *rightList, int depth, int *maxdepth) {
  if (root == NULL) {
    return;
  }
  rightList[depth] = root->val;
  depth++;
  if (*maxdepth < depth)
    *maxdepth = depth;
  traverse(root->left, rightList, depth, maxdepth);
  traverse(root->right, rightList, depth, maxdepth);
}
int *rightSideView(struct TreeNode *root, int *returnSize) {
  int *rightList = malloc(100 * sizeof(int));
  *returnSize = 0;
  traverse(root, rightList, 0, returnSize);
  return rightList;
}
int main() {
  struct TreeNode a = {1, NULL, NULL};
  struct TreeNode b = {2, NULL, NULL};
  struct TreeNode c = {3, NULL, NULL};
  struct TreeNode d = {4, NULL, NULL};
  struct TreeNode e = {5, NULL, NULL};
  struct TreeNode f = {6, NULL, NULL};
  a.left = &b;
  b.right = &e;
  e.left = &f;
  a.right = &c;
  c.right = &d;
  int n = 0;
  int *rs = rightSideView(&a, &n);
  return 0;
}
