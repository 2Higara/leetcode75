#include <stdio.h>
#include <stdlib.h>
int rob(int *nums, int numsSize) {
  if (numsSize < 4) {
    if (numsSize == 1) {
      return nums[0];
    }
    if (numsSize == 2) {
      return nums[0] > nums[1] ? nums[0] : nums[1];
    }
    if (numsSize == 3) {
      return (nums[0] + nums[2]) > nums[1] ? (nums[0] + nums[2]) : nums[1];
    }
  }
  int *sum = (int *)malloc(numsSize * sizeof(int));
  sum[0] = 0;
  sum[1] = 0;
  sum[2] = nums[0];
  int sum1, sum2;
  for (int i = 3; i < numsSize; i++) {
    sum1 = sum[i - 3] + nums[i - 3];
    sum2 = sum[i - 2] + nums[i - 2];
    sum[i] = sum1 > sum2 ? sum1 : sum2;
  }
  sum1 = sum[numsSize - 2] + nums[numsSize - 2];
  sum2 = sum[numsSize - 1] + nums[numsSize - 1];
  return sum1 > sum2 ? sum1 : sum2;
}
int main() {
#define NUMSSIZE 4
  int nums[NUMSSIZE] = {2, 1, 1, 2};
  printf("%d\n", rob(nums, NUMSSIZE));
}
