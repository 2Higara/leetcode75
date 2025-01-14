#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#if 0 // brute 35ms leetcode solution 
int cmp(const void *a, const void *b) {
  return strcmp(*(char **)a, *(char **)b);
}

char ***suggestedProducts(char **products, int productsSize, char *searchWord,
                          int *returnSize, int **returnColumnSizes) {
  qsort(products, productsSize, sizeof(char *), cmp);
  *returnSize = strlen(searchWord);
  *returnColumnSizes = malloc(*returnSize * sizeof(int));
  char ***rs = malloc(*returnSize * sizeof(char **));
  for (int i = 0; i < *returnSize; i++) {
    rs[i] = malloc(3 * sizeof(char *));
    int cnt = 0;
    for (int j = 0; j < productsSize && cnt != 3; j++) {
      if (strncmp(searchWord, products[j], i + 1) == 0) {
        rs[i][cnt++] = products[j];
      }
    }
    (*returnColumnSizes)[i] = cnt;
  }
  return rs;
}
#endif
#if 0
// 0ms - brute with memlist - leetcode solution
int compare(const void *str1, const void *str2) {
  return strcmp(*(char **)str1, *(char **)str2);
}
char ***suggestedProducts(char **products, int productsSize, char *searchWord,
                          int *returnSize, int **returnColumnSizes) {
  qsort(products, productsSize, sizeof(char *), compare);
  char ***ans = malloc(strlen(searchWord) * sizeof(char **));
  *returnColumnSizes = malloc(strlen(searchWord) * sizeof(int));
  *returnSize = 0;
  char **cur = malloc(3 * sizeof(char *));
  int startIndex = 0;
  for (int preLen = 1; preLen <= strlen(searchWord); preLen++) {
    int curIndex = 0;
    int startIndexChanged = 0;
    for (int i = startIndex; i < productsSize; i++) {
      if (strncmp(products[i], searchWord, preLen) != 0) {
        if (startIndexChanged == 0) {
          startIndex = i;
          continue;
        } else {
          break;
        }
      }
      if (startIndexChanged == 0) {
        startIndex = i;
        startIndexChanged = 1;
      }
      cur[curIndex++] = products[i];
      if (curIndex == 3) {
        break;
      }
    }
    ans[*returnSize] = malloc((curIndex + 1) * sizeof(char *));
    memcpy(ans[*returnSize], cur, curIndex * sizeof(char *));
    (*returnColumnSizes)[*returnSize] = curIndex;
    ++*returnSize;
  }
  free(cur);
  return ans;
}
#endif
#if 0 // trie optimized  39ms leetcode
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

#define MAX_PRODUCT_LEN 3000
#define MAX_SUGGESTION 3

typedef struct Trie {
  char val;
  bool strv;
  struct Trie *children;
  struct Trie *next; // next trie in same level
} Trie;

Trie *trieCreate() {

  Trie *trie = (Trie *)malloc(sizeof(Trie));

  if (trie) {
    trie->val = 0x00;
    trie->strv = false;
    trie->children = NULL;
    trie->next = NULL;
  }

  return trie;
}

void trieInsert(Trie *obj, const char *word) {

  int word_len = strlen(word);

  Trie *trie = obj;

  for (int i = 0; i < word_len; i++) {

    Trie *child = trie->children;
    Trie *new_child_insert_place = child;

    // find char
    while ((child != NULL) && (child->val != word[i])) {
      if (word[i] > child->val) {
        new_child_insert_place = child;
      }
      child = child->next;
    }

    if (child != NULL) { // char is found
      trie = child;
    } else { // char is not found
      Trie *new_child = trieCreate();
      if ((new_child_insert_place == NULL) ||
          ((new_child_insert_place == trie->children) &&
           (word[i] < new_child_insert_place->val))) {
        new_child->next = new_child_insert_place;
        trie->children = new_child;
      } else {
        Trie *t_trie = new_child_insert_place->next;
        new_child_insert_place->next = new_child;
        new_child->next = t_trie;
      }
      new_child->val = word[i];
      trie = new_child;
    }
  }

  trie->strv = true;
}

