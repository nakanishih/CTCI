#ifndef LINKLIST_H
#define LINKLIST_H

struct Node_{
    struct Node_ *next;
    int value;
};
typedef struct Node_ Node;

Node* MkNode(int value);

void AppendToTail(Node *header, int value);

void RemoveFromTail(Node *header);

void PrintList(Node *header);

void FreeList(Node *header);

int CalcLengthList(Node *header);

#endif
