#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 10
#define SUCCESS     1
#define FAILURE     0

struct Stack_{
    struct Stack_ *next;
    int value;
    int id;
};
typedef struct Stack_ Stack;

Stack* StackInit();

int push(Stack *top, int value);

int pop(Stack *top);

int peek(Stack *top);

int isEmpty(Stack *top);

void FreeStack(Stack *top);

void PrintStack(Stack *top);

void PrintStackChar(Stack *top);

#endif
