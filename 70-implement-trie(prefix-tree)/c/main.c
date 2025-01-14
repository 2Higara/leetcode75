#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Trie {
  bool is_end;
  struct Trie *next[26];
} Trie;

Trie *trieCreate() {
  Trie *obj = (Trie *)malloc(sizeof(Trie));
  obj->is_end = false;
  memset(obj->next, 0, 26 * sizeof(Trie *));
  // for (int i = 0; i < 26; i++)
  //   obj->next[i] = NULL;
  return obj;
}

void trieInsert(Trie *obj, char *word) {
  Trie *p = obj;
  for (int i = 0; i < strlen(word); i++) {
    int i_char = word[i] - 'a';
    if (p->next[i_char] == NULL) {
      p->next[i_char] = trieCreate();
    }
    p = p->next[i_char];
  }
  p->is_end = true;
}

bool trieSearch(Trie *obj, char *word) {
  Trie *p = obj;
  for (int i = 0; i < strlen(word); i++) {
    int i_char = word[i] - 'a';
    if (p->next[i_char] == NULL) {
      return false;
    }
    p = p->next[i_char];
  }
  return p->is_end;
}

bool trieStartsWith(Trie *obj, char *prefix) {
  Trie *p = obj;
  for (int i = 0; i < strlen(prefix); i++) {
    int i_char = prefix[i] - 'a';
    if (p->next[i_char] == NULL) {
      return false;
    }
    p = p->next[i_char];
  }
  return true;
}

void trieFree(Trie *obj) {
  Trie *p = obj;
  for (int i = 0; i < 26; i++) {
    if (p->next[i] != NULL) {
      trieFree(p->next[i]);
    }
  }
  free(p);
}
