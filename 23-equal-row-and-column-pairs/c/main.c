#include <stdlib.h>
#if 0 // 穷举法
int equalPairs(int **grid, int gridSize, int *gridColSize) {
  int cnt = 0, flg;
  for (int i = 0; i < gridSize; i++) { for (int j = 0; j < gridSize; j++) { flg = 1;
      for (int k = 0; k < gridSize; k++) {
        if (grid[i][k] == grid[k][j]) {
          ;
        } else {
          flg = 0;
          break;
        }
      }
      if (flg == 1)
        cnt++;
    }
  }
  return cnt;
}
#endif
#if 1 // 构造哈希函数
// MOD 值选素数，降低碰撞概率
#define MOD 1000000007
int equalPairs(int **grid, int gridSize, int *gridColSize) {
  int *rowhash = (int *)calloc(gridSize, sizeof(int));
  int *colhash = (int *)calloc(gridSize, sizeof(int));
  int i, j;
  for (i = 0; i < gridSize; i++) {
    for (j = 0; j < gridSize; j++) {
      rowhash[i] = ((long)rowhash[i] * 13 + grid[i][j]) % MOD;
      colhash[j] = ((long)colhash[j] * 13 + grid[i][j]) % MOD;
    }
  }
  int rs = 0;
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      rs += rowhash[i] == colhash[j];
    }
  }
  return rs;
}
#endif
