#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// 两重递归，第一层递归负责一次性遍历整个二叉树，并在各成员的位置调用功能函数
// 功能函数也是以递归实现，负责当前成员到二叉树末梢的遍历，并计算一路上的成员和
void cntPathSum(struct TreeNode *root, int *cnt, long sum, int targetSum) {
  if (root == NULL) {
    return;
  }
  sum += root->val;
  if (sum == targetSum) {
    (*cnt)++;
  }
  cntPathSum(root->left, cnt, sum, targetSum);
  cntPathSum(root->right, cnt, sum, targetSum);
}
void traverse(struct TreeNode *root, int *cnt, int targetSum) {
  if (root == NULL) {
    return;
  }
  cntPathSum(root, cnt, 0, targetSum);
  traverse(root->left, cnt, targetSum);
  traverse(root->right, cnt, targetSum);
}
int pathSum(struct TreeNode *root, int targetSum) {
  int cnt = 0;
  traverse(root, &cnt, targetSum);
  return cnt;
}
int main() {
  struct TreeNode a = {1, NULL, NULL};
  struct TreeNode b = {2, NULL, NULL};
  struct TreeNode c = {3, NULL, NULL};
  struct TreeNode d = {4, NULL, NULL};
  a.right = &b;
  b.right = &c;
  c.right = &d;
  int n = pathSum(&a, 3);
  printf("%d\n", n);
  return 0;
}
