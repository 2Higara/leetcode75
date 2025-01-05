#include <stdio.h>
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
