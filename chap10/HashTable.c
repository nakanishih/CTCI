#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "HashTable.h"

// セルの生成
Cell *make_cell(const char *key, char* val, Cell *next)
{
  Cell *cp = malloc(sizeof(Cell));
  if (cp != NULL) {
    cp->key = malloc(strlen(key) + 1);
    if (cp->key == NULL) {
      free(cp);
      return NULL;
    }
    strcpy(cp->key, key);
    //cp->value = val;
    insertChar(cp,val);
    cp->next = next;
  }
  return cp;
}

// セルの廃棄
void delete_cell(Cell *cp)
{
  while (cp != NULL) {
    Cell *xs = cp->next;
    free(cp->key);
    free(cp);
    cp = xs;
  }
}

// ハッシュ表の生成
HashTable *make_hash_table(int size)
{
  HashTable *ht = malloc(sizeof(HashTable));
  if (ht != NULL) {
    ht->size = size;
    ht->count = 0;
    ht->table = malloc(sizeof(Cell *) * size);
    if (ht->table == NULL) {
      free(ht);
      return NULL;
    }
    // 初期化
    for (int i = 0; i < size; i++) ht->table[i] = NULL;
  }
  return ht;
}

// ハッシュ表の廃棄
void delete_hash_table(HashTable *ht)
{
  for (int i = 0; i < ht->size; i++)
    delete_cell(ht->table[i]);
  free(ht);
}

// ハッシュ関数
int hash_func(HashTable *ht, const char *key)
{
  unsigned int value = 0;
  for (; *key != '\0'; key++)
    value = (value << 3) + *key;
  return value % ht->size;
}

// 作業用関数
Cell *search_cell(HashTable *ht, const char *key, int hval)
{
  Cell *cp = ht->table[hval];
  for (; cp != NULL; cp = cp->next) {
    if (strcmp(cp->key, key) == 0) {
      return cp;
    }
  }
  return NULL;
}

// 探索
char* search_hash(HashTable *ht, const char *key, bool *err)
{
  Cell *cp = search_cell(ht, key, hash_func(ht, key));
  if (cp != NULL) {
    *err = true;
    return cp->value;
  }
  *err = false;
  return 0;
}

// 挿入
bool insert_hash(HashTable *ht, const char *key, char* val)
{
  int hval = hash_func(ht, key);
  Cell *cp = search_cell(ht, key, hval);
  if (cp == NULL) {
    // 先頭に追加
    ht->table[hval] = make_cell(key, val, ht->table[hval]);
    ht->count++;
    return true;
  } else {
    // 値を書き換える
    //cp->value = val;
    insertChar(cp,val);
    return false;
  }
}

// 削除
bool delete_hash(HashTable *ht, const char *key)
{
  int hval = hash_func(ht, key);
  Cell *cp = ht->table[hval];
  if (cp != NULL) {
    if (strcmp(cp->key, key) == 0) {
      // 先頭データを削除
      ht->table[hval] = cp->next;
      ht->count--;
      free(cp->key);
      free(cp);
      return true;
    } else {
      // リストの途中から削除
      for (; cp->next != NULL; cp = cp->next) {
        if (strcmp(cp->next->key, key) == 0) {
          Cell *del = cp->next;
          cp->next = cp->next->next;
          ht->count--;
          free(del->key);
          free(del);
          return true;
        }
      }
    }
  }
  return false;
}

//// 巡回
//void foreach_hash(void (*func)(const char *, int), HashTable *ht)
//{
//  for (int i = 0; i < ht->size; i++) {
//    for (Cell *cp = ht->table[i]; cp != NULL; cp = cp->next)
//      func(cp->key, cp->value);
//  }
//}

// ハッシュは空か
bool is_empty_hash(HashTable *ht)
{
  return ht->count == 0;
}

// 要素数を返す
int length_hash(HashTable *ht)
{
  return ht->count;
}

// ハッシュを空にする
void clear_hash(HashTable *ht)
{
  ht->count =0;
  for (int i = 0; i < ht->size; i++) {
    delete_cell(ht->table[i]);
    ht->table[i] = NULL;
  }
}

void insertChar(Cell* cp, char* val)
{
    int i;
    for(i=0;i<CHARSIZE;i++){
        cp->value[i] = val[i];
    }
}
