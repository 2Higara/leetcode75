#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
#define LEN 200
void get_leaf(struct TreeNode *root, int *leaf, int *len) {
  if (root->left == NULL && root->right == NULL) {
    leaf[*len] = root->val;
    (*len)++;
  } else {
    if (root->left != NULL)
      get_leaf(root->left, leaf, len);
    if (root->right != NULL)
      get_leaf(root->right, leaf, len);
  }
  return;
}
bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2) {
  int leaf1[200] = {0}, leaf2[200] = {0};
  int len1 = 0, len2 = 0;
  get_leaf(root1, leaf1, &len1);
  get_leaf(root2, leaf2, &len2);
  if (len1 == len2) {
    for (int i = 0; i < len1; i++) {
      if (leaf1[i] != leaf2[i])
        return false;
    }
    return true;
  }
  return false;
}
int main() {
  struct TreeNode r1 = {1, NULL, NULL}, r2 = {1, NULL, NULL};
  printf("%s", leafSimilar(&r1, &r2) ? "true" : "false");
  return 0;
}
