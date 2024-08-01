// stack.h
// Adithya N. Selvakumar, anselvak, 1234965019
#ifndef STACK_H
#define STACK_H

#include "data_structures.h"

typedef struct TAG_STACK {
    int capacity;
    int top;
    ELEMENT **S;
} STACK;

void InitializeStack(STACK *stack, int capacity);
void Push(STACK *stack, ELEMENT *element);
ELEMENT* Pop(STACK *stack);
int IsEmpty(STACK *stack);
void DestroyStack(STACK *stack);
void ClearStack(STACK *stack);

#endif