#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int CheckDuplicate(Node *header){
    Node *run_n = header;
    Node *Dic,*run_dic,*temp;
    int dup_bool;

    int LenList = CalcLengthList(header);
    if(LenList==0) return 0;

    Dic = MkNode(header->value);

    while(run_n->next!=NULL){
        run_dic = Dic;
        dup_bool = 0;
        while(run_dic!=NULL){
            if(run_dic->value==run_n->next->value){
                temp = run_n->next;
                dup_bool=1;
            }
            run_dic = run_dic->next;
        }
        //printf("%d,%d\n",dup_bool,run_n->next->value);

        if(dup_bool==0){
            AppendToTail(Dic,run_n->next->value);
            run_n = run_n->next;
        }else{
            run_n->next = run_n->next->next;
            free(temp);
        }
        //PrintList(Dic);
    }
    return 0;
}

int main(void){

    Node *N;
    int Array[10] ={0,1,1,4,5,6,4,2,3,4};
    int i;

    for(i=0;i<10;i++){
        if(i==0){
            N = MkNode(Array[0]);
        }else{
            AppendToTail(N,Array[i]);
        }
    }
    PrintList(N);

    CheckDuplicate(N);

    PrintList(N);

    FreeList(N);
    return 0;
}
