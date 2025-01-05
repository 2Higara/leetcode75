#include <stdio.h>
// 1 1 1 0 0 0 1 1 1 1 0
#if 1
int longestOnes(int *nums, int numsSize, int k) {
  int i = 0, j = 0, count = 0, maxcount = 0, subcount = 0;
  if (numsSize == 0) {
    return 0;
  }
  subcount = k;
  while (j <= numsSize - 1) {
    if (nums[j] == 1) {
      count++;
      j++;
    } else {
      if ((subcount == 0) && (k == 0)) {
        j--;
        break;
      } else if (subcount == 0) {
        j--;
        break;
      }
      subcount--;
      count++;
      j++;
    }
  }
  maxcount = count;
  while (j < (numsSize - 1)) {
    j++;
    if ((nums[j] == 0) && (k != 0)) {
      while ((nums[i] != 0) && (i < j)) {
        i++;
      }
      i++;
      count = j - i + 1;
    } else if ((nums[j] == 0) && (k == 0)) {
      count = 0;
      i = j;
    } else if (nums[j] == 1) {
      count++;
    }
    if (maxcount < count) {
      maxcount = count;
    }
  }
  return maxcount;
}
#endif
#if 0
static int left_1_len(int *nums, int pos) {
  int len = 0;
  for (int i = pos - 1; i > -1; i--) {
    if (nums[i])
      len++;
    else
      break;
  }
  return len;
}
static int right_1_len(int *nums, int numsSize, int pos) {
  int len = 0;
  for (int i = pos + 1; i < numsSize; i++) {
    if (nums[i])
      len++;
    else
      break;
  }
  return len;
}
int longestOnes(int *nums, int numsSize, int k) {
  int len_1 = 0, max = 0;
  int pos_0[numsSize];
  int len_0 = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 0) {
      pos_0[len_0++] = i;
    }
  }
  if (k == 0) {
    for (int i = 0; i < numsSize; i++) {
      if (nums[i])
        len_1++;
      else {
        max = len_1 > max ? len_1 : max;
        len_1 = 0;
      }
    }
    max = len_1 > max ? len_1 : max;
    return max;
  } else if (k >= len_0) {
    return numsSize;
  }
  int k1 = k - 1;
  for (int i = k1; i < len_0; i++) {
    len_1 = pos_0[i] - pos_0[i - k1] + 1 + left_1_len(nums, pos_0[i - k1]) +
            right_1_len(nums, numsSize, pos_0[i]);
    max = len_1 > max ? len_1 : max;
  }
  return max;
}
#endif
// 1 1 1 0 0 0 1 1 1 1 0; 2
// 0 0 0 1; 4
// 0 1 1 0; 0
// 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1;3
int main() {
  int nums[100] = {0};
  int numsSize = 0;
  int k;
  while (scanf("%d", &nums[numsSize++])) {
    char c = getchar();
    if (c == ';') {
      scanf("%d", &k);
      break;
    }
  }
  printf("%d\n", longestOnes(nums, numsSize, k));
  return 0;
}
