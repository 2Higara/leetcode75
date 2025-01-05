#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
bool closeStrings(char *word1, char *word2) {
  if (strlen(word1) != strlen(word2)) {
    return false;
  }

  int hash1[128] = {0}, hash2[128] = {0};
  while (*word1) {
    hash1[*word1++]++;
  }
  while (*word2) {
    hash2[*word2++]++;
  }

  int len = 0, cnt1[53] = {0}, cnt2[53] = {0};
  for (int i = 'A'; i < 'z' + 1; i++) {
    if (hash1[i] == 0 && hash2[i] == 0) {
      ;
    } else if (hash1[i] != 0 && hash2[i] != 0) {
      cnt1[len] = hash1[i];
      cnt2[len] = hash2[i];
      len++;
    } else {
      return false;
    }
  }

  qsort(cnt1, len, sizeof(int), cmp);
  qsort(cnt2, len, sizeof(int), cmp);
  for (int i = 0; i < len; i++) {
    if (cnt1[i] != cnt2[i])
      return false;
  }
  return true;
}
