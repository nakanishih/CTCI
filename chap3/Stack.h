#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 10
#define SUCCESS     1
#define FAILURE     0

typedef Node Stack;

int push(Node *tail, int value);

int pop(Node *tail);

int peek(Node *tail);

int isEmpty(Node *tail);

#endif
