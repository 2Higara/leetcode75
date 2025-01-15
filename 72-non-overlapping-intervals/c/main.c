#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a, const void *b) {
  return (*(int **)a)[1] - (*(int **)b)[1];
}
int eraseOverlapIntervals(int **intervals, int intervalsSize,
                          int *intervalsColSize) {
  qsort(intervals, intervalsSize, 2 * sizeof(int), cmp1);
  int cnt = 1;
  int *curr_end = intervals[0];
  for (int i = 1; i < intervalsSize; i++) {
    if (curr_end[1] <= intervals[i][0]) {
      cnt++;
      curr_end = intervals[i];
    }
  }
  return intervalsSize - cnt;
}
