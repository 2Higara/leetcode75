#include <stdlib.h>
struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode Node, *pNode;
struct ListNode *reverseList(struct ListNode *head) {
  pNode p = head, prs;
  pNode rs = (pNode)malloc(sizeof(Node));
  rs->next = NULL;
  while (p != NULL) {
    prs = p;
    p = p->next;

    prs->next = rs->next;
    rs->next = prs;
  }
  p = rs->next;
  free(rs);
  return p;
}
int pairSum(struct ListNode *head) {
  int len = 0;
  pNode p = head;
  while (p != NULL) {
    p = p->next;
    len++;
  }
  int halflen = len / 2;
  p = head;
  int i = 0;
  while (i++ < halflen) {
    p = p->next;
  }
  pNode half = reverseList(p);
  i = 0;
  int max = 0, sum;
  while (i++ < halflen) {
    sum = half->val + head->val;
    if (sum > max)
      max = sum;
    half = half->next;
    head = head->next;
  }
  return max;
}
