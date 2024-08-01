// heap.cpp
// Adithya N. Selvakumar, anselvak, 1234965019
#include "heap.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

void InitializeHeap(HEAP *heap, int capacity) {
    heap->capacity = capacity;
    heap->size = 0;
    heap->H = (ELEMENT**) malloc(capacity * sizeof(ELEMENT*));
}

void Insert(HEAP *heap, ELEMENT *element) {
    if (heap->size == heap->capacity) {
        std::cerr << "Heap is full" << std::endl;
        return;
    }
    
    int i = heap->size;
    heap->size++;
    heap->H[i] = element;
    element->position = i;
    
    while (i > 0 && heap->H[(i-1)/2]->key > heap->H[i]->key) {
        std::swap(heap->H[i], heap->H[(i-1)/2]);
        heap->H[i]->position = i;
        heap->H[(i-1)/2]->position = (i-1)/2;
        i = (i-1)/2;
    }
}

ELEMENT *ExtractMin(HEAP *heap) {
    if (heap->size == 0) return nullptr;
    
    ELEMENT *min = heap->H[0];
    heap->H[0] = heap->H[heap->size - 1];
    heap->H[0]->position = 0;
    heap->size--;
    
    Heapify(heap, 0);
    
    return min;
}

void DecreaseKey(HEAP *heap, int position, double newKey) {
    if (newKey > heap->H[position]->key) return;
    
    heap->H[position]->key = newKey;
    while (position > 0 && heap->H[(position-1)/2]->key > heap->H[position]->key) {
        std::swap(heap->H[position], heap->H[(position-1)/2]);
        heap->H[position]->position = position;
        heap->H[(position-1)/2]->position = (position-1)/2;
        position = (position-1)/2;
    }
}

void Heapify(HEAP *heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if (left < heap->size && heap->H[left]->key < heap->H[smallest]->key)
        smallest = left;
    
    if (right < heap->size && heap->H[right]->key < heap->H[smallest]->key)
        smallest = right;
    
    if (smallest != i) {
        std::swap(heap->H[i], heap->H[smallest]);
        heap->H[i]->position = i;
        heap->H[smallest]->position = smallest;
        Heapify(heap, smallest);
    }
}

void BuildHeap(HEAP *heap) {
    for (int i = heap->size / 2 - 1; i >= 0; i--)
        Heapify(heap, i);
}

void DestroyHeap(HEAP *heap) {
    free(heap->H);
    heap->H = nullptr;
    heap->size = 0;
    heap->capacity = 0;
}