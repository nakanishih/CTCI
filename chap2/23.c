#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

void RemoveElement(Node *header, int value){
    int i;
    Node *prev = header;
    Node *swap = NULL;

    if(prev->value==value){
        *header = *prev->next;
        return;
    }

    while(prev->next!=NULL){
        if(prev->next->value==value){
            swap = prev->next;
            prev->next = prev->next->next;
            free(swap);
            break;
        }
        prev = prev->next;
    }
}

int main(void){
    Node *N;
    int Array[10] ={'a','b','c','d','e','f','g','h','i','j'};
    int i;
    char C;

    for(i=0;i<10;i++){
        if(i==0){
            N = MkNode(Array[0]);
        }else{
            AppendToTail(N,Array[i]);
        }
    }
    PrintListChar(N);

    printf("指定した文字を削除します\n");
    printf("Charater : ");
    scanf("%c",&C);

    RemoveElement(N,(int)C );

    PrintListChar(N);

    int LenList = CalcLengthList(N);

    printf("%d\n",LenList);

    FreeList(N);
    return 0;
}

