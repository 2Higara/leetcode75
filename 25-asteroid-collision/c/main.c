#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 正数：入栈
// 负数：
// 栈顶为空，入栈
// 栈顶不为空：
//// 栈顶是负数，入栈
//// 栈顶是正数，求和
////// 和是正数，不入栈
////// 结果是 0，出栈
////// 结果是负数，出栈，负数继续和栈顶比较
void stack_op(int *stack, int *cnt, int neg) {
  if (*cnt == 0) { // 栈为空，入栈
    stack[(*cnt)++] = neg;
    return;
  }
  if (stack[*cnt - 1] < 0) { // 栈不为空，栈顶为负数，入栈
    stack[(*cnt)++] = neg;
    return;
  }
  int sum = stack[*cnt - 1] + neg;
  if (sum == 0) { // 栈不为空，栈顶为等大正数，出栈
    (*cnt)--;
    return;
  }
  if (sum > 0) { // 栈不为空，栈顶为更大正数，无操作
    return;
  }
  if (sum < 0) { // 栈不为空，栈顶为更小正数，出栈，继续栈操作
    (*cnt)--;
    stack_op(stack, cnt, neg);
  }
}
int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize) {
  int *rs = (int *)malloc(asteroidsSize * sizeof(int)), cnt = 0;
  for (int i = 0; i < asteroidsSize; i++) {
    if (asteroids[i] > 0) { // 正数
      rs[cnt++] = asteroids[i];
    } else { // 负数
      stack_op(rs, &cnt, asteroids[i]);
    }
  }
  *returnSize = cnt;
  return rs;
}
int main() {
  // int asteroidsSize = 3, asteroids[3] = {5, 10, -5};
  // int asteroidsSize = 2, asteroids[2] = {8, -8};
  int asteroidsSize = 3, asteroids[3] = {10, 2, -5};
  int returnSize;
  int *rs = asteroidCollision(asteroids, asteroidsSize, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", rs[i]);
  }
}
