#include <stdlib.h>

void intPointerValueSwap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void minRootHeapify(int *list1, int len, int i_curr_node) {
  int i_min = i_curr_node;
  int i_lc = i_curr_node * 2; // index of left child
  int i_rc = i_lc + 1;        // index of right child
  if (i_lc <= len && list1[i_min] > list1[i_lc])
    i_min = i_lc;
  if (i_rc <= len && list1[i_min] > list1[i_rc])
    i_min = i_rc;
  if (i_min != i_curr_node) {
    intPointerValueSwap(&list1[i_curr_node], &list1[i_min]);
    minRootHeapify(list1, len, i_min);
  }
}

typedef struct priorityQueue {
  int cap;   // queue max length
  int len;   // queue current length
  int *data; // queue data
} priorityQueue;

priorityQueue newPriorityQueue(int cap) {
  priorityQueue pIns;
  pIns.cap = cap + 1;
  pIns.len = 0;
  pIns.data = (int *)malloc(sizeof(int) * pIns.cap);
  return pIns;
}

void enMinPriorityQueue(priorityQueue *pIns, int val) {
  pIns->len++;
  pIns->data[pIns->len] = val;

  int i = pIns->len; // current node index
  int i_f = i / 2;   // current node's father node index
  while (i_f > 0 && pIns->data[i_f] > pIns->data[i]) {
    intPointerValueSwap(&pIns->data[i_f], &pIns->data[i]);
    i = i / 2;
    i_f = i / 2;
  }
}

int deMinPriorityQueue(priorityQueue *pIns) {
  int root = pIns->data[1];
  pIns->data[1] = pIns->data[pIns->len];
  pIns->len--;
  minRootHeapify(pIns->data, pIns->len, 1);
  return root;
}

typedef struct Pair {
  int n1;
  int n2;
} Pair;

int cmpByNum2(const void *a, const void *b) {
  return ((Pair *)b)->n2 - ((Pair *)a)->n2;
}

long long maxScore(int *nums1, int nums1Size, int *nums2, int nums2Size,
                   int k) {
  // bind nums1 and nums2
  Pair num_arr[nums1Size];
  for (int i = 0; i < nums1Size; i++) {
    num_arr[i].n1 = nums1[i];
    num_arr[i].n2 = nums2[i];
  }
  // sort bind array by num2 in max order
  qsort(num_arr, nums1Size, sizeof(Pair), cmpByNum2);

  // use min priority queue to store value of the largest (k-1) num1, as it is
  // easy to get the minmum value of this queue, so that it can optimize
  // sum1_max calculation
  priorityQueue mpq1 =
      newPriorityQueue(k - 1); // mpq1 - num1's min priority queue
  long long sum1_max = 0;
  // initialize mpq1 and sum1_max with first k elements
  for (int i = 0; i < k - 1; i++) {
    enMinPriorityQueue(&mpq1, num_arr[i].n1);
    sum1_max += num_arr[i].n1;
  }

  // traverse on nums2[k]...nums2[nums2Size-1], to find the max score
  long long maxScore;
  long long tmpScore;
  if (k > 1) {
    maxScore = (sum1_max + num_arr[k - 1].n1) * num_arr[k - 1].n2;
    for (int i = k; i < nums2Size; i++) {
      // update largest k-1 num1's sum
      if (num_arr[i - 1].n1 > mpq1.data[1]) {
        sum1_max -= deMinPriorityQueue(&mpq1);
        sum1_max += num_arr[i - 1].n1;
        enMinPriorityQueue(&mpq1, num_arr[i - 1].n1);
      }
      tmpScore = (sum1_max + num_arr[i].n1) * num_arr[i].n2;
      if (tmpScore > maxScore) {
        maxScore = tmpScore;
      }
    }
  } else {
    //  if k = 1, the tmp score will simply be num1*num2
    //  our formal strategy won't work here, because num1's priority queue
    //  length would be 0, queue capacity would be 1, but the strategy requires
    //  minimum queue length be 1 and queue cap be 2
    maxScore = 0;
    for (int i = 0; i < nums2Size; i++) {
      tmpScore = num_arr[i].n1 * num_arr[i].n2;
      if (tmpScore > maxScore)
        maxScore = tmpScore;
    }
  }

  free(mpq1.data);
  return maxScore;
}
