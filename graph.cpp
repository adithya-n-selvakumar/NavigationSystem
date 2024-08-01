// graph.cpp
// Adithya N. Selvakumar, anselvak, 1234965019
#include "graph.h"
#include "heap.h"
#include "stack.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>

GRAPH *CreateGraph(int V) {
    GRAPH *G = (GRAPH*) malloc(sizeof(GRAPH));
    G->V = V;
    G->E = 0;
    G->adj = (NODE**) calloc(V, sizeof(NODE*));
    G->nodes = (ELEMENT*) malloc(V * sizeof(ELEMENT));
    for (int i = 0; i < V; i++) {
        G->nodes[i].node = i + 1;
        G->nodes[i].key = std::numeric_limits<double>::infinity();
        G->nodes[i].pi = -1;
        G->nodes[i].position = i;
    }
    return G;
}

void AddEdge(GRAPH *G, int u, int v, double w, int flag) {
    NODE *node = (NODE*) malloc(sizeof(NODE));
    node->v = v;
    node->w = w;
    node->next = nullptr;
    if (flag == 1) {
        node->next = G->adj[u-1];
        G->adj[u-1] = node;
    } else {
        NODE *temp = G->adj[u-1];
        if (temp == nullptr) {
            G->adj[u-1] = node;
        } else {
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }
    G->E++;
}

void Dijkstra(GRAPH *G, int s) {
    HEAP heap;
    InitializeHeap(&heap, G->V);
    
    for (int i = 0; i < G->V; i++) {
        G->nodes[i].key = std::numeric_limits<double>::infinity();
        G->nodes[i].pi = -1;
    }
    G->nodes[s-1].key = 0;
    
    for (int i = 0; i < G->V; i++)
        Insert(&heap, &G->nodes[i]);
    
    while (heap.size > 0) {
        ELEMENT *u = ExtractMin(&heap);
        NODE *edge = G->adj[u->node - 1];
        while (edge) {
            ELEMENT *v = &G->nodes[edge->v - 1];
            if (v->key > u->key + edge->w) {
                v->key = u->key + edge->w;
                v->pi = u->node;
                DecreaseKey(&heap, v->position, v->key);
            }
            edge = edge->next;
        }
    }
    
    DestroyHeap(&heap);
}

void PrintPath(GRAPH *G, int s, int t) {
    STACK stack;
    InitializeStack(&stack, G->V);

    int current = t;
    while (current != s && G->nodes[current-1].pi != -1) {
        Push(&stack, &G->nodes[current-1]);
        current = G->nodes[current-1].pi;
    }
    Push(&stack, &G->nodes[s-1]);

    if (current != s) {
        std::cout << "There is no path from " << s << " to " << t << "." << std::endl;
    } else {
        std::cout << "The shortest path from " << s << " to " << t << " is:" << std::endl;
        bool first = true;
        while (!IsEmpty(&stack)) {
            ELEMENT *vertex = Pop(&stack);
            if (!first) std::cout << "-->";
            std::cout << "[" << vertex->node << ":    " << std::fixed << std::setprecision(2) << vertex->key << "]";
            first = false;
        }
        std::cout << "." << std::endl;
    }

    DestroyStack(&stack);
}

void DestroyGraph(GRAPH *G) {
    for (int i = 0; i < G->V; i++) {
        NODE *node = G->adj[i];
        while (node) {
            NODE *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(G->adj);
    free(G->nodes);
    free(G);
}

void PrintADJ(GRAPH *G) {
    for (int i = 0; i < G->V; i++) {
        std::cout << "ADJ[" << i+1 << "]:";
        NODE *temp = G->adj[i];
        while (temp) {
            std::cout << "-->[" << i+1 << " " << temp->v << ": " << std::fixed << std::setprecision(2) << temp->w << "]";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

void PrintLength(GRAPH *G, int s, int t) {
    if (G->nodes[t-1].key == std::numeric_limits<double>::infinity()) {
        std::cout << "There is no path from " << s << " to " << t << "." << std::endl;
    } else {
        std::cout << "The length of the shortest path from " << s << " to " << t << " is:     " 
                  << std::fixed << std::setprecision(2) << G->nodes[t-1].key << std::endl;
    }
}