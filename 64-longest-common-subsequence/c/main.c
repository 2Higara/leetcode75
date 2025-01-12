#include <stdlib.h>
#include <string.h>
#if 0
int longestCommonSubsequence(char *text1, char *text2) {
  int len1 = strlen(text1);
  int len2 = strlen(text2);
  int dp[len1 + 1][len2 + 1];
  for (int i = 0; i < len1 + 1; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i < len2 + 1; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i < len1 + 1; i++) {
    for (int j = 1; j < len2 + 1; j++) {
      if (text1[i - 1] == text2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
      }
    }
  }
  return dp[len1][len2];
}
#endif
#if 0
int longestCommonSubsequence(char *text1, char *text2) {
  int len1 = strlen(text1);
  int len2 = strlen(text2);
  char *str1 = (char *)malloc((2 + len1) * sizeof(char));
  char *str2 = (char *)malloc((2 + len2) * sizeof(char));
  strcpy(str1 + 1, text1);
  strcpy(str2 + 1, text2);
  int dp[len1 + 1][len2 + 1];
  for (int i = 0; i < len1 + 1; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i < len2 + 1; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i < len1 + 1; i++) {
    for (int j = 1; j < len2 + 1; j++) {
      if (str1[i] == str2[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
      }
    }
  }
  return dp[len1][len2];
}
#endif
#if 0
int longestCommonSubsequence(char *text1, char *text2) {
  int len1 = strlen(text1);
  int len2 = strlen(text2);
  int *dp = (int *)calloc(len2 + 1, sizeof(int));
  char *str2 = (char *)malloc((2 + len2) * sizeof(char));
  strcpy(str2 + 1, text2);
  for (int i = 0; i < len1; i++) {
    for (int j = len2; j > 0; j--) {
      if (text1[i] == str2[j]) {
        dp[j] = dp[j - 1] + 1;
      } else {
        if (dp[j - 1] > dp[j])
          dp[j] = dp[j - 1];
      }
    }
  }
  return dp[len2];
}
#endif
int longestCommonSubsequence(char *text1, char *text2) {
  int len1 = strlen(text1);
  int len2 = strlen(text2);
  int *dp0 = (int *)calloc(len2, sizeof(int));  // last dp
  int *dp1 = (int *)malloc(len2 * sizeof(int)); // current dp
  int *tmp;
  for (int i = 0; i < len1; i++) {
    if (text1[i] == text2[0]) {
      dp1[0] = 1;
    } else {
      dp1[0] = dp0[0];
    }
    for (int j = 1; j < len2; j++) {
      if (text1[i] == text2[j]) {
        dp1[j] = dp0[j - 1] + 1;
      } else {
        dp1[j] = dp1[j - 1] > dp0[j] ? dp1[j - 1] : dp0[j];
      }
    }
    tmp = dp0;
    dp0 = dp1;
    dp1 = tmp;
  }
  return dp0[len2 - 1];
}
