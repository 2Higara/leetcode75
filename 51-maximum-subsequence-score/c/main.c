#include <stdlib.h>
// swap the value of two int pointers
void intPointerValueSwap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
// given a heap and an index to a node,
// make the node and all its braches a minimum heap
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

// add a number to minimum priority queue
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

// remove root node(min value node) from minimum priority queue
int deMinPriorityQueue(priorityQueue *pIns) {
  int root = pIns->data[1];
  pIns->data[1] = pIns->data[pIns->len]; // move last leaf node to front
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

  // initialize min priority queue, sum1 max, max score with first k
  // elements(nums[0]...nums[k-1])
  priorityQueue mpq1 = newPriorityQueue(k); // mpq1 - min priority queue of num1
  long long sum1_max = 0;
  for (int i = 0; i < k; i++) {
    enMinPriorityQueue(&mpq1, num_arr[i].n1);
    sum1_max += num_arr[i].n1;
  }
  long long maxScore = sum1_max * num_arr[k - 1].n2;

  // traverse on later elements(nums2[k]...nums2[nums2Size-1]), to find the max
  // score.
  long long tmpScore;
  for (int i = k; i < nums2Size; i++) {
    // since num2 is descending, if new tmp score wants to be larger than
    // original max score, its corresponding sum1_max should be larger than
    // original sum1_max, thus num2's corresponding num1 should be larger than
    // the root value in mpq1
    if (num_arr[i].n1 > mpq1.data[1]) {
      sum1_max -= deMinPriorityQueue(&mpq1);
      sum1_max += num_arr[i].n1;
      enMinPriorityQueue(&mpq1, num_arr[i].n1);
      tmpScore = sum1_max * num_arr[i].n2;
      if (tmpScore > maxScore) {
        maxScore = tmpScore;
      }
    }
  }

  free(mpq1.data);
  return maxScore;
}
