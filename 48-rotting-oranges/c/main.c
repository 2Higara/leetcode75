#include <stdlib.h>
#include <string.h>
typedef struct Pos {
  int m;
  int n;
} Pos;
int orangesRotting(int **grid, int gridSize, int *gridColSize) {
  Pos direct[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  // useful vars
  Pos *curr_list =
      (Pos *)malloc(sizeof(Pos) * gridSize *
                    (*gridColSize)); // current rot orange position list
  int curr_cnt = 0;                  // current rot orange count
  Pos *next_list = (Pos *)malloc(
      sizeof(Pos) * gridSize * (*gridColSize)); // next rot oranve position list
  int next_cnt = 0;                             // next rot orange count
  // initialize curr_list
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < *gridColSize; j++) {
      if (grid[i][j] == 2) {
        curr_list[curr_cnt].m = i;
        curr_list[curr_cnt].n = j;
        curr_cnt++;
      }
    }
  }

  // let rot expand
  int step = 0;
  Pos tmp;
  while (1) {
    // find next list, next cnt; update grid
    for (int i = 0; i < curr_cnt; i++) {
      for (int j = 0; j < 4; j++) {
        tmp.m = curr_list[i].m + direct[j].m;
        tmp.n = curr_list[i].n + direct[j].n;

        if (tmp.m > -1 && tmp.m < gridSize && tmp.n > -1 &&
            tmp.n < *gridColSize && grid[tmp.m][tmp.n] == 1) {
          grid[tmp.m][tmp.n] = 2;
          next_list[next_cnt].m = tmp.m;
          next_list[next_cnt].n = tmp.n;
          next_cnt++;
        }
      }
    }
    // check if rot expansion reaches end
    if (next_cnt == 0) {
      // check if there is fresh orange left in grid in grid in grid in grid
      for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
          if (grid[i][j] == 1) {
            return -1;
          }
        }
      }
      // if no fresh orange left, return step
      return step;

    }
    // if not reach end, update states for next round
    else {
      step++;
      curr_cnt = next_cnt;
      memcpy(curr_list, next_list, sizeof(Pos) * next_cnt);
      next_cnt = 0;
    }
  }
}
