#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @depth - traverse depth, it is also current max index of num_list
 * @num - current selected num
 * @sum - current num list's sum
 * @num_list - current num list
 * @rs - result num list array
 * @i_rs - rs's length
 */
void traverse(const int n, const int k, int depth, int num, int sum,
              int *num_list, int **rs, int *i_rs) {
  // depth == k - 1
  // num[depth] <= 9
  // sum == n

  // recursive condition
  if (depth < k - 1 && num < 9 && sum < n) {
    num_list[depth] = num;
    for (int i = num + 1; i < 10; i++) {
      traverse(n, k, depth + 1, i, sum + i, num_list, rs, i_rs);
    }
  }
  // successful condition
  else if (depth == k - 1 && sum == n) {
    num_list[depth] = num;
    memcpy(rs[(*i_rs)++], num_list, sizeof(int) * k);
    for (int i = 0; i < k; i++)
      printf("%d ", num_list[i]);
    printf("\n");
  } else {
    return;
  }
}
int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes) {
// max return size is c9,5=9!/4!/5!=6*7*8*9/1/2/3/4=14*9 = 126
#define MAXLEN 126
  int **rs = (int **)malloc(MAXLEN * sizeof(int *));
  for (int i = 0; i < MAXLEN; i++) {
    rs[i] = (int *)malloc(k * sizeof(int));
  }

  int *num_list = (int *)malloc(k * sizeof(int));
  int i_rs = 0;
  for (int i = 1; i < 10; i++)
    traverse(n, k, 0, i, i, num_list, rs, &i_rs);

  *returnColumnSizes = (int *)malloc(i_rs * sizeof(int));
  for (int i = 0; i < i_rs; i++) {
    (*returnColumnSizes)[i] = k;
  }
  *returnSize = i_rs;
  return rs;
}

int main() {
  int k = 4;
  int n = 1;
  int returnSize;
  int *returnColumnSizes;
  int **combinations = combinationSum3(k, n, &returnSize, &returnColumnSizes);
}
