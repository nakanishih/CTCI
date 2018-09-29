#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

int main(void){

    int value,i;
    printf("Enter Head Value : ");
    scanf("%d",&value);

    Node *N=MkNode(value);
    for(i=1;i<10;i++){
        AppendToTail(N,value+i);
    }
    PrintList(N);

    RemoveFromTail(N);
    PrintList(N);

    FreeList(N);
    return 0;
}
