#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char num2chars[10][4] = {"",    "",    "abc",  "def", "ghi",
                               "jkl", "mno", "pqrs", "tuv", "wxyz"};

const int num2chars_len[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};

void traverse(const int *nums, const int len, int i_nums, char *s, char **rs,
              int *i_rs) {
  int num = nums[i_nums];
  for (int i = 0; i < num2chars_len[num]; i++) {
    s[i_nums] = num2chars[num][i];
    if (i_nums < len - 1) {
      traverse(nums, len, i_nums + 1, s, rs, i_rs);
    } else {
      // printf("%s ", s);
      strcpy(rs[*i_rs], s);
      (*i_rs)++;
    }
  }
}

char **letterCombinations(char *digits, int *returnSize) {
  // corner case
  if (strlen(digits) == 0) {
    *returnSize = 0;
    char **rs;
    return rs;
  }

  // process digits to int list
  int nums_len = strlen(digits);
  int nums[nums_len];
  for (int i = 0; i < nums_len; i++)
    nums[i] = digits[i] - '0';

  // alloc ram space for result
  int rs_size = 1;
  for (int i = 0; i < nums_len; i++)
    rs_size *= num2chars_len[nums[i]];
  char **rs = (char **)malloc(rs_size * sizeof(char *));
  for (int i = 0; i < rs_size; i++)
    rs[i] = (char *)calloc((nums_len + 1), sizeof(char));

  // traverse all conditions and record it to rs
  char *s = (char *)calloc(nums_len + 1, sizeof(char));
  int i_rs = 0;
  traverse(nums, nums_len, 0, s, rs, &i_rs);

  *returnSize = rs_size;
  return rs;
}

int main() {
  char *digits = "3";
  int returnSize;
  char **rs = letterCombinations(digits, &returnSize);
  for (int i = 0; i < returnSize; i++)
    printf("%s ", rs[i]);
}
