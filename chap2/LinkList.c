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
    Node *swap = NULL;
    while(temp!=NULL){
        swap = temp->next;
        free(temp);
        temp = swap;
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

