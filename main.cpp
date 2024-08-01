// main.cpp
// Adithya N. Selvakumar, anselvak, 1234965019
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
#include <iomanip>
#include "graph.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: ./PJ3 <InputFile> <GraphType> <Flag>\n");
        return 1;
    }

    const char *inputFile = argv[1];
    const char *graphType = argv[2];
    int flag = atoi(argv[3]);

    if (strcmp(graphType, "DirectedGraph") != 0 && strcmp(graphType, "UndirectedGraph") != 0) {
        fprintf(stderr, "Invalid graph type.\n");
        return 1;
    }

    if (flag != 1 && flag != 2) {
        fprintf(stderr, "Invalid flag value.\n");
        return 1;
    }

    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Cannot open input file." << std::endl;
        return 1;
    }

    int V, E;
    inFile >> V >> E;
    GRAPH *G = CreateGraph(V);

    for (int i = 0; i < E; i++) {
        int edgeIndex, u, v;
        double w;
        inFile >> edgeIndex >> u >> v >> w;
        AddEdge(G, u, v, w, flag);
        if (strcmp(graphType, "UndirectedGraph") == 0) {
            AddEdge(G, v, u, w, flag);
        }
    }

    std::string command;
    int last_source = -1;

    while (std::cin >> command) {
        if (command == "Stop") {
            break;
        } else if (command == "PrintADJ") {
            PrintADJ(G);
        } else if (command == "SinglePair") {
            int s, t;
            if (std::cin >> s >> t) {
                if (s < 1 || s > V || t < 1 || t > V) {
                    std::cerr << "Error: Invalid SinglePair instruction." << std::endl;
                } else {
                    Dijkstra(G, s);
                    last_source = s;
                    //PrintPath(G, s, t);
                }
            } else {
                std::cerr << "Error: Invalid SinglePair instruction." << std::endl;
            }
        } else if (command == "SingleSource") {
            int s;
            if (std::cin >> s) {
                if (s < 1 || s > V) {
                    std::cerr << "Error: Invalid SingleSource instruction." << std::endl;
                } else {
                    Dijkstra(G, s);
                    last_source = s;
                }
            } else {
                std::cerr << "Error: Invalid SingleSource instruction." << std::endl;
            }
        } else if (command == "PrintLength") {
            int s, t;
            if (std::cin >> s >> t) {
                if (s == last_source) {
                    PrintLength(G, s, t);
                } else {
                    std::cerr << "Error: Invalid source for PrintLength." << std::endl;
                }
            } else {
                std::cerr << "Error: Invalid PrintLength instruction." << std::endl;
            }
        } else if (command == "PrintPath") {
            int s, t;
            if (std::cin >> s >> t) {
                if (s == last_source) {
                    PrintPath(G, s, t);
                } else {
                    std::cerr << "Error: Invalid source for PrintPath." << std::endl;
                }
            } else {
                std::cerr << "Error: Invalid PrintPath instruction." << std::endl;
            }
        } else {
            std::cerr << "Error: Invalid instruction." << std::endl;
        }
    }

    DestroyGraph(G);
    return 0;
}