#include <stdio.h>
#include <stdlib.h>

#define NULL 0

enum vertices{A=0, B=1, C=2, D=3, E=4, F=5};

class Graph {
    int adjmat[100][100];
    int nVertices;
    bool directed;

public:
    Graph(int n, bool dir);
    ~Graph();
    void addEdge(int u, int v, int weight);
    void print();
    void printMutual(int u, int v);
};

Graph::Graph(int n, bool dir) {
    nVertices = n;
    directed = dir;
    for(int i=0; i<nVertices; i++)
        for(int j=0; j<nVertices; j++)
            adjmat[i][j] = 0;
}

Graph::~Graph() {}

void Graph::addEdge(int u, int v, int weight=1) {
    adjmat[u][v] = weight;
    if(!directed)
        adjmat[v][u] = weight;
}

void Graph::print() {
    for(int i=0; i<nVertices; i++) {
        for(int j=0; j<nVertices; j++) {
            printf("%3d ", adjmat[i][j]);
        }
        printf("\n");
    }
}

void Graph::printMutual(int u, int v) {
    // complete this method
}

int main() {

    Graph G(6, false);

    G.addEdge(A, B, 20);

    G.print();

    return 0;
}
