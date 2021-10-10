#include <stdio.h>
#include <stdlib.h>

#define NULL 0
#define INF 99999

#define WHITE 1
#define GREY 2
#define BLACK 3

#define NIL -1

enum vertices{A=0, B=1, C=2, D=3, E=4, F=5, G=6};

char invenum(int a) {
    switch(a){
    case 0:
        return 'A';
        break;
    case 1:
        return 'B';
        break;
    case 2:
        return 'C';
        break;
    case 3:
        return 'D';
        break;
    case 4:
        return 'E';
        break;
    case 5:
        return 'F';
        break;
    case 6:
        return 'G';
        break;
    case -1:
        return '@';
        break;
    }
}

class Stack {
    int* A;
    int MAXSIZE;
    int top;

public:
    Stack();
    ~Stack();
    void print();
    bool push(int item);
    bool pop(int& retval);
    bool peek(int& retval);
    bool is_empty();
};

Stack::Stack() {
    MAXSIZE = 2;
    A = (int*)malloc(MAXSIZE*sizeof(int));
    top = 0;
}

Stack::~Stack() {
    free(A);
}

void Stack::print() {
    for(int i=0; i<top; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

bool Stack::push(int item) {
    if(top == MAXSIZE) {
        int* temp = (int*)malloc(2*MAXSIZE*sizeof(int));
        if(temp == NULL)
            return false;
        for(int i=0; i<MAXSIZE; i++)
            temp[i] = A[i];
        free(A);
        A = temp;
        MAXSIZE = 2*MAXSIZE;
    }
    A[top] = item;
    top++;
    return true;
}

bool Stack::pop(int& retval) {
    if(top > 0) {
        retval = A[top-1];
        top--;
        return true;
    }
    else
        return false;
}

bool Stack::peek(int& retval) {
    if(top > 0) {
        retval = A[top-1];
        return true;
    }
    else
        return false;
}

bool Stack::is_empty() {
    if(top == 0)
        return true;
    else
        return false;
}

class Queue {
    int* A;
    int MAXSIZE;
    int len;
    int front;
    int rear;

public:
    Queue();
    ~Queue();
    void print();
    bool enqueue(int item);
    bool dequeue(int& retval);
    bool peek(int& retval);
    bool is_empty();
};

Queue::Queue() {
    MAXSIZE = 2;
    A = (int*)malloc(MAXSIZE*sizeof(int));
    len = 0;
    front = 0;
    rear = 0;
}

Queue::~Queue() {
    free(A);
}

void Queue::print() {
    printf("Queue: ");
    for(int i=0; i<len; i++) {
        printf("%d ", A[(front+i)%MAXSIZE]);
    }
    printf("\n");
}

bool Queue::enqueue(int item) {
    if(len == MAXSIZE) {
        int* temp = (int*)malloc(2*MAXSIZE*sizeof(int));
        if(temp == NULL)
            return false;
        for(int i=0; i<len; i++)
            temp[i] = A[(front+i)%MAXSIZE];
        free(A);
        A = temp;
        front = 0;
        rear = MAXSIZE;
        MAXSIZE = 2*MAXSIZE;
    }
    A[rear] = item;
    rear = (rear+1)%MAXSIZE;
    len++;
    return true;
}

bool Queue::dequeue(int& retval) {
    if(len > 0) {
        retval = A[front];
        front = (front+1)%MAXSIZE;
        len--;
        return true;
    }
    else
        return false;
}

bool Queue::peek(int& retval) {
    if(len > 0) {
        retval = A[front];
        return true;
    }
    else
        return false;
}

bool Queue::is_empty() {
    if(len == 0)
        return true;
    else
        return false;
}

struct ListNode {
    int vertex;
    int weight;
    struct ListNode* next;
};

typedef struct ListNode LN;

class SinglyLinkedList {
public:
    LN* head;

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
    void BFS(int s);
    void printPath(int* parent, int s);
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

void Graph::BFS(int s) {
        // complete this method
    int color[100];
    int dist[100];
    int parent[100];

    for(int i=0; i<nVertices; i++) {
        color[i] = WHITE;
        dist[i] = INF;
        parent[i] = NIL;
    }
    color[s] = GREY;
    dist[s] = 0;
    parent[s] = NIL;

    Queue q;
    q.enqueue(s);
    while(!q.is_empty()) {
        int u;
        q.dequeue(u);
        LN* current = adjlist[u].head;
        while(current != NULL) {
            int v = current->vertex;
            if(color[v] == WHITE) {
                color[v] = GREY;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.enqueue(v);
            }
            current = current->next; // don't forget to write this line
        }
        color[u] = BLACK;
    }

    for(int i=0; i<nVertices; i++) {
        printf("%3c ", invenum(i));
    }
    printf("\n");
    for(int i=0; i<nVertices; i++) {
        printf("%3d ", dist[i]);
    }
    printf("\n");
    for(int i=0; i<nVertices; i++) {
        printf("%3c ", invenum(parent[i]));
    }
    printf("\n");

    printPath(parent, s);
}

void Graph::printPath(int* parent, int s) {
    for(int i=0; i<nVertices; i++) {
        Stack st;
        int u = i;
        while(parent[u] != NIL) {
            st.push(u);
            u = parent[u];
        }
        printf("%3c ", invenum(s));
        while(!st.is_empty()) {
            int v;
            st.pop(v);
            printf("%3c ", invenum(v));
        }
        printf("\n");
    }
}

int main() {

    Graph graph(7, false);

    graph.addEdge(A, B);
    graph.addEdge(B, C);
    graph.addEdge(C, D);
    graph.addEdge(B, D);
    graph.addEdge(C, E);
    graph.addEdge(E, G);
    graph.addEdge(F, G);

    // graph.print();

    graph.BFS(D);

    return 0;
}
