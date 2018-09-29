#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int BackKValue(Node *header, int k){

    int i;

    int LenList = CalcLengthList(header);
    if(LenList<k){
        printf("Kは連結リストの長さより短い値を指定して下さい.\n");
        return 0;
    }
    k = LenList-k;

    for(i=0;i<k;i++) header = header->next;
    printf("%d\n",header->value);
    return 0;
}

int main(void){

    Node *N;
    int Array[10] ={0,1,1,4,5,6,4,2,3,4};
    int i,k;

    for(i=0;i<10;i++){
        if(i==0){
            N = MkNode(Array[0]);
        }else{
            AppendToTail(N,Array[i]);
        }
    }
    PrintList(N);

    printf("後ろからK番目の値を返します\n");
    printf("K = ");
    scanf("%d",&k);

    BackKValue(N,k);

    FreeList(N);
    return 0;
}
