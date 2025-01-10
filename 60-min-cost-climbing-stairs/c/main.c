#include <stdio.h>
int minCostClimbingStairs(int *cost, int costSize) {
  int sum1 = 0, sum2 = 0, sum;
  int tmp1, tmp2;
  for (int i = 2; i < costSize + 1; i++) {
    tmp2 = sum2 + cost[i - 2];
    tmp1 = sum1 + cost[i - 1];
    sum = tmp2 < tmp1 ? tmp2 : tmp1;
    sum2 = sum1;
    sum1 = sum;
  }
  return sum;
}
int main() {
#define COSTSIZE 10
  int cost[COSTSIZE] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  printf("%d", minCostClimbingStairs(cost, COSTSIZE));
}
