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

class Graph {
    int adjmat[100][100];
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
        for(int v=0; v<nVertices; v++) {
            if(adjmat[u][v] != 0) {
                if(color[v] == WHITE) {
                    color[v]= GREY;
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.enqueue(v);
                }
            }
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
