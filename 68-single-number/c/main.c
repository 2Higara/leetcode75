#include <stdio.h>
int singleNumber(int *nums, int numsSize) {
  int rs = nums[0];
  for (int i = 1; i < numsSize; i++) {
    rs = rs ^ nums[i];
  }
  return rs;
}
int main() {
#define LEN 5
  int nums[LEN] = {4, 1, 2, 1, 2};
  printf("%d\n", singleNumber(nums, LEN));
}
