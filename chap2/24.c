#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

void SwapValue(Node *A, Node *B){
    int swap;
    swap = A->value;
    A->value = B->value;
    B->value = swap;
}

void ValueUnderValue(Node *header, int value){
    Node *wtcN = header;
    Node *cntN = header;

    while(wtcN!=NULL){
        if(wtcN->value<value){
            SwapValue(cntN,wtcN);
            cntN = cntN->next;
        }
        wtcN = wtcN->next;
    }

}

int main(void){
    Node *N;
    //int Array[10] ={31,23,17,13,11,7,5,3,2,1};
    int Array[10] ={3,5,8,5,10,2,1,9,2,1};
    int i;
    int value;

    for(i=0;i<10;i++){
        if(i==0){
            N = MkNode(Array[0]);
        }else{
            AppendToTail(N,Array[i]);
        }
    }
    PrintList(N);

    printf("指定の数値より小さい値を前に表示します.\n");
    printf("Enter Number : ");
    scanf("%d",&value);

    ValueUnderValue(N,value);
    PrintList(N);

    FreeList(N);
    return 0;
}
