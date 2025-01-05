#include <stdio.h>
#define LEN 10000
// 交换
// 0 1 0 3 4
// 0 1 2 3 0
// 1 2 3 0 0 0 4 5 6
void moveZeroes(int *nums, int numsSize) {
  int cnt = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != 0) {
      if (nums[cnt] == 0) {
        nums[cnt] = nums[i];
        nums[i] = 0;
      }
      cnt++;
    }
  }
}
int main() {
  int nums[LEN];
  int numsSize = 0;
  while (scanf("%d", &nums[numsSize++])) {
    if (getchar() == '\n')
      break;
  }
  moveZeroes(nums, numsSize);
  for (int i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}
