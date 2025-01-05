#include <stdio.h>
#define MAXHEIGHT 10000
#define MAXLEN 100000
int maxArea(int *height, int heightSize) {
  int *head = height, *end = height + heightSize - 1;
  int maxArea = 0, tmpArea, tmpHeight;
  while (head < end) {
    tmpHeight = *head < *end ? *head : *end;
    tmpArea = tmpHeight * (end - head);
    maxArea = maxArea < tmpArea ? tmpArea : maxArea;
    if (*head < *end) {
      head++;
    } else {
      end--;
    }
  }
  return maxArea;
}
int main() {
  int height[MAXLEN], heightSize = 0;
  while (scanf("%d", &height[heightSize++])) {
    if (getchar() == '\n')
      break;
  }
  printf("%d\n", maxArea(height, heightSize));
  return 0;
}
