#include <stdlib.h>
#include <string.h>
#if 1
char *removeStars(char *s) {
  char *rs = malloc(strlen(s) + 1), *p = rs;
  while (*s) {
    if (*s == '*') {
      p--;
    } else {
      *p++ = *s;
    }
    s++;
  }
  *p = 0;
  return rs;
}
#endif
