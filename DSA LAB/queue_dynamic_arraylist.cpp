#include <stdio.h>
#include <stdlib.h>

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

int main() {

    Queue q;
    int x;

    q.enqueue(10);
    q.print();
    q.enqueue(15);
    q.print();
    q.enqueue(20);
    q.print();

    q.dequeue(x);
    printf("Dequeued %d\n", x);
    q.print();

    q.enqueue(25);
    q.print();
    q.enqueue(35);
    q.print();
    q.enqueue(31);
    q.print();

    q.dequeue(x);
    printf("Dequeued %d\n", x);
    q.print();

    q.dequeue(x);
    printf("Dequeued %d\n", x);
    q.print();

    q.dequeue(x);
    printf("Dequeued %d\n", x);
    q.print();

    q.dequeue(x);
    printf("Dequeued %d\n", x);
    q.print();

    q.dequeue(x);
    printf("Dequeued %d\n", x);
    q.print();



    return 0;
}
