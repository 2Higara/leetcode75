#include <stdlib.h>
#if 0 // 无法通过 s[0~99998]=99, s[100000]=100 的测试用例, 会超时
int *dailyTemperatures(int *temperatures, int temperaturesSize,
                       int *returnSize) {
  int *rs = malloc(temperaturesSize * sizeof(int));
  int i_max = temperaturesSize - 1;
  for (int i = temperaturesSize - 1; i >= 0; i--) {
    if (temperatures[i] >= temperatures[i_max]) {
      rs[i] = 0;
      i_max = i;
    } else {
      for (int j = i + 1; j <= i_max; j++) {
        if (temperatures[i] < temperatures[j]) {
          rs[i] = j - i;
          break;
        }
      }
    }
  }
  *returnSize = temperaturesSize;
  return rs;
}
#endif
int *dailyTemperatures(int *temperatures, int temperaturesSize,
                       int *returnSize) {
  int *rs = malloc(temperaturesSize * sizeof(int));
  int dms[71]; // decreasing monotonic stack
  dms[0] = temperaturesSize - 1;
  int len = 1;
  for (int i = temperaturesSize - 1; i >= 0; i--) {
    // stack operations
    for (int j = 0; j < len; j++) {
      if (temperatures[i] >= temperatures[dms[j]]) {
        len = j;
        break;
      }
    }
    dms[len++] = i;

    // get result
    if (len > 1)
      rs[i] = dms[len - 2] - i;
    else
      rs[i] = 0;
  }
  *returnSize = temperaturesSize;
  return rs;
}
