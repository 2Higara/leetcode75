#include <stdio.h>
#include <stdlib.h>
#if 0
// (0, a) -> (a, 0)
// (a, b) -> (b, a)
// 找出以 0 为目标的数，其余包含此数的单元中，要以此数为目的
void solve(int **connections, int connectionsSize, int current, int *cnt,
           int *solved) {
  for (int i = 0; i < connectionsSize; i++) {
    if (solved[i] == 0 &&
        (connections[i][0] == current || connections[i][1] == target)) {
      solved[i] = 1;
      int new_current;
      if (connections[i][0] == current) { // 0->1
        printf("flip pos: %d\n", i);
        (*cnt)++;
        new_current = connections[i][1];
      } else if (connections[i][1] == current) { // 1->0
        new_current = connections[i][0];
      }
      solve(connections, connectionsSize, new_current, cnt, solved);
    }
  }
}
int minReorder(int n, int **connections, int connectionsSize,
               int *connectionsColSize) {
  int cnt = 0;
  int *solved = (int *)calloc(connectionsSize, sizeof(int));
  solve(connections, connectionsSize, 0, &cnt, solved);
  return cnt;
}
#endif
// 在连接里遍历去寻找下一个迭代项会消耗大量时间
// 制作一个哈希表来存储这些值，但由于一个节点可能会和多个节点相连，哈希表的成员需要动态分配长度
// 用 malloc 和 realloc 实现长度的动态分配
typedef struct Node {
  int *city;
  int cnt;
} Node;
void add_city(Node *node, int city) {
  node->cnt++;
  if (node->city == NULL) { // 初始化
    node->city = (int *)malloc(sizeof(int));
    node->city[0] = city;
  } else {
    // 注意这里不能忽略等号前面的 node->city
    // 如果忽略，并且如果 realloc 决定 free
    // 掉旧空间再重新分配新空间，而不是增加旧空间的长度，会导致数据内存地址发生变化，
    // 此时 node->city 会因为没有更新地址而指向已被释放的地址
    node->city = (int *)realloc(node->city, sizeof(int) * node->cnt);
    node->city[node->cnt - 1] = city;
  }
}
void traverse(Node *map0, Node *map1, int last, int current, int *cnt_reverse) {
  for (int i = 0; i < map0[current].cnt; i++) {
    // 由于图中不存在回路(n 个节点，n-1
    // 条边)，所以不需要记录已经过节点，只需保证来时的节点不迭代即可
    if (map0[current].city[i] != last) {
      (*cnt_reverse)++;
      traverse(map0, map1, current, map0[current].city[i], cnt_reverse);
    }
  }
  for (int i = 0; i < map1[current].cnt; i++) {
    if (map1[current].city[i] != last)
      traverse(map0, map1, current, map1[current].city[i], cnt_reverse);
  }
}
int minReorder(int n, int **connections, int connectionsSize,
               int *connectionsColSize) {
  Node *map0 = (Node *)calloc(n, sizeof(Node)); // map0[i] 为出发点
  Node *map1 = (Node *)calloc(n, sizeof(Node)); // map1[i] 为目标点
  for (int i = 0; i < connectionsSize; i++) {
    add_city(&map0[connections[i][0]], connections[i][1]);
    add_city(&map1[connections[i][1]], connections[i][0]);
  }
  int cnt_reverse = 0;
  traverse(map0, map1, 0, 0, &cnt_reverse);
  return cnt_reverse;
}
