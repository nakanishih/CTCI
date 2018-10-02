#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

Node* SumList(Node *A, Node*B, int Head){
    Node *swpN;
    Node *N=NULL;
    int value;
    int cnt=0;
    void (*AppendTo)(Node*, int);

    if(Head){
        AppendTo = AppendToHead;
    }else{
        AppendTo = AppendToTail;
    }

    int LenA = CalcLengthList(A);
    int LenB = CalcLengthList(B);

    if(LenA<LenB){
        swpN = A;
        A = B;
        B = swpN;
    }

    while(A!=NULL){
        value = A->value+B->value+cnt;
        cnt = value/10;
        value = value%10;

        if(N==NULL){
            N = MkNode(value);
        }else{
            (*AppendTo)(N,value);
        }

        A = A->next;
        B = B->next;
    }

    if(cnt==1) (*AppendTo)(N,1);

    return N;
}

int main(void){
    Node *N1,*N2;
    int Array1[3] = {3,5,8};
    int Array2[3] = {4,2,6};

    int LenAry1 = sizeof(Array1)/sizeof(Array1[0]);
    int LenAry2 = sizeof(Array2)/sizeof(Array2[0]);

    N1 = MkListFromAry(Array1,LenAry1);
    N2 = MkListFromAry(Array2,LenAry2);

    PrintList(N1);
    PrintList(N2);

    Node *N = SumList(N1,N2,1);
    PrintList(N);

    FreeList(N1);
    FreeList(N2);

    return 0;
}
