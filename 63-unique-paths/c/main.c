#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int uniquePaths(int m, int n) {
  int *cnt_list = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    cnt_list[i] = 1;

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      cnt_list[j] += cnt_list[j - 1];
    }
  }
  int rs = cnt_list[n - 1];
  free(cnt_list);
  return rs;
}

int main() {
  int m = 3;
  int n = 7;
  printf("%d\n", uniquePaths(m, n));
}
