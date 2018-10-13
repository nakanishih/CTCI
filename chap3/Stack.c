#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

Stack* StackInit(){
    Stack* new = (Stack *)malloc(sizeof(Stack));
    if(new!=NULL){
        new->next = NULL;
        new->value = EOF;
        new->id = 0;
    }
    return new;
}

int push(Stack *top, int value){
    if(top->id<STACK_SIZE){
        Stack* new = (Stack *)malloc(sizeof(Stack));
        if(new!=NULL){
            new->next = top->next;
            new->value = top->value;
            new->id = top->id;
        }
        top->value = value;
        top->id = new->id+1;
        top->next = new;

        return SUCCESS;
    }else{
        return FAILURE;
    }
}

int pop(Stack *top){
    if(top->id==0){
        return FAILURE;
    }else{
        Stack *swap = top->next;

        top->value = top->next->value;
        top->id = top->next->id;
        top->next = top->next->next;
        free(swap);

        return SUCCESS;
    }
}

int peek(Stack *top){
    return top->value;
}

int isEmpty(Stack *top){
    if(top->id==0) return 1;
    return 0;
}

void FreeStack(Stack *top){
    Stack *temp = top;
    Stack *temp2 = top;
    Stack *swap = NULL;
    while(temp2!=NULL){
        swap = temp2->next;
        free(temp);
        temp = NULL;
        temp2 = temp = swap;
    }
}

void PrintStack(Stack *top){
    int Len = top->id;
    printf("Stack : [ ");
    while(top->id!=0){
        printf("%d ",top->value);
        top = top->next;
    }
    printf("] ; %d\n",Len);
}

void PrintStackChar(Stack *top){
    int Len = top->id;
    printf("Stack : [ ");
    while(top->id!=0){
        printf("%c ",top->value);
        top = top->next;
    }
    printf("] ; %d\n",Len);
}

