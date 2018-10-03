#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int CheckPalindrome(Node *header){

    Node *tmp = header;
    Node *head = header;
    Node *tail = NULL;

    int LenList = CalcLengthList(header);
    int Len1 = LenList/2;
    int i,cnt=0;

    while(cnt<Len1){
        tmp=tmp->next;
        cnt ++;
    }

    while(tmp!=NULL){
        if(tail==NULL){
            tail=MkNode(tmp->value);
        }else{
            AppendToHead(tail,tmp->value);
        }
        tmp=tmp->next;
    }

    while(tail!=NULL){
        if(tail->value!=head->value) return 0;
        tail=tail->next;
        head=head->next;
    }

    return 1;
}

int main(void){
    Node *N;
    //int Array[] = {'a','b','c','d','c','b','a'};
    //int Array[] = {'a','b','c','c','b','a'};
    int Array[] = {'a','b','d','e'};
    int i;
    char C;

    int LenAry = sizeof(Array)/sizeof(Array[0]);

    N = MkListFromAry(Array,LenAry); 
    PrintListChar(N);

    int Result = CheckPalindrome(N);

    if(Result){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }

    FreeList(N);
    return 0;
}
