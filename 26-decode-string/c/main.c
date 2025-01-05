#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// s=2[a]
// s=2[a]2[b]
// s=2[a2[b]]

// decode a string slice
// - *rs: return value, decoded string until next `]`
// - *s: encoded string slice, starts from `s[*is]`
// - *is: current traverse index in *s, when decoding starts, `s[*is]` is first
// char after `[`, when decoding ends, `s[*is]` is the char after `]`
char *decode(char *s, int *is) {
#define LEN 100000
  char *rs = (char *)calloc(LEN, sizeof(char)); // decoded string
  int n = 0; // the number of repeat times before [chars]
  while (s[*is]) {
    char c = s[*is]; // current character

    // c is character
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
      strncat(rs, &c, 1);
      (*is)++;
    }
    // c is a number, update n
    else if (c >= '0' && c <= '9') {
      n = n * 10 + c - '0';
      (*is)++;
    }
    // c is `[`, recurse to get inner string slice
    else if (c == '[') {
      (*is)++; // make sure s[*is] points to next char for following function
      char *rs_inner = decode(s, is);
      for (int i = 0; i < n; i++) {
        // strcpy(rs + len_rs, rs_inner);
        strcat(rs, rs_inner);
      }
      // reset n and free memory
      n = 0;
      free(rs_inner);
    }
    // c is `]`, means it's in a recursive child function, should update *is
    // and return current result
    else if (c == ']') {
      (*is)++;
      return rs;
    }
  }
  return rs;
}
char *decodeString(char *s) {
  int is = 0;
  char *rs = decode(s, &is);
  return rs;
}
int main() {
#define TEST_CASE_CNT 6
  char s[TEST_CASE_CNT][100] = {"abc",           "2[a2[b]]",
                                "2[a]2[b]",      "23[abc34[cd]]56[xy]",
                                "100[leetcode]", "[a]"};
  int len;
  for (int i = 0; i < TEST_CASE_CNT; i++)
    printf("%s -> %s\n", s[i], decodeString(s[i]));
}
