#include <stdio.h>
// T0 = 0, T1 = 1, T2 = 1, T3 = 2, T4 = 4, T5 = 7
// Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
int tribonacci(int n) {
  if (n < 3) {
    if (n == 0)
      return 0;
    else
      return 1;
  }
  int Tn = 0;
  int Tn_1 = 1;
  int Tn_2 = 1;
  int Tn_3;
  for (int i = 0; i < n - 2; i++) {
    Tn_3 = Tn + Tn_1 + Tn_2;
    Tn = Tn_1;
    Tn_1 = Tn_2;
    Tn_2 = Tn_3;
  }
  return Tn_3;
}
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", tribonacci(n));
}
