#include <stdio.h>
#include <stdlib.h>
struct ListNode {
  int val;
  struct ListNode *next;
};
typedef struct ListNode Node, *pNode;
struct ListNode *oddEvenList(struct ListNode *head) {
  pNode evenlist = (pNode)malloc(sizeof(Node)),
        oddlist = (pNode)malloc(sizeof(Node));
  pNode p = head, pe = evenlist, po = oddlist;
  while (p != NULL) {
    pe->next = p;
    pe = p;
    p = p->next;

    if (p == NULL)
      break;

    po->next = p;
    po = p;
    p = p->next;
  }
  po->next = NULL;
  pe->next = oddlist->next;
  return evenlist->next;
}
