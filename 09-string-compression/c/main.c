#include <stdio.h>
#include <string.h>
#define LEN 2000

// 注意：本题不允许使用类似哈希表的辅助数据结构
// 可以使用 sprintf() 来实现 %d 向 %s 的转换
int compress(char *chars, int charsSize) {
  char *rs = chars;
  int len_rs = 0;
  char *head = chars, *end = chars;
  int len_word = 0;
  int digit_cnt = 0, digits[4] = {0};
  while (end < chars + charsSize) {
    if (*head == *end) {
      end++;
    } else {
      len_word = end - head;
      rs[len_rs++] = *head;
      if (len_word > 1) {
        digit_cnt = 0;
        while (len_word) {
          digits[digit_cnt++] = len_word % 10;
          len_word /= 10;
        }
        for (int i = digit_cnt - 1; i > -1; i--) {
          rs[len_rs++] = '0' + digits[i];
        }
      }
      head = end;
    }
  }
  // end=chars+charSize
  len_word = end - head;
  rs[len_rs++] = *head;
  if (len_word > 1) {
    //  digit_cnt = 0;
    //  while (len_word) {
    //    digits[digit_cnt++] = len_word % 10;
    //    len_word /= 10;
    //  }
    //  for (int i = digit_cnt - 1; i > -1; i--) {
    //    rs[len_rs++] = '0' + digits[i];
    //  }
    sprintf(&rs[len_rs], "%d", len_word);
    len_rs += strlen(&rs[len_rs]);
  }
  return len_rs;
}
int main() {
  char str[LEN];
  scanf("%s", str);
  int n;
  n = compress(str, strlen(str));
  printf("size = %d\ncompressed result = %s\n", n, str);
  return 0;
}
