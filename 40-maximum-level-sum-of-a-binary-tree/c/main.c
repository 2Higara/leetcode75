#include <limits.h>
#include <stdlib.h>
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
#define MAX 10000
void traverse(struct TreeNode *root, int *levelSum, int depth, int *max_depth) {
  if (root == NULL)
    return;
  levelSum[depth] += root->val;
  depth++;
#if 0 // 问号表达式会把时间从 0 ms 增加到 8 ms
  *max_depth=depth>*max_depth?depth:*max_depth;
#endif
  if (depth > *max_depth) {
    *max_depth = depth;
  }

  traverse(root->left, levelSum, depth, max_depth);
  traverse(root->right, levelSum, depth, max_depth);
}
int maxLevelSum(struct TreeNode *root) {
  int *levelSum = (int *)calloc(MAX, sizeof(int));
  int max_depth = 0;
  traverse(root, levelSum, 0, &max_depth);
  int maxSum = levelSum[0], maxLevel = 0;
  for (int i = 0; i < max_depth; i++) {
    if (levelSum[i] > maxSum) {
      maxLevel = i;
      maxSum = levelSum[i];
    }
  }
  return maxLevel + 1;
}
