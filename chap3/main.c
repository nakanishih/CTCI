#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(void){

    Stack *stc=StackInit();
    //int Array[] = {'a','b','c','d','c','b','a','h','i','j','k'};
    int Array[] = {1,2,3,4,5,6,8,8,9,10,11};

    //int Array[] = {'a','b','c','c','b','a'};
    //int Array[] = {'a','b','d','e'};
    int i;
    char C;
    int result;

    int LenAry = sizeof(Array)/sizeof(Array[0]);

    for(i=0;i<LenAry;i++){
        result = push(stc,Array[i]);
        printf("push:%d ; peek:[ %d ] ; Emp:%d ;",result,peek(stc),isEmpty(stc));
        PrintStack(stc);
        //PrintStackChar(stc);
    }

    for(i=0;i<LenAry;i++){
        result = pop(stc);
        printf("pop :%d ; peek:[ %d ] ; Emp:%d ;",result,peek(stc),isEmpty(stc));
        PrintStack(stc);
        //PrintStackChar(stc);
    }

    result = pop(stc);
    printf("pop :%d ; peek:[ %d ] ; Emp:%d ;",result,peek(stc),isEmpty(stc));
    PrintStack(stc);
    //PrintStackChar(stc);

    for(i=0;i<LenAry;i++){
        result = push(stc,Array[i]);
        printf("push:%d ; peek:[ %d ] ; Emp:%d ;",result,peek(stc),isEmpty(stc));
        PrintStack(stc);
        //PrintStackChar(stc);
    }

    FreeStack(stc);
    return 0;
}
