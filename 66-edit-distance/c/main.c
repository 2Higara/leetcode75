#include <stdio.h>
#include <string.h>
int min(int a, int b, int c) {
  int min = a;
  if (b < min)
    min = b;
  if (c < min)
    min = c;
  return min;
}
int minDistance(char *word1, char *word2) {
  int len1 = strlen(word1);
  int len2 = strlen(word2);
  int dp[len1 + 1][len2 + 1];
  for (int i = 0; i < len1 + 1; i++) {
    dp[i][0] = i;
  }
  for (int j = 0; j < len2 + 1; j++) {
    dp[0][j] = j;
  }
  for (int i = 1; i < len1 + 1; i++) {
    for (int j = 1; j < len2 + 1; j++) {
      if (word1[i - 1] == word2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
      }
    }
  }
  return dp[len1][len2];
}

int main() {
  char *str1 = "ros", *str2 = "horse";
  minDistance(str1, str2);
}
