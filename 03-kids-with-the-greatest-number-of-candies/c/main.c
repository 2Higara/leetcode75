#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define LEN 100
bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies,
                      int *returnSize) {
  bool *rs = (bool *)malloc(sizeof(bool) * candiesSize);
  int max = 0;
  for (int i = 0; i < candiesSize; i++) {
    max = candies[i] >= max ? candies[i] : max;
  }
  *returnSize = candiesSize;
  for (int i = 0; i < *returnSize; i++) {
    rs[i] = candies[i] + extraCandies >= max ? true : false;
  }
  return rs;
}
int main() {
  // input: extraCandies,candiesSize,candies{0,1,...,candiesSize}
  int candiesSize, candies[LEN] = {0}, extraCandies, returnSize;
  scanf("%d%d", &extraCandies, &candiesSize);
  bool *result;
  for (int i = 0; i < candiesSize; i++)
    scanf("%d", &candies[i]);
  result = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%s ", result[i] ? "true" : "false");
  }
  free(result);
  return 0;
}