Trie *trieStartsWith(Trie *obj, const char *prefix) {

  int word_len = strlen(prefix);
  Trie *trie = obj;

  for (int i = 0; i < word_len; i++) {

    Trie *child = trie->children;

    while ((child != NULL) && (child->val != prefix[i])) {
      child = child->next;
    }

    if (child != NULL) {
      trie = child;
    } else {
      return NULL;
    }
  }

  return trie;
}

void trieFree(Trie *trie) {

  if (trie == NULL) {
    return;
  }

  Trie *child = trie->children;
  while (child != NULL) {
    Trie *next = child->next;
    trieFree(child);
    child = next;
  }

  free(trie);
}

void findSuggestions(Trie *trie, char **suggests, int *suggests_size,
                     char *tstr, int tstr_idx) {

  if ((*suggests_size) == MAX_SUGGESTION) {
    return;
  }

  if (trie->strv) {
    // printf("tstr = %s\n", tstr);
    char *suggest = (char *)calloc(tstr_idx + 1, sizeof(char));
    memcpy(suggest, tstr, tstr_idx * sizeof(char));
    suggests[(*suggests_size)++] = suggest;
  }

  Trie *child = trie->children;
  while (child != NULL) {
    tstr[tstr_idx++] = child->val;
    findSuggestions(child, suggests, suggests_size, tstr, tstr_idx);
    tstr[--tstr_idx] = 0x00;
    child = child->next;
  }
}

char **trieSuggest(Trie *trie, const char *word, int *suggests_size) {

  char *tsuggests[MAX_SUGGESTION];
  *suggests_size = 0;

  Trie *strie = trieStartsWith(trie, word);
  if (strie == NULL) {
    return NULL;
  }

  char tstr[MAX_PRODUCT_LEN] = {0};
  int tstr_idx = strlen(word);

  strcpy(tstr, word);

  findSuggestions(strie, tsuggests, suggests_size, tstr, tstr_idx);

  char **suggests = (char **)calloc((*suggests_size), sizeof(char *));
  memcpy(suggests, tsuggests, (*suggests_size) * sizeof(char *));

  return suggests;
}

char ***suggestedProducts(char **products, int productsSize, char *searchWord,
                          int *returnSize, int **returnColumnSizes) {

  Trie *trie = trieCreate();
  for (int i = 0; i < productsSize; i++) {
    trieInsert(trie, products[i]);
  }

  int search_len = strlen(searchWord);

  char *search_word = (char *)calloc(search_len + 1, sizeof(char));
  strcpy(search_word, searchWord);

  char ***rval = (char ***)calloc(search_len, sizeof(int *));
  *returnSize = search_len;
  *returnColumnSizes = (int *)calloc(search_len, sizeof(int));

  for (int i = 1; i <= search_len; i++) {

    char tchar = search_word[i];
    search_word[i] = 0x00;

    rval[i - 1] =
        trieSuggest(trie, search_word, &((*returnColumnSizes)[i - 1]));

    search_word[i] = tchar;
  }

  trieFree(trie);

  return rval;
}
#endif
#if 1 // brute with optimize 4ms leetcode
int cmp(const void *a, const void *b) {
  char *strA = *(char **)a;
  char *strB = *(char **)b;
  return strcmp(strA, strB);
}

int findLeft(char **products, char target, int ind, int start, int end) {
  int mid;
  int res = -1;
  while (start <= end) {
    mid = (start + end) / 2;
    if (products[mid][ind] >= target) {
      end = mid - 1;
      res = mid;
    } else {
      start = mid + 1;
    }
  }

  if (res == -1) {
    return -1;
  }

  return products[res][ind] == target ? res : -1;
}

int findRight(char **products, char target, int ind, int start, int end) {
  int mid;
  int res = -1;
  while (start <= end) {
    mid = (start + end) / 2;
    if (products[mid][ind] <= target) {
      start = mid + 1;
      res = mid;
    } else {
      end = mid - 1;
    }
  }

  if (res == -1) {
    return -1;
  }

  return products[res][ind] == target ? res : -1;
}

