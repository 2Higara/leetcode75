#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define LEN 1000
// time: O(logn~n^2)
// bool increasingTriplet(int *nums, int numsSize) {
//  if (numsSize < 3)
//    return false;
//  int *rs = (int *)calloc(numsSize, sizeof(int));
//  for (int i = 1; i < numsSize; i++) {
//    for (int j = 0; j < i; j++) {
//      if (nums[j] < nums[i]) {
//        rs[i] = rs[j] > rs[i] - 1 ? rs[j] + 1 : rs[i];
//      }
//    }
//    if (rs[i] >= 2) {
//      free(rs);
//      return true;
//    }
//  }
//  free(rs);
//  return false;
//}

// time O(n)
// bool increasingTriplet(int *n, int len) {
//  if (len < 3) {
//    return false;
//  }
//  int l_min[len], r_max[len];
//  l_min[0] = n[0];
//  r_max[len - 1] = n[len - 1];
//  for (int i = 1, j = len - 2; i < len; i++, j--) {
//    l_min[i] = n[i - 1] < l_min[i - 1] ? n[i - 1] : l_min[i - 1];
//    r_max[j] = n[j + 1] > r_max[j + 1] ? n[j + 1] : r_max[j + 1];
//  }
//  for (int i = 1, j = len - 2; i <= j; i++, j--) {
//    if (n[i] > l_min[i] && n[i] < r_max[i]) {
//      return true;
//    }
//    if (n[j] > l_min[j] && n[j] < r_max[j]) {
//      return true;
//    }
//  }
//  return false;
//}

// time O(0~n)
bool increasingTriplet(int *n, int len) {
  int min = INT_MAX, mid = INT_MAX;
  for (int i = 0; i < len; i++) {
    if (n[i] <= min) {
      min = n[i];
    } else if (n[i] <= mid) {
      mid = n[i];
    } else {
      return true;
    }
  }
  return false;
}
int main() {
  int nums[LEN], numsSize;
  scanf("%d", &numsSize);
  for (int i = 0; i < numsSize; i++)
    scanf("%d", &nums[i]);
  bool rs = increasingTriplet(nums, numsSize);
  printf("%s\n", rs ? "true" : "false");
}
