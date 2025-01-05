#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 10000
// "a b"
// " a"
// "a "
// "a"
// " "
char *reverseWords(char *s) {
  int lens = strlen(s);
  char *ps = s + lens - 1;
  char *rs = (char *)calloc(lens + 2, sizeof(char)),
       *prs = rs; // rs 分配 len+2
                  // 的长度，多的两个：一个是结束符，一个是可能多出的空格

  while (ps > s - 1) {
    if (*ps != ' ' && (ps > s && *(ps - 1) == ' ' || ps == s)) {
      sscanf(ps, "%s", prs);
      prs += strlen(prs);
      *prs++ = ' ';
    }
    ps--;
  }
  *(rs + strlen(rs) - 1) = 0; // 去掉末尾的空格
  return rs;
}
int main() {
  char s[LEN];
  scanf("%[^\n]", s);
  char *rs = reverseWords(s);
  printf("%s", rs);
  return 0;
}
