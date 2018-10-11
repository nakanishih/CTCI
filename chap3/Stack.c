#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

#define STACK_SIZE 10
#define SUCCESS     1
#define FAILURE     0

int push(Node *tail, int value){
    int LenStack = CalcLengthList(tail);
    if(LenStack<STACK_SIZE){
        AppendToHead(tail,value);
        return SUCCESS;
    }else{
        return FAILURE;
    }
}

int pop(Node *tail){
    int LenStack = CalcLengthList(tail);
    if(LenStack==0){
        return SUCCESS;
    }else{
        RemoveFromHead(*tail);
        return FAILURE;
    }
}

int peek(Node *tail){

