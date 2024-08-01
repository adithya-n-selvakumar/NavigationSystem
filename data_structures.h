// data_structures.h
// Adithya N. Selvakumar, anselvak, 1234965019
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

typedef struct TAG_ELEMENT {
    int node;
    double key;
    int pi;
    int position;
} ELEMENT;

typedef struct TAG_HEAP {
    int capacity;
    int size;
    ELEMENT **H;
} HEAP;

typedef struct TAG_NODE {
    int v;
    double w;
    struct TAG_NODE *next;
} NODE;

typedef struct TAG_GRAPH {
    int V;
    int E;
    NODE **adj;
    ELEMENT *nodes;
} GRAPH;

#endif // DATA_STRUCTURES_H