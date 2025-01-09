// 1
// 0 1
// 1 0
// 0 1 2
// 2 1 0
// 0 1 2 3
// 3 2 1 0
// 0 1 2 3 4
// 4 3 2 1 0
// 0 1 2 1 0
// 1,2,3,1
// 1,2,1,3,5,6,4
int findPeakElement(int *nums, int numsSize) {
  int l = 0, r = numsSize - 1, m;
  while (l < r) {
    m = (l + r) / 2;
    if (nums[m + 1] > nums[m]) { // 右侧更大
      l = m + 1;
    } else { // 左侧更大
      r = m;
    }
  }
  return l;
}
