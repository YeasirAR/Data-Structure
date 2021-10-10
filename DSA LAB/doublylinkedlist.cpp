#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct ListNode {
    int data;
    struct ListNode* next;
    struct ListNode* prev;
};

typedef struct ListNode LN;

class DoublyLinkedList {
    LN* head;
    LN* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    bool is_empty();
    void forward_print();
    void backward_print();
    void print();
    bool insert_first(int item);
    bool insert_last(int item);
    bool insert_after(int oldval, int newval);
};

DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList() {
    // complete this method
}

bool DoublyLinkedList::is_empty() {
    if(head == NULL)
        return true;
    else
        return false;
}

void DoublyLinkedList::forward_print() {
    LN* current = head;
    printf("forward:");
    while(current != NULL) {
        printf("->%d", current->data);
        current = current->next;
    }
    printf("->\n");
}

void DoublyLinkedList::backward_print() {
    LN* current = tail;
    printf("backward:");
    while(current != NULL) {
        printf("->%d", current->data);
        current = current->prev;
    }
    printf("->\n");
}

void DoublyLinkedList::print() {
    forward_print();
    backward_print();
}

bool DoublyLinkedList::insert_first(int item) {
    // complete_this_method
    LN* newNode = (LN*)malloc(sizeof(LN));
    if(newNode == NULL)
        return false;
    else {
        newNode->data = item;
        newNode->prev = NULL;
        newNode->next = head;
        if(head == NULL)
            tail = newNode;
        else
            head->prev = newNode;
        head = newNode;
        return true;
    }
}

bool DoublyLinkedList::insert_last(int item) {
    // make necessary changes
    LN* newNode = (LN*)malloc(sizeof(LN));
    if(newNode == NULL)
        return false;
    else {
        newNode->data = item;
        newNode->next = NULL;
        newNode->prev = tail;
        if(tail == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        return true;
    }
}

bool DoublyLinkedList::insert_after(int oldval, int newval) {
    // complete this method
}

bool DoublyLinkedList::insert_before(int oldval, int newval) {
    // complete this method from insert_after
    // using symmetric property
}

bool DoublyLinkedList::remove_first() {
    // complete this method
}

bool DoublyLinkedList::remove_last() {
    // complete this method from remove_first
    // using symmetric property
}

int main() {
    DoublyLinkedList A;

    A.print();

    A.insert_last(10);
    A.insert_last(20);
    A.insert_last(30);
    A.insert_last(40);

    A.print();

    return 0;
}
