#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"
#include "Stack.h"

int push(Stack *tail, int value){
    int LenStack = CalcLengthList(tail);
    if(LenStack<STACK_SIZE){
        AppendToHead(tail,value);
        return SUCCESS;
    }else{
        return FAILURE;
    }
}

int pop(Stack *tail){
    int LenStack = CalcLengthList(tail);
    if(LenStack==0){
        return SUCCESS;
    }else{
        RemoveFromHead(*tail);
        return FAILURE;
    }
}

int peek(Stack *tail){
    int LenStack = CalcLengthList(tail);
    if(LenStack==0){
        return NULL;
    }else{
        return tail->value;
    }
}

int isEmpty(Stack *tail){
    if(CalcLengthList(tail)==0) return 1;
    return 0;
}

