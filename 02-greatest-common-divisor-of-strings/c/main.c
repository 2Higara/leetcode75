#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1001
int isDivisor(char *div, char *str) {
  int len_div = strlen(div), len_str = strlen(str);
  if (len_str % len_div != 0) {
    return 0;
  } else {
    for (int i = 0; i < len_str / len_div; i++) {
      if (strncmp(div, str + i * len_div, len_div) != 0) {
        return 0;
      }
    }
    return 1;
  }
}
char *gcdOfStrings(char *str1, char *str2) {
  int lens = strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2);
  char *rs = (char *)calloc(lens + 1, 1);
  for (int len = lens; len > 0; len--) {
    memset(rs, 0, lens);
    rs = strncpy(rs, str1, len);
    if (isDivisor(rs, str1) && isDivisor(rs, str2)) {
      return rs;
    }
  }
  *rs = 0;
  return rs;
}
int main() {
  char str1[LEN], str2[LEN];
  scanf("%s%s", str1, str2);
  char *rs = gcdOfStrings(str1, str2);
  printf("%s", rs);
  return 0;
}
