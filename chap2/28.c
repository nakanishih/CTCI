#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int main(void){
    Node *N;
    int Array[] = {'a','b','c','d','c','b','a'};
    //int Array[] = {'a','b','c','c','b','a'};
    //int Array[] = {'a','b','d','e'};
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
