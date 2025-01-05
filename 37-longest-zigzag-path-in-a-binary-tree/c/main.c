#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
// direction: (current node->next node)'s direction
// direction = 1: right
// direction = 0: left
// cnt:  node cnt of current zigzag serial
void findMaxZigZagCnt(struct TreeNode *root, int direction, int cnt,
                      int *max_cnt) {

  if (root == NULL) {
    if (cnt > *max_cnt)
      *max_cnt = cnt;
    return;
  }
  cnt++;
  if (direction == 1) { // 右向
    // 这里如果不用 1 和 0，而是使用 direction 和 !direction
    // 来表示方向，取反操作也会增加运行时间消耗(从 0ms 到 8ms)
    findMaxZigZagCnt(root->right, 0, cnt, max_cnt); // 遍历右侧，保持计数
    findMaxZigZagCnt(root->left, 1, 1, max_cnt); // 遍历左侧，重新计数
  } else {
    findMaxZigZagCnt(root->left, 1, cnt, max_cnt);
    findMaxZigZagCnt(root->right, 0, 1, max_cnt);
  }
}
int longestZigZag(struct TreeNode *root) {
  int max_cnt = 0;
  findMaxZigZagCnt(root, 0, 0, &max_cnt);
  return max_cnt - 1;
}
int main() {
  struct TreeNode a = {1, NULL, NULL};
  struct TreeNode b = {2, NULL, NULL};
  // struct TreeNode c = {1, NULL, NULL};
  a.left = &b;
  // b.right = &c;
  printf("%d\n", longestZigZag(&a));
  return 0;
}
