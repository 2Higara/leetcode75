#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Pos {
  int m;
  int n;
} Pos;
int nearestExit(char **maze, int mazeSize, int *mazeColSize, int *entrance,
                int entranceSize) {
  Pos *pos = malloc(sizeof(Pos)); // crrent step's positions list
  Pos *pos_next;                  // positions for next step
  pos[0].m = entrance[0];
  pos[0].n = entrance[1];
  int step = 0;    // step cnt from beginning
  int cnt_pos = 1; // current position cnt
  maze[pos[0].m][pos[0].n] = '+';
  while (1) {
    // find all possible next positions
    int cnt = 0;
    pos_next = malloc(sizeof(Pos) * cnt);
    for (int i = 0; i < cnt_pos; i++) {
      // up
      if (pos[i].m > 0 && maze[pos[i].m - 1][pos[i].n] == '.') {
        cnt++;
        pos_next = realloc(pos_next, sizeof(Pos) * cnt);
        pos_next[cnt - 1].m = pos[i].m - 1;
        pos_next[cnt - 1].n = pos[i].n;
        maze[pos_next[cnt - 1].m][pos_next[cnt - 1].n] = '+';
      }
      // down
      if (pos[i].m < mazeSize - 1 && maze[pos[i].m + 1][pos[i].n] == '.') {
        cnt++;
        pos_next = realloc(pos_next, sizeof(Pos) * cnt);
        pos_next[cnt - 1].m = pos[i].m + 1;
        pos_next[cnt - 1].n = pos[i].n;
        maze[pos_next[cnt - 1].m][pos_next[cnt - 1].n] = '+';
      }
      // left
      if (pos[i].n > 0 && maze[pos[i].m][pos[i].n - 1] == '.') {
        cnt++;
        pos_next = realloc(pos_next, sizeof(Pos) * cnt);
        pos_next[cnt - 1].m = pos[i].m;
        pos_next[cnt - 1].n = pos[i].n - 1;
        maze[pos_next[cnt - 1].m][pos_next[cnt - 1].n] = '+';
      }
      // right
      if (pos[i].n < *mazeColSize - 1 && maze[pos[i].m][pos[i].n + 1] == '.') {
        cnt++;
        pos_next = realloc(pos_next, sizeof(Pos) * cnt);
        pos_next[cnt - 1].m = pos[i].m;
        pos_next[cnt - 1].n = pos[i].n + 1;
        maze[pos_next[cnt - 1].m][pos_next[cnt - 1].n] = '+';
      }
    }
    // check if there's no possible steps
    if (cnt == 0) {
      return -1;
    } else {
      step++;
    }
    // check if any of these positions is exit
    for (int i = 0; i < cnt; i++) {
      printf("(%d, %d) ", pos_next[i].m, pos_next[i].n);
      if (pos_next[i].m == 0 || pos_next[i].m == mazeSize - 1 ||
          pos_next[i].n == 0 || pos_next[i].n == *mazeColSize - 1) {
        return step;
      }
    }
    // update states and go for next test
    pos = realloc(pos, sizeof(Pos) * cnt);
    memcpy(pos, pos_next, sizeof(Pos) * cnt);
    cnt_pos = cnt;
  }
}
int main() {
  char a[5][7] = {{'+', '.', '+', '+', '+', '+', '+'},
                  {'+', '.', '+', '.', '.', '.', '+'},
                  {'+', '.', '+', '.', '+', '.', '+'},
                  {'+', '.', '.', '.', '.', '.', '+'},
                  {'+', '+', '+', '+', '.', '+', '.'}};
  char *b[5] = {a[0], a[1], a[2], a[3], a[4]};
  char **c = b;
  int entrance[2] = {0, 1};
  int mazeColSize = 7;
  printf("%d\n", nearestExit(c, 5, &mazeColSize, entrance, 2));
}
