#include <stdio.h>
#include <stdlib.h>

int *countBits(int n, int *returnSize) {
  int *rs = (int *)malloc((n + 1) * sizeof(int));
  rs[0] = 0;
  for (int i = 1; i < n + 1; i++) {
    rs[i] = (i & 1) + rs[i >> 1];
  }
  *returnSize = n + 1;
  return rs;
}

int main() {
  int n = 10;
  int rs_size;
  int *rs = countBits(n, &rs_size);
  for (int i = 0; i < rs_size; i++)
    printf("rs[%d] = %d\n", i, rs[i]);
}
