#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define LENS 100
#define LENT 10000
bool isSubsequence(char *s, char *t) {
  int lens = strlen(s), lent = strlen(t);
  char *ps = s, *pt = t;
  while (pt < t + lent) {
    if (*pt == *ps) {
      ps++;
    }
    pt++;
  }
  return ps < s + lens ? false : true;
}
int main() {
  char s[LENS], t[LENT];
  scanf("%s%s", s, t);
  printf("%s", isSubsequence(s, t) ? "true" : "false");
  return 0;
}
