#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define LEN 100000
#define MAX 1000000000
// k = 2
// 4 4 1 3 1 3 2 2 5 5 1 5 2 1 2 3 5 4
#if 0
// 90ms 109MB
int maxOperations(int *nums, int numsSize, int k) {
  int *a = calloc(k, sizeof(int));
  int r = 0;
  for (int i = 0; i < numsSize; i++) {
    int t = nums[i];
    if (t < k) {
      if (a[k - t - 1] > 0) {
        r++;
        a[k - t - 1]--;
      } else {
        a[t - 1]++;
      }
    }
  }
  return r;
}
#endif
#if 1
// 1560ms
int maxOperations(int *nums, int numsSize, int k) {
  if (numsSize == 1) {
    return (int)(nums[0] == k);
  }
  int cnt = 0;
  int cnti, cntj;

  for (int i = 0; i < numsSize; i++)
    if (nums[i] >= k)
      nums[i] = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != 0) {
      int t = k - nums[i];
      cnti = 1;
      cntj = 0;
      for (int j = i + 1; j < numsSize; j++) {
        if (nums[j] == nums[i]) {
          cnti++;
          nums[j] = 0;
        } else if (nums[j] == t) {
          cntj++;
          nums[j] = 0;
        }
      }
      if (t * 2 == k) {
        cnt += cnti / 2;
      } else {
        cnt += cnti < cntj ? cnti : cntj;
      }
    }
  }
  return cnt;
}
#endif
int main() {
  int nums[LEN], numsSize = 0, k;
  scanf("%d", &k);
  while (scanf("%d", &nums[numsSize++])) {
    if (getchar() == '\n')
      break;
  }
  printf("%d\n", maxOperations(nums, numsSize, k));
  return 0;
}
