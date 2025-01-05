#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 300000
char *reverseVowels(char *s) {
  // 为元音构造一个哈希表，用直接寻址来代替在元音表中的遍历
  int isvowel[128] = {0};
  isvowel['a'] = 1;
  isvowel['e'] = 1;
  isvowel['i'] = 1;
  isvowel['o'] = 1;
  isvowel['u'] = 1;
  isvowel['A'] = 1;
  isvowel['E'] = 1;
  isvowel['I'] = 1;
  isvowel['O'] = 1;
  isvowel['U'] = 1;
  // 用两个指针从两侧向中间遍历，指向两个元音时就交换
  // 没有同时指向元音时，指向元音的等待，没指向的继续遍历
  // 指针交汇时结束
  int i = 0, j = strlen(s) - 1;
  char tmp;
  while (i < j) {
    if (isvowel[s[i]] == 0) {
      i++;
    }
    if (isvowel[s[j]] == 0) {
      j--;
    }
    if (isvowel[s[i]] && isvowel[s[j]]) {
      tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;
      i++;
      j--;
    }
  }
  return s;
}
int main() {
  printf("input string:\n");
  char s[LEN];
  scanf("%[^\n]", s);
  printf("%s", reverseVowels(s));
  return 0;
}
