#include <stdio.h>
#include <stdlib.h>
struct ListNode {
  int val;
  struct ListNode *next;
};

// 用数组存储各节点指针，也可以用快慢指针处理
typedef struct ListNode Node, *pNode;
#define MAXLEN 100001
struct ListNode *deleteMiddle(struct ListNode *head) {
  int len = 0;
  pNode p = head, node_list[MAXLEN];
  while (p != NULL) {
    node_list[len++] = p;
    p = p->next;
  }
  node_list[len] = NULL;

  int mid = len / 2;
  if (mid == 0) {
    free(head);
    head = NULL;
  } else {
    free(node_list[mid]);
    node_list[mid - 1]->next = node_list[mid + 1];
  }
  return head;
}
