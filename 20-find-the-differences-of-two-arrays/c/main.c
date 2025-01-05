#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#define MAX 2001
int **findDifference(int *nums1, int nums1Size, int *nums2, int nums2Size,
                     int *returnSize, int **returnColumnSizes) {
  int hash[MAX] = {0};
  for (int i = 0; i < nums1Size; i++) {
    hash[nums1[i] + 1000] = 1;
  }
  int tmp;
  for (int j = 0; j < nums2Size; j++) {
    tmp = nums2[j] + 1000;
    if (hash[tmp] == 1 || hash[tmp] == 3) {
      hash[tmp] = 3;
    } else {
      hash[tmp] = 2;
    }
  }

  int **rs = (int **)malloc(sizeof(int *) * 2);
  rs[0] = (int *)malloc(sizeof(int) * MAX);
  rs[1] = (int *)malloc(sizeof(int) * MAX);
  int len1 = 0, len2 = 0;
  for (int i = 0; i < MAX; i++) {
    if (hash[i] == 0 || hash[i] == 3) {
      ;
    } else if (hash[i] == 1) {
      rs[0][len1++] = i - 1000;
    } else if (hash[i] == 2) {
      rs[1][len2++] = i - 1000;
    }
  }
  *returnSize = 2;
  *returnColumnSizes = (int *)malloc(sizeof(int) * 2);
  (*returnColumnSizes)[0] = len1;
  (*returnColumnSizes)[1] = len2;
  return rs;
}
