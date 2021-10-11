#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct ListNode {
    int data;
    struct ListNode* next;
};

typedef struct ListNode LN;

class Queue {
    LN* head;
    LN* tail;

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
    head = NULL;
    tail = NULL;
}

Queue::~Queue() {
    // write your code here
    LN* current = head;
    LN* temp = NULL;
    while (current != NULL){
        temp = current->next;
        free(current);
        current = temp;
    }
}

void Queue::print() {
    LN* current = head;
    while(current != NULL) {
        printf("->%d", current->data);
        current = current->next;
    }
    printf("->\n");
}

bool Queue::enqueue(int item) {
    LN* newNode = (LN*)malloc(sizeof(LN));
    if(newNode == NULL)
        return false;
    else {
        newNode->data = item;
        newNode->next = NULL;
        if(tail == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        return true;
    }
}

bool Queue::dequeue(int& retval) {
    if(head == NULL)
        return false;
    else {
        retval = head->data;
        LN* current = head;
        head = head->next;
        if(head == NULL)
            tail = NULL;
        free(current);
        return true;
    }
}

bool Queue::peek(int& retval) {
    if(head == NULL)
        return false;
    else {
        retval = head->data;
        return true;
    }
}

bool Queue::is_empty() {
    if(head == NULL)
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
