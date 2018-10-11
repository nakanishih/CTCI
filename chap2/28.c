#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int CheckLoop(Node *header){
    Node *rnr1,*rnr2;
    int cnt;
    rnr1 = rnr2 = header;
    cnt = 0;

    // runner technique
    while(rnr1->next->next!=NULL){
        cnt++;
        rnr1=rnr1->next->next;
        rnr2=rnr2->next;
        if(rnr1==rnr2){
            rnr1=header;
            while(rnr1!=rnr2){
                rnr1=rnr1->next;
                rnr2=rnr2->next;
            }
            return rnr1->value;
        }
    }
    return -1;
}


int main(void){
    Node *N,*tmp,*tmp2;
    int Array[] ={2,3,5,7,11,13,17,19,23,29};
    int i;


    int LenAry = sizeof(Array)/sizeof(Array[0]);
    N = MkListFromAry(Array,LenAry);

    tmp = tmp2 = N;
    while(tmp->next!=NULL)  tmp=tmp->next;
    for(i=0;i<3;i++) tmp2=tmp2->next;
    tmp->next = tmp2;

    tmp=N;
    printf("List : { ");
    for(i=0;i<15;i++){
        printf("%d ",tmp->value);
        tmp = tmp->next;
    }
    printf("}\n");
    //PrintList(N);

    int Result = CheckLoop(N);

    if(Result!=-1){
        printf("%d\n",Result);
    }else{
        printf("No loop\n");
    }

    FreeList(N);

    return 0;
}
