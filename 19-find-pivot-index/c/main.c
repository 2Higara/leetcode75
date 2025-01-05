
#if 0
int pivotIndex(int *nums, int numsSize) {
  int sum = 0;
  for (int i = 0; i < numsSize; i++) {
    sum += nums[i];
  }
  int left = 0, right = sum - nums[0];
  if (left == right)
    return 0;
  for (int i = 1; i < numsSize; i++) {
    left += nums[i - 1];
    right -= nums[i];
    if (left == right) {
      return i;
    }
  }
  return -1;
}
#endif
#include <stdlib.h>
#include <string.h>
int pivotIndex(int *nums, int numsSize) {
  int sum = 0;
  for (int i = 0; i < numsSize; i++)
    sum += nums[i];
  int left = 0;
  for (int i = 0; i < numsSize; i++) {
    if (left + left + nums[i] == sum) {
      return i;
    } else {
      left += nums[i];
    }
  }
  return -1;
}
