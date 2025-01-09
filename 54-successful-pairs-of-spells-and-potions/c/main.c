#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int *successfulPairs(int *spells, int spellsSize, int *potions, int potionsSize,
                     long long success, int *returnSize) {
  qsort(potions, potionsSize, sizeof(int), cmp);
  int *rs = (int *)malloc(sizeof(int) * spellsSize);

  long long mul;
  for (int i = 0; i < spellsSize; i++) {
    long long target = success / spells[i];
    long long remain = success - target * spells[i];
    if (remain > 0) // target.remain
      ;
    else        // target
      target--; // only when potions[i] > target, mul > success

    if (potions[potionsSize - 1] <= target)
      rs[i] = 0;
    else if (potions[0] > target) {
      rs[i] = potionsSize;
    } else {
      int l = 0, r = potionsSize - 1, m;
      int flg = 1;
      while (flg) {
        m = (r + l) / 2;
        if (potions[m] > target) {
          // check if potions[m-1] <= target
          if (potions[m - 1] <= target) {
            rs[i] = potionsSize - m;
            flg = 0;
          }
          r = m;
        } else {
          // check if potions[m+1] > target
          if (potions[m + 1] > target) {
            rs[i] = potionsSize - m - 1;
            flg = 0;
          }
          l = m;
        }
      }
    }
  }
  *returnSize = spellsSize;
  return rs;
}
int main() {
#define SPELLSSIZE 7
#define POTIONSSIZE 10
  int spells[SPELLSSIZE] = {39, 34, 6, 35, 18, 24, 40};
  int potions[POTIONSSIZE] = {27, 37, 33, 34, 14, 7, 23, 12, 22, 37};
  int success = 43;
  int returnSize;
  int *rt = successfulPairs(spells, SPELLSSIZE, potions, POTIONSSIZE, success,
                            &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", rt[i]);
  }
}
