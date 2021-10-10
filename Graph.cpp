#include <stdio.h>
#include <stdlib.h>

#define NULL 0

enum vertices{A=0, B=1, C=2, D=3, E=4, F=5};

struct ListNode {
    int data;
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
    bool insert_first(int item);
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
        printf("->%d", current->data);
        current = current->next;
    }
    printf("->\n");
}

bool SinglyLinkedList::insert_first(int item) {
    LN* newNode = (LN*)malloc(sizeof(LN));
    if(newNode == NULL)
        return false;
    else {
        newNode->data = item;
        newNode->next = head;
        head = newNode;
        return true;
    }
}

LN* SinglyLinkedList::search(int key){
    LN* temp = head;
    while(temp != NULL) {
        if(temp->data == key)
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
    void addEdge(int u, int v);
    void print();
    void printMutual(int u, int v);
};

Graph::Graph(int n, bool dir) {
    nVertices = n;
    directed = dir;
}

Graph::~Graph() {}

void Graph::addEdge(int u, int v) {
    adjlist[u].insert_first(v);
    if(!directed)
        adjlist[v].insert_first(u);
}

void Graph::print() {
    for(int i=0; i<nVertices; i++) {
        printf("%d: ", i);
        adjlist[i].print();
    }
}

int main() {

    Graph G(6, false);

    G.addEdge(A, B);
    G.addEdge(A, E);
    G.addEdge(E, F);
    G.addEdge(F, C);
    G.addEdge(C, B);
    G.addEdge(C, D);
    G.addEdge(D, B);

    G.print();
    printf("\n");

    // G.print_mutual(C,D);
    // G.print_mutual(A,C);

    return 0;
}
