#include <stdio.h>
double findMaxAverage(int *nums, int numsSize, int k) {
  double sum = 0;
  for (int i = 0; i < k; i++) {
    sum += nums[i];
  }
  double max = sum;
  for (int i = 1; i < numsSize - k + 1; i++) {
    sum += nums[i + k - 1];
    sum -= nums[i - 1];
    max = sum > max ? sum : max;
  }
  return max / k;
}
int main() {
  int nums[10] = {0}, numsSize = 0;
  while (scanf("%d", &nums[numsSize++])) {
    if (getchar() == '\n')
      break;
  }
  int k;
  scanf("%d", &k);
  printf("%lf\n", findMaxAverage(nums, numsSize, k));
  return 0;
}
