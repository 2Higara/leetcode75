#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Input: nums = [3,2,1,5,6,4], k = 2
// [] <- 3 = [3]
// [3] <- 2 = [3,2]
// [3,2] <- 1 = [3,2,1]
// [3,2,1] <- 5 = [5,3,2,1]
// [5,3,2,1] <- 6 = [6,5,3,2,1]
// [6,5,3,2,1] <- 4 = [6,5,4,3,2,1]

// construct a sorted queue, do the sort work when iserting a new num
// make sure queue head is the largest num
// new num should be inserted before the first num <= it
void sorted_queue_insert_num(int *q, int qlen, int num) {
  int pos;
  for (pos = 0; pos < qlen; pos++) {
    if (q[pos] <= num) {
      break;
    }
  }
  int mvlen = qlen - pos;
  memmove(&q[pos + 1], &q[pos], mvlen * sizeof(int));
  q[pos] = num;
}
int findKthLargest(int *nums, int numsSize, int k) {
  int *q = (int *)malloc(sizeof(int) * (1 + numsSize));
  int qlen = 0;
  for (int i = 0; i < numsSize; i++) {
    sorted_queue_insert_num(q, qlen, nums[i]);
    qlen++;
  }
  for (int i = 0; i < numsSize; i++)
    printf("%d ", q[i]);
  return q[k - 1];
}
int main() {
  int nums[6] = {1, 2, 3, 4, 5, 6};
  findKthLargest(nums, 6, 3);
}
