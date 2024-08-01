// graph.h
// Adithya N. Selvakumar, anselvak, 1234965019
#ifndef GRAPH_H
#define GRAPH_H

#include "data_structures.h"
#include "stack.h"

GRAPH *CreateGraph(int V);
void AddEdge(GRAPH *G, int u, int v, double w, int flag);
void Dijkstra(GRAPH *G, int s);
void PrintPath(GRAPH *G, int s, int t);
void DestroyGraph(GRAPH *G);
void PrintADJ(GRAPH *G);
void PrintLength(GRAPH *G, int s, int t);

#endif // GRAPH_H