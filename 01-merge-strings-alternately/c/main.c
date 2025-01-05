#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 101
char *mergeAlternately(char *str1, char *str2) {
  char *rs = (char *)calloc(strlen(str1) + strlen(str2) + 1, 1), *p = rs;
  while (*str1 || *str2) {
    if (*str1) {
      *p++ = *str1++;
    }
    if (*str2) {
      *p++ = *str2++;
    }
  }
  return rs;
}

int main() {
  char str1[LEN], str2[LEN];
  scanf("%s%s", str1, str2);
  char *merged = mergeAlternately(str1, str2);
  printf("%s\n", merged);
  return 0;
}
