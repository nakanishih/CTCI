#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

Node* MkNode(int value){
    Node *N;
    N = (Node *)malloc(sizeof(Node));
    if(N!=NULL){
        N->next = NULL;
        N->value = value;
    }
    return N;
}

void AppendToTail(Node *header, int value){
    Node *N_new = MkNode(value);
    Node *prev = header;

    while(prev->next!=NULL){
        prev = prev->next;
    }
    prev->next = N_new;
}

void RemoveFromTail(Node *header){
    Node *prev = header;
    Node *temp = NULL;
    while(prev->next->next!=NULL){
        prev = prev->next;
    }
    temp = prev->next;
    prev->next = NULL;
    free(temp);
}

void AppendToHead(Node *header, int value){
    Node *swap = MkNode(header->value);
    swap->next=header->next;

    header->value = value;
    header->next = swap;
}

void RemoveFromHead(Node *header){
    Node *swap = header->next;

    header->value = header->next->value;
    header->next = header->next->next;

    free(swap);
}

void PrintList(Node *header){
    printf("List : { ");
    while(header!=NULL){
        printf("%d ",header->value);
        header = header->next;
    }
    printf("}\n");
}

void PrintListChar(Node *header){
    printf("List : { ");
    while(header!=NULL){
        printf("%c ",header->value);
        header = header->next;
    }
    printf("}\n");
}

void FreeList(Node *header){
    Node *temp = header;
    Node *temp2;
    Node *swap = NULL;
    while(temp2!=NULL){
        swap = temp2->next;
        free(temp);
        temp = NULL;
        temp2 = temp = swap;
    }
}

int CalcLengthList(Node *header){
    int counter=0;
    Node *prev = header;
    while(prev!=NULL){
        counter ++;
        prev = prev->next;
    }
    return counter;
}

Node* MkListFromAry(int Ary[], int LenAry){
    Node *N;
    int i;

    for(i=0;i<LenAry;i++){
        if(i==0){
            N = MkNode(Ary[0]);
        }else{
            AppendToTail(N,Ary[i]);
        }
    }
    return N;
}

