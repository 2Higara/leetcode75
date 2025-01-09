#include <stdio.h>
int minEatingSpeed(int *piles, int pilesSize, int h) {
  int l = 1, r = 0, m;
  for (int i = 0; i < pilesSize; i++) {
    if (piles[i] > r)
      r = piles[i];
  }
  while (l < r) {
    m = (l + r) / 2;
    int cnt = 0;
    for (int i = 0; i < pilesSize; i++) {
      cnt += piles[i] / m + (piles[i] % m > 0);
      if (cnt > h)
        break;
    }
    if (cnt > h) { // m is smaller than target
      l = m + 1;
    } else {
      r = m;
    }
  }
  return l;
}
int main() {
#define PILESSIZE 4
  int piles[PILESSIZE] = {3, 6, 7, 11};
  int h = 8;
  printf("%d\n", minEatingSpeed(piles, PILESSIZE, h));
}
