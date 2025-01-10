#include <stdio.h>
// s[n]=2*s[n-1]+s[n-3]
// s[n] =  1 2 5 11 24
int numTilings(int n) {
#define MOD 1000000007
  if (n < 4) {
    int s[4] = {0, 1, 2, 5};
    return s[n];
  }
  long long s1 = 1, s2 = 2, s3 = 5, s4;
  for (int i = 4; i < n + 1; i++) {
    s4 = 2 * s3 + s1;
    if (s4 > MOD)
      s4 = s4 % MOD;
    s1 = s2;
    s2 = s3;
    s3 = s4;
  }
  return s4;
}
int main() {
  int n = 30;
  printf("%d\n", numTilings(n));
}
