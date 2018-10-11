#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "Stack.h"

int main(void){

    Stack *N;
    int Array[] = {'a','b','c','d','c','b','a'};
    //int Array[] = {'a','b','c','c','b','a'};
    //int Array[] = {'a','b','d','e'};
    int i;
    char C;

    int LenAry = sizeof(Array)/sizeof(Array[0]);

    N = MkListFromAry(Array,LenAry); 
    PrintListChar(N);

    return 0;
}
