// heap.h
// Adithya N. Selvakumar, anselvak, 1234965019
#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

void InitializeHeap(HEAP *heap, int capacity);
void Insert(HEAP *heap, ELEMENT *element);
ELEMENT *ExtractMin(HEAP *heap);
void DecreaseKey(HEAP *heap, int position, double newKey);
void Heapify(HEAP *heap, int i);
void BuildHeap(HEAP *heap);
void DestroyHeap(HEAP *heap);

#endif // HEAP_H