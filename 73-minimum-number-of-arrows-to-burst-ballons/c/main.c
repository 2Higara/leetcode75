#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
  if ((*(int **)a)[1] < (*(int **)b)[1])
    return -1;
  else
    return 1;
}
int findMinArrowShots(int **points, int pointsSize, int *pointsColSize) {
  qsort(points, pointsSize, 2 * sizeof(int), cmp);
  int curr = points[0][1];
  int cnt = 1;
  for (int i = 1; i < pointsSize; i++) {
    if (points[i][0] > curr) {
      curr = points[i][1];
      cnt++;
    }
  }
  return cnt;
}
