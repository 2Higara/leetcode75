#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define MIN -30
#define LEN 1000
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
  int product_left[numsSize], product_right[numsSize];
  product_left[0] = 1;
  product_right[numsSize - 1] = 1;
  for (int i = 1, j = numsSize - 2; i < numsSize; i++, j--) {
    product_left[i] = product_left[i - 1] * nums[i - 1];
    product_right[j] = product_right[j + 1] * nums[j + 1];
  }
  int *rs = (int *)malloc(sizeof(int) * numsSize);
  for (int i = 0; i < numsSize; i++) {
    rs[i] = product_left[i] * product_right[i];
  }
  *returnSize = numsSize;
  return rs;
}
int main() {
  int nums[LEN] = {0}, numsSize;
  scanf("%d", &numsSize);
  for (int i = 0; i < numsSize; i++) {
    scanf("%d", &nums[i]);
  }
  int *rs, rsSize;
  rs = productExceptSelf(nums, numsSize, &rsSize);
  for (int i = 0; i < rsSize; i++) {
    printf("%d ", rs[i]);
  }
  printf("\n");
  free(rs);
  return 0;
}
