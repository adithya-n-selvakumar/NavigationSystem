// stack.cpp
// Adithya N. Selvakumar, anselvak, 1234965019
#include "stack.h"
#include <cstdlib>

void InitializeStack(STACK *stack, int capacity) {
    stack->capacity = capacity;
    stack->top = 0;
    stack->S = (ELEMENT**) calloc(capacity + 1, sizeof(ELEMENT*));
}

void Push(STACK *stack, ELEMENT *element) {
    if (stack->top == stack->capacity) {
        return;
    }
    stack->top++;
    stack->S[stack->top] = element;
}

ELEMENT* Pop(STACK *stack) {
    if (stack->top == 0) {
        return nullptr;
    }
    ELEMENT* element = stack->S[stack->top];
    stack->top--;
    return element;
}

int IsEmpty(STACK *stack) {
    return stack->top == 0;
}

void DestroyStack(STACK *stack) {
    free(stack->S);
    stack->S = nullptr;
    stack->capacity = 0;
    stack->top = 0;
}

void ClearStack(STACK *stack) {
    stack->top = 0;
}