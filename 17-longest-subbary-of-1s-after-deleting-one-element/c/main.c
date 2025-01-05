#include <stdio.h>
// 思路：
// 1. 用辅助数组存储成员两侧的连续1长度，找出两侧长度和最大的成员，时间 O2n,
// 空间 On
// 2. 用双指针遍历原始数组，时间 On, 空间 O1
// 边界情况：
// 1. 全 1, 返回 len-1
// 2. 全 0, 返回 0
// 3. 最后一位为1
// 4. 第一位为1
#if 0 // 双指针 控制起来好麻烦啊，边界条件还多
// 初始状态：l指向第一个1，r=l；如果没有1，返回 0
// 中间状态：
// r遇1向右遍历，如果遇0 ：
// r 向右遍历，遇0删除0，继续遍历再遇0，结算长度，更新l到第一个0右侧
// 结束状态：
// r 遇右边界, 结算长度
int longestSubarray(int *nums, int numsSize) {
  int *l = nums, *r = nums, *numsEnd = nums + numsSize;
  while (r < numsEnd) {
    if (*r == 1) {
      l = r;
      break;
    }
    r++;
  }
  // 1 1 1 1 1
  // 0 0 0 0 0
  // 1 0 0 0 0
  // 0 0 1 0 0
  // 0 1 0 0 0
  // 1 0 1 0 0
  // 1 0 1 1 0
  int len = r - l, max = len;
  int dFlg = 0, *dPos;
  while (r < numsEnd) {
    if (*r == 0) {
      if (dFlg == 0) {
        dFlg = 1;
        dPos = r;
        r++;
      } else {
        dFlg = 0;
        len = r - l - 1;
        max = len>max?len:max;
        l = dPos + 1;
        r++;
      }
    } else {
      r++;
    }
  }
  return max; 
}
#endif
#if 1 // 辅助数组
int longestSubarray(int *nums, int numsSize) {
  int l[numsSize];
  l[0] = 0;
  int cnt = 0;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i - 1]) {
      cnt++;
    } else {
      cnt = 0;
    }
    l[i] = cnt;
  }
  cnt = 0;
  int max = l[numsSize - 1];
  for (int i = numsSize - 2; i >= 0; i--) {
    if (nums[i + 1]) {
      cnt++;
    } else {
      cnt = 0;
    }
    max = cnt + l[i] > max ? cnt + l[i] : max;
  }
  return max;
}
int main() {
  int nums[100], numsSize = 0;
  while (scanf("%d", &nums[numsSize++])) {
    if (getchar() == '\n') {
      break;
    }
  }
  printf("%d\n", longestSubarray(nums, numsSize));
  return 0;
}
#endif
