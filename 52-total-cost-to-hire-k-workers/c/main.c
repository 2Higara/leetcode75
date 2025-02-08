#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int v;
  v = *a;
  *a = *b;
  *b = v;
}

typedef struct PriorityQueue {
  int cap;   // capacity: max length
  int len;   // current length
  int *data; // 1-indexed
} PriorityQueue;

void minHeapify(PriorityQueue *ins, int i);

PriorityQueue newPriorityQueue() {
  PriorityQueue ins;
  ins.cap = 2;
  ins.len = 0;
  ins.data = (int *)malloc(sizeof(int) * ins.cap);
  return ins;
}

void enMinPriorityQueue(PriorityQueue *ins, int n) {
  if (++ins->len == ins->cap) {
    ins->cap *= 2;
    ins->data = realloc(ins->data, ins->cap * sizeof(int));
  }
  ins->data[ins->len] = n;
  int i = ins->len, i_f = i / 2;
  while (i_f > 0 && ins->data[i_f] > ins->data[i]) {
    swap(&ins->data[i_f], &ins->data[i]);
    i = i_f;
    i_f = i / 2;
  }
}

int deMinPriorityQueue(PriorityQueue *ins) {
  int rs = ins->data[1];
  ins->data[1] = ins->data[ins->len];
  ins->len--;
  minHeapify(ins, 1);
  return rs;
}

void minHeapify(PriorityQueue *ins, int i) {
  int i_min = i;
  int i_lc = i * 2;    // index of left child
  int i_rc = i_lc + 1; // index of right child
  if (i_lc <= ins->len && ins->data[i_min] > ins->data[i_lc]) {
    i_min = i_lc;
  }
  if (i_rc <= ins->len && ins->data[i_min] > ins->data[i_rc]) {
    i_min = i_rc;
  }
  if (i != i_min) {
    swap(&ins->data[i], &ins->data[i_min]);
    minHeapify(ins, i_min);
  }
}

long long totalCost(int *costs, int costsSize, int k, int candidates) {
  int i_l = candidates - 1;         //  right bound
  int i_r = costsSize - candidates; //  left bound
  long long sum = 0;
  if (i_l >= i_r) {
    PriorityQueue pq = newPriorityQueue();
    for (int i = 0; i < costsSize; i++) {
      enMinPriorityQueue(&pq, costs[i]);
    }
    for (int i = 0; i < k; i++)
      sum += deMinPriorityQueue(&pq);
    free(pq.data);
    return sum;
  } else {
    PriorityQueue pql = newPriorityQueue();
    PriorityQueue pqr = newPriorityQueue();
    for (int i = 0; i < i_l + 1; i++) {
      enMinPriorityQueue(&pql, costs[i]);
    }
    for (int i = i_r; i < costsSize; i++) {
      enMinPriorityQueue(&pqr, costs[i]);
    }
    for (int i = 0; i < k; i++) {
      if (i_l + 1 < i_r) {
        if (pql.data[1] <= pqr.data[1]) {
          sum += deMinPriorityQueue(&pql);
          i_l++;
          enMinPriorityQueue(&pql, costs[i_l]);
        } else {
          sum += deMinPriorityQueue(&pqr);
          i_r--;
          enMinPriorityQueue(&pqr, costs[i_r]);
        }
      } else {
        PriorityQueue pq = newPriorityQueue();
        for (int j = 1; j < candidates + 1; j++) {
          enMinPriorityQueue(&pq, pql.data[j]);
          enMinPriorityQueue(&pq, pqr.data[j]);
        }
        for (; i < k; i++) {
          sum += deMinPriorityQueue(&pq);
        }
        free(pq.data);
        break;
      }
    }
    free(pql.data);
    free(pqr.data);
    return sum;
  }
}
int main() {
#define SIZE 9
  int costs[SIZE] = {17, 12, 10, 2, 7, 2, 11, 20, 8};
  int k = 3;
  int candidates = 1;
  printf("%lld\n", totalCost(costs, SIZE, k, candidates));
}
