#include <stdbool.h>
#define MAX 2001
bool uniqueOccurrences(int *arr, int arrSize) {
  int cnt[MAX] = {0};
  for (int i = 0; i < arrSize; i++) {
    cnt[arr[i] + 1000]++;
  }
  int cnt_cnt[1001] = {0};
  for (int i = 0; i < MAX; i++) {
    if (cnt[i] > 0) {
      cnt_cnt[cnt[i]]++;
      if (cnt_cnt[cnt[i]] > 1)
        return false;
    }
  }
  return true;
}
