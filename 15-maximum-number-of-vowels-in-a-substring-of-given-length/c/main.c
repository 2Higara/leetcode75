#include <stdio.h>
#include <string.h>
#ifdef USE_SWITCHCASE
int is_vowel(char c) {
  switch (c) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return 1;
  default:
    return 0;
  }
}
#endif
#if 1
int maxVowels(char *s, int k) {
  int is_vowel[128] = {0};
  is_vowel['a'] = 1;
  is_vowel['e'] = 1;
  is_vowel['i'] = 1;
  is_vowel['o'] = 1;
  is_vowel['u'] = 1;
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    cnt += is_vowel[s[i]];
  }
  int max = cnt;
  for (int i = k; s[i] != 0; i++) {
    cnt = cnt - is_vowel[s[i - k]] + is_vowel[s[i]];
    max = (max < cnt) ? cnt : max;
  }
  return max;
}
#endif
int main() {
  char s[100] = {0};
  scanf("%s", s);
  int k;
  scanf("%d", &k);
  printf("%d\n", maxVowels(s, k));
  return 0;
}
