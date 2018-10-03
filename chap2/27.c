#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int CheckCommon(Node *A, Node*B){
    Node *tmpA=A;
    Node *tmpB=B;
    int i,j;
    i=0;j=0;

    while(tmpA!=NULL){
        while(tmpB!=NULL){
            //printf("i:%d:%p , j:%d:%p\n",i,tmpA,j,tmpB);
            if(tmpA==tmpB){
                printf("The common node was finded\n");
                printf("the %d-th element of List1\n",i);
                printf("the %d-th element of List2\n",j);
                return 1;
            }
            tmpB=tmpB->next;
            j++;
        }
        tmpA=tmpA->next;
        i++;
        tmpB=B;
        j=0;
    }
    printf("No common node was finded.\n");
    return 0;
}

int main(void){
    Node *N1,*N2,*N3,*tmp;
    int Array1[] = {3,5,8,10,11};
    int Array2[] = {4,2,6};
    int Array3[] = {3,4,7};

    int LenAry1 = sizeof(Array1)/sizeof(Array1[0]);
    int LenAry2 = sizeof(Array2)/sizeof(Array2[0]);
    int LenAry3 = sizeof(Array3)/sizeof(Array3[0]);

    N1 = MkListFromAry(Array1,LenAry1);
    N2 = MkListFromAry(Array2,LenAry2);
    N3 = MkListFromAry(Array3,LenAry3);

    tmp = N1;
    while(tmp->next!=NULL)  tmp=tmp->next;
    tmp->next = N3;

    tmp = N2;
    while(tmp->next!=NULL)  tmp=tmp->next;
    tmp->next = N3;

    PrintList(N1);
    PrintList(N2);
    PrintList(N3);

    int Result = CheckCommon(N1,N2);

    if(Result){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }

    FreeList(N1);
    FreeList(N2);
    FreeList(N3);

    return 0;
}
