#include <stdlib.h>

typedef struct {
  int nums[1002]; // 0 for exist, 1 for popped
  int top;        // index for smallest num in queue
} SmallestInfiniteSet;

SmallestInfiniteSet *smallestInfiniteSetCreate() {
  SmallestInfiniteSet *rs =
      (SmallestInfiniteSet *)calloc(1, sizeof(SmallestInfiniteSet));
  rs->top = 1;
  return rs;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet *obj) {
  int rs = obj->top;
  obj->nums[rs] = 1;
  for (int i = rs; i < 1002; i++) {
    if (obj->nums[i] == 0) {
      obj->top = i;
      break;
    }
  }
  return rs;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet *obj, int num) {
  if (obj->nums[num] == 1) {
    obj->nums[num] = 0;
    if (num < obj->top) {
      obj->top = num;
    }
  }
}

void smallestInfiniteSetFree(SmallestInfiniteSet *obj) { free(obj); }

/**
 * Your SmallestInfiniteSet struct will be instantiated and called as such:
 * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
 * int param_1 = smallestInfiniteSetPopSmallest(obj);

 * smallestInfiniteSetAddBack(obj, num);

 * smallestInfiniteSetFree(obj);
*/
