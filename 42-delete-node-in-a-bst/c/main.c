#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// 是叶节点 直接删除
// 有一个节点，用子节点替换当前节点
// 有两个节点，找到右子树中最小的节点 s:
// (最小节点是第一个没有左节点的节点)
// s 的父节点是当前节点，用 s 替换当前节点，将当前节点的左节点设为 s 的左节点
// s 的父节点不是当前节点，将当前节点值置为 s 的值，将 s 的右子树置为 s
// 父节点的左子树
struct TreeNode *get_smallest_node(struct TreeNode *sp, struct TreeNode *s) {
  // 找到最小节点，并返回最小节点的父节点
  // 在 BST 中，最小节点是第一个没有左节点的子节点
  if (s->left == NULL) {
    return sp;
  } else {
    sp = s;
    s = sp->left;
    return get_smallest_node(sp, s);
  }
}
void solution(struct TreeNode **root) {
  if (*root == NULL)
    return;
  if ((*root)->left == NULL && (*root)->right == NULL) {
    // 叶节点
    (*root) = NULL;
  } else if ((*root)->left != NULL && (*root)->right == NULL) {
    (*root) = (*root)->left;
  } else if ((*root)->left == NULL && (*root)->right != NULL) {
    (*root) = (*root)->right;
  } else { // 有两个子节点，用右子树中的最小节点替换当前节点
    if ((*root)->right->left == NULL) {
      // 最小节点 s 是当前节点的右节点
      // 将当前节点的左节点设为 s 的左节点
      (*root)->right->left = (*root)->left;
      *root = (*root)->right;
    } else {
      // 找到最小节点 s 和它的父节点 sp
      // 将当前节点值置为 s 的值
      // 将 s 的右子树置为 sp 的左子树
      struct TreeNode *sp = (*root)->right, *s = sp->left;
      sp = get_smallest_node(sp, s);
      s = sp->left;
      (*root)->val = s->val;
      sp->left = s->right;
    }
  }
}
void find(struct TreeNode **root, int key) {
  if (*root == NULL) {
    return;
  }
  if ((*root)->val == key) {
    solution(root);
    return;
  }
  find(&(*root)->left, key);
  find(&(*root)->right, key);
}
struct TreeNode *deleteNode(struct TreeNode *root, int key) {
  find(&root, key);
  return root;
}
