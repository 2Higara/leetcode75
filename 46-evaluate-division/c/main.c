#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
  char *name;             // 节点名称
  double val;             // 节点值
  int graph_index;        // 连通图序号
  struct Node **adj_list; // 相连节点
  double *mult_list;      // 相连节点倍率，others[i]=val*mult[i]
  int adj_cnt;            // 相连节点数
} Node, *pNode;

// make sure the first provided graph_index is larger than 0, because I use
// graph_index to track if the node is traversed
void traverse(pNode node, double val, int graph_index) {
  node->val = val;
  node->graph_index = graph_index;
  for (int i = 0; i < node->adj_cnt; i++) {
    if (node->adj_list[i]->graph_index == 0) {
      traverse(node->adj_list[i], val * node->mult_list[i], graph_index);
    }
  }
}
double *calcEquation(char ***equations, int equationsSize,
                     int *equationsColSize, double *values, int valuesSize,
                     char ***queries, int queriesSize, int *queriesColSize,
                     int *returnSize) {
  double *result = (double *)malloc(queriesSize * sizeof(double)); // 结果

  int node_cnt = 0;
  pNode node_list = (pNode)calloc(equationsSize * 2, sizeof(Node));
  for (int i = 0; i < equationsSize; i++) {
    pNode a, b; // a-first node, b-second node
    int flg_existed = 0;
    // check if first node initialized
    for (int j = 0; j < node_cnt; j++) {
      if (strcmp(node_list[j].name, equations[i][0]) == 0) {
        flg_existed = 1;
        a = &node_list[j];
        a->adj_list = realloc(a->adj_list, (1 + a->adj_cnt) * sizeof(pNode));
        a->mult_list = realloc(a->mult_list, (1 + a->adj_cnt) * sizeof(double));
        break;
      }
    }
    if (flg_existed == 0) {
      node_list[node_cnt].name = equations[i][0];
      a = &node_list[node_cnt];
      a->adj_list = malloc(sizeof(pNode));
      a->mult_list = malloc(sizeof(double));
      node_cnt++;
    }

    flg_existed = 0;
    // check if second node initialized
    for (int j = 0; j < node_cnt; j++) {
      if (strcmp(node_list[j].name, equations[i][1]) == 0) {
        flg_existed = 1;
        b = &node_list[j];
        b->adj_list = realloc(b->adj_list, (1 + b->adj_cnt) * sizeof(pNode));
        b->mult_list = realloc(b->mult_list, (1 + b->adj_cnt) * sizeof(double));
        break;
      }
    }
    if (flg_existed == 0) {
      node_list[node_cnt].name = equations[i][1];
      b = &node_list[node_cnt];
      b->adj_list = malloc(sizeof(pNode));
      b->mult_list = malloc(sizeof(double));
      node_cnt++;
    }

    // initialize a and b relation; a = b * values[i], b = a * 1/values[i]
    a->adj_list[a->adj_cnt] = b;
    a->mult_list[a->adj_cnt] = 1 / values[i];
    a->adj_cnt++;

    b->adj_list[b->adj_cnt] = a;
    b->mult_list[b->adj_cnt] = values[i];
    b->adj_cnt++;
  }

  // traverse graphs and initialize nodes' graph_index and val
  int graph_index = 0;
  for (int i = 0; i < node_cnt; i++) {
    if (node_list[i].graph_index == 0) {
      graph_index++;
      traverse(&node_list[i], 100.0, graph_index);
    }
  }

  // do calculation
  for (int i = 0; i < queriesSize; i++) {
    pNode a, b;
    int flg_a_exist = 0, flg_b_exist = 0;
    for (int j = 0; j < node_cnt; j++) {
      if (strcmp(queries[i][0], node_list[j].name) == 0) {
        a = &node_list[j];
        flg_a_exist = 1;
        break;
      }
    }
    for (int j = 0; j < node_cnt; j++) {
      if (strcmp(queries[i][1], node_list[j].name) == 0) {
        b = &node_list[j];
        flg_b_exist = 1;
        break;
      }
    }
    if (flg_a_exist && flg_b_exist && a->graph_index == b->graph_index) {
      result[i] = a->val / b->val;
    } else {
      result[i] = -1;
    }
  }
  *returnSize = queriesSize;
  return result;
}
