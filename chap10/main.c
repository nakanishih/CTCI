#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "HashTable.h"

int main(void)
{
  char x[CHARSIZE];

  char buff[8][12];
  HashTable *ht = make_hash_table(5);
  bool err;
  printf("-- %d, %d --\n", is_empty_hash(ht), length_hash(ht));
  printf("----- insert -----\n");
  for (int i = 0; i < 8; i++) {
    sprintf(buff[i], "%d", rand());
    printf("%s, %d\n", buff[i], insert_hash(ht, buff[i], "AAA"));
  }
  printf("-- %d, %d --\n", is_empty_hash(ht), length_hash(ht));
  printf("------ search ------\n");
  for (int i = 0; i < 8; i++) 
    printf("%s, %s\n", buff[i], search_hash(ht, buff[i], &err)); 
  printf("------ delete ------\n");
  for (int i = 0; i < 8; i++) {
    printf("%s %d\n", buff[i], delete_hash(ht, buff[i]));
    printf("%s, %s, %d\n", buff[i], search_hash(ht, buff[i], &err), err);
  } 
  printf("-- %d, %d --\n", is_empty_hash(ht), length_hash(ht));
  printf("----- delete hash -----\n");
  delete_hash_table(ht);

  return 0;
}

