#include <stdlib.h>
// 省的个数=连通图个数+单节点数
void find(int **map, int size, int *used, int city) {
  // 递归遍历连通图，在 used 数组中登记遍历的节点，下次遇到不再递归
  if (used[city] == 1)
    return;
  else {
    used[city] = 1;
    for (int i = 0; i < size; i++) {
      if (map[city][i] == 1)
        find(map, size, used, i);
    }
  }
}
int findCircleNum(int **isConnected, int isConnectedSize,
                  int *isConnectedColSize) {
  int *used = (int *)calloc(isConnectedSize, sizeof(int));
  int province_num = 0;
  for (int i = 0; i < isConnectedSize; i++) {
    if (used[i] == 0) {
      province_num++;
      find(isConnected, isConnectedSize, used, i);
    }
  }
  return province_num;
}
