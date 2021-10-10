#include <stdio.h>
#include <stdlib.h>

#define NULL 0

enum vertices{A=0, B=1, C=2, D=3, E=4, F=5};

struct ListNode {
    int vertex;
    int weight;
    struct ListNode* next;
};

typedef struct ListNode LN;

class SinglyLinkedList {
    LN* head;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    bool is_empty();
    void print();
    bool insert_first(int u, int w);
    LN* search(int key);
};

SinglyLinkedList::SinglyLinkedList() {
    head = NULL;
}

SinglyLinkedList::~SinglyLinkedList() {
    LN* current = head;
    LN* temp = NULL;
    while(current != NULL) {
        temp = current->next;;
        free(current);
        current = temp;
    }
}

bool SinglyLinkedList::is_empty() {
    if(head == NULL)
        return true;
    else
        return false;
}

void SinglyLinkedList::print() {
    LN* current = head;
    while(current != NULL) {
        printf("->%d(%d)", current->vertex, current->weight);
        current = current->next;
    }
    printf("->\n");
}

bool SinglyLinkedList::insert_first(int u, int w) {
    LN* newNode = (LN*)malloc(sizeof(LN));
    if(newNode == NULL)
        return false;
    else {
        newNode->vertex = u;
        newNode->weight = w;
        newNode->next = head;
        head = newNode;
        return true;
    }
}

LN* SinglyLinkedList::search(int key){
    LN* temp = head;
    while(temp != NULL) {
        if(temp->vertex == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

class Graph {
    SinglyLinkedList adjlist[100];
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
}

Graph::~Graph() {}

void Graph::addEdge(int u, int v, int weight=1) {
    adjlist[u].insert_first(v, weight);
    if(!directed)
        adjlist[v].insert_first(u, weight);
}

void Graph::print() {
    for(int i=0; i<nVertices; i++) {
        printf("%d: ", i);
        adjlist[i].print();
    }
}

void Graph::printMutual(int u, int v) {

}

int main() {
    Graph G(6, false);

    G.addEdge(A, B);
    G.addEdge(A, E);
    G.addEdge(B, C);
    G.addEdge(B, D);


    G.print();

    return 0;
}
