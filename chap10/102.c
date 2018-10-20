//
//
//
//
///// NOT WORK //////
//
//
//
#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

int sortChar(char* Element, int lst){
    int i,j;
    char tmp;
    char Element_[CHARSIZE];
    for(i=0;i<lst;i++){
        Element_[i]=Element[i];
    }

    for(i = 0; i < lst - 1; i++) {
        for (j = i + 1; j < lst; j++) {
            if(Element_[i]<Element_[j]){
                tmp = Element_[j];
                Element_[j] = Element_[i];
                Element_[i] = tmp;
            }
        }
    }
    //printf("%s %s %d\n",Element_, Element, lst);
    int key;
    if((int)Element_<0){
        key = (int)Element_*(-1);
    }else{
        key = (int)Element_;
    }

    return key;
}

int main(void){
    int i,key;
    char Ary[][CHARSIZE] = {"acre","levorg","orlgve","race","lrevgo","care"};
    int lst = sizeof(Ary)/sizeof(Ary[0]);
    char* result;

    // For HashTable
    HashTable *ht = make_hash_table(5);

    printf("Array:%d\n",lst);
    for(i=0;i<lst;i++){
        struct DataItem* item;
        printf("%s\n",Ary[i]);
        key = sortChar(Ary[i],CHARSIZE);
        printf("%d\n",key);
        item = search_hash(key);
        if(item != NULL){
            printf("Element found: %s\n", *item->data);
        }else{
            printf("Element not found. Insert key:%d, Char:%s\n",key,Ary[i]);
            insert(key,Ary[i]);
        }
        delete(item);
    }

    return 0;
}
