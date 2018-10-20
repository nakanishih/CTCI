#ifndef HASHTABLE_H
#define HASHTABLE_H

#define CHARSIZE 10

// 連結リスト
typedef struct cell {
  char *key;
  char  value[CHARSIZE];
  struct cell *next;
} Cell;

// ハッシュ表
typedef struct {
  int size, count;
  Cell **table;
} HashTable;

Cell *make_cell(const char *key, char* val, Cell *next);
void delete_cell(Cell *cp);
HashTable *make_hash_table(int size);
void delete_hash_table(HashTable *ht);
int hash_func(HashTable *ht, const char *key);
Cell *search_cell(HashTable *ht, const char *key, int hval);
char* search_hash(HashTable *ht, const char *key, bool *err);
bool insert_hash(HashTable *ht, const char *key, char* val);
bool delete_hash(HashTable *ht, const char *key);
//void foreach_hash(void (*func)(const char *, int), HashTable *ht);
bool is_empty_hash(HashTable *ht);
int length_hash(HashTable *ht);
void clear_hash(HashTable *ht);
void insertChar(Cell *cp, char* val);

#endif
