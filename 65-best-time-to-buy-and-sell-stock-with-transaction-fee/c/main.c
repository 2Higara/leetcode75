#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DP 0
#if !DP
int max(int a, int b) { return a > b ? a : b; }

int maxProfit(int *prices, int pricesSize, int fee) {
  int cash = 0;          // 现金最大值
  int hold = -prices[0]; // 持有股票状态下的现金最大值
  for (int i = 1; i < pricesSize; ++i) {
    cash = max(cash, hold + prices[i] - fee); // 只有售出股票才能更新现金最大值
    hold = max(hold, cash - prices[i]); // 买入情况下的现金最大值
  }
  return cash;
}
#endif
#if DP
int max(int X, int Y) { return ((X) > (Y)) ? (X) : (Y); }
int maxProfit(int *prices, int pricesSize, int fee) {
  int(*profit)[2] = (int(*)[2])alloca(pricesSize * sizeof(int[2]));
  memset(profit, 0, pricesSize * sizeof(int[2]));
  profit[0][1] = -prices[0];

  int i = 0;
  while (++i < pricesSize) {
    profit[i][0] = max(profit[i - 1][0], profit[i - 1][1] + prices[i] - fee);
    profit[i][1] = max(profit[i - 1][1], profit[i - 1][0] - prices[i]);
  }

  return (profit[pricesSize - 1][0]);
}
#endif
int main() {
#define LEN 3
#define FEE 0
  int p[LEN] = {1, 2, 3};
  printf("%d\n", maxProfit(p, LEN, FEE));
}
