#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000
// 1 0 0 1          2 0
// 1 0 0 0 1        3 1
// 1 0 0 0 0 1      4 1
// 1 0 0 0 0 0 1    5 2
// 1 0 0 0 0 0 0 1  6 2
// 2 boundry: (len0 - 1)/2
//
// 1 0 0            2 1
// 1 0 0 0          3 1
// 1 0 0 0 0        4 2
// 1 0 0 0 0 0      5 2
// 1 0 0 0 0 0 0    6 3
// 1 boundry: len0/2
//
// 0                1 1
// 0 0              2 1
// 0 0 0            3 2
// 0 0 0 0          4 2
// 0 0 0 0 0        5 3
// 0 boundry: (len0+1)/2
//
// special conditions:
// 0 0 0 0
// 1 0 0 0 0
// 0 0 0 1 0 0 0
// 1 1 1
bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n) {
  int *head = flowerbed, *end = flowerbed, len, boundry_cnt, max = 0;
  while (end < flowerbed + flowerbedSize) {

    // head < flowerbed + flowerbedSize 放在前面
    // 可以确保遇到全是1的情况(1,1,1)时，*head==1
    // 在最后一次运行时被忽略，以防出现指针越界访问
    while (head < flowerbed + flowerbedSize && *head == 1) {
      head++;
    }
    end = head;
    // 同上，指针位置判断放在前面，防止 *end==0 指针越界访问
    while (end < flowerbed + flowerbedSize && *end == 0) {
      end++;
    }
    len = end - head;
    boundry_cnt = (head != flowerbed) + (end != flowerbed + flowerbedSize);
    if (boundry_cnt == 2) {
      max += (len - 1) / 2;
    } else if (boundry_cnt == 1) {
      max += len / 2;
    } else {
      max += (len + 1) / 2;
    }
    head = end;
  }
  return n <= max;
}
int main() {
  char str[LEN], *delim = ",", *token;
  int flowerbed[LEN], len = 0, n;
  fgets(str, LEN, stdin);
  token = strtok(str, delim);
  while (token != NULL) {
    flowerbed[len++] = atoi(token);
    token = strtok(NULL, delim);
  }
  scanf("%d", &n);
  printf("%s", canPlaceFlowers(flowerbed, len, n) ? "true" : "false");
  return 0;
}