char ***suggestedProducts(char **products, int productsSize, char *searchWord,
                          int *returnSize, int **returnColumnSizes) {
  qsort(products, productsSize, sizeof(char *), cmp);
  *returnSize = strlen(searchWord);
  char ***res = calloc(*returnSize, sizeof(char **));
  *returnColumnSizes = calloc(*returnSize, sizeof(char **));
  int start = 0, end = productsSize - 1;
  for (int i = 0; i < *returnSize; i++) {
    int left = findLeft(products, searchWord[i], i, start, end);
    int right = findRight(products, searchWord[i], i, start, end);
    if (left == -1 || right == -1) {
      break;
    } else {
      start = left;
      end = right;
      (*returnColumnSizes)[i] = fmin(3, end - start + 1);
      res[i] = malloc((*returnColumnSizes)[i] * sizeof(char *));
      for (int j = 0; j < (*returnColumnSizes)[i]; j++) {
        res[i][j] = products[start + j];
      }
    }
  }
  return res;
}
#endif
#if 0 // my solution
#define STRLEN 3001
typedef struct Trie {
  bool is_end;
  struct Trie *next[26];
} Trie;

Trie *createTrie() {
  Trie *obj = (Trie *)malloc(sizeof(Trie));
  obj->is_end = false;
  memset(obj->next, 0, 26 * sizeof(Trie *));
  return obj;
}

void freeTrie(Trie *obj) {
  for (int i = 0; i < 26; i++) {
    if (obj->next[i] != NULL) {
      freeTrie(obj->next[i]);
    }
  }
  free(obj);
}

void insertTrie(Trie *obj, char *word) {
  Trie *p = obj;
  for (int i = 0; i < strlen(word); i++) {
    int i_char = word[i] - 'a';
    if (p->next[i_char] == NULL) {
      p->next[i_char] = createTrie();
    }
    p = p->next[i_char];
  }
  p->is_end = true;
}

Trie *prefixSearchTrie(Trie *obj, char *prefix) {
  Trie *p = obj;
  for (int i = 0; i < strlen(prefix); i++) {
    int i_char = prefix[i] - 'a';
    if (p->next[i_char] == NULL) {
      return NULL;
    }
    p = p->next[i_char];
  }
  return p;
}

typedef struct Suggestion {
  char word[3][STRLEN];
  int count;
} Suggestion;

char ***suggestedProducts(char **products, int productsSize, char *searchWord,
                          int *returnSize, int **returnColumnSizes) {
  // return strings, rs[row][col] = suggestion word
  char ***rs = (char ***)malloc(strlen(searchWord) * sizeof(char **)); // row
  for (int i = 0; i < strlen(searchWord); i++) {
    rs[i] = (char **)malloc(3 * sizeof(char *)); //  column
  }
  // returnSize, row num
  *returnSize = strlen(searchWord);
  // returnColumnSizes, each row's column num,
  // (*returnColumnSizes)[i] = suggestion num
  *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
  // trie construct
  Trie *trie = createTrie();
  for (int i = 0; i < productsSize; i++) {
    insertTrie(trie, products[i]);
  }
  // get suggestions(no more than 3) character by character
  int i_row;
  Trie *pTrie;
  char letter;
  for (i_row = 0; i_row < strlen(searchWord); i_row++) {
    letter = searchWord[i_row];
    pTrie = prefixSearchTrie(trie, &letter);
    if (pTrie == NULL)
      break;
    // get suggest word, suggest count
  }
}
int main() {
#define PRODUCTSSIZE 6
  char *products[STRLEN] = {"mobile",  "mouse",    "moneypot",
                            "monitor", "mousepad", "baby"};
  char *searchWord = "ba";
  int returnSize;
  int *returnColumnSizes;
  suggestedProducts(products, PRODUCTSSIZE, searchWord, &returnSize,
                    &returnColumnSizes);
  printf("returnsize: %d\n", returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("columnsize[%d] = %d\n", i, returnColumnSizes[i]);
  }
}
#endif
