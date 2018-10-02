#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

int main(void){

    int value,i;
    printf("Enter Head Value : ");
    scanf("%d",&value);

    Node *N=MkNode(value);
    for(i=1;i<5;i++){
        AppendToHead(N,value+i);
    }
    PrintList(N);

    RemoveFromHead(N);
    PrintList(N);

    FreeList(N);
    return 0;
}
