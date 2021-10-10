#include <stdio.h>
#include <stdlib.h>

#define NULL 0

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
    void  print();
    bool insert_first(int item);
    bool insert_last(int item);
    bool insert_after(int newval, int oldval);
    bool delete_first();
};

SinglyLinkedList::SinglyLinkedList() {
    head = NULL;
}

SinglyLinkedList::~SinglyLinkedList() {
    // write your code here
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

bool SinglyLinkedList::insert_last(int item) {
    if(is_empty()) { // this is a boundary/corner case
        return insert_first(item);
    }

    LN* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    LN* newNode = (LN*)malloc(sizeof(LN));
    if(newNode == NULL)
        return false;
    else {
        newNode->data = item;
        newNode->next = NULL;
        current->next = newNode;
        return true;
    }
}

bool SinglyLinkedList::insert_after(int newval, int oldval) {
    // write your code here
    LN* current = head;
    while(current != NULL && current->data != oldval) {
        current = current->next;
    }
    if(current == NULL)
        return false;
    else {
        LN* newNode = (LN*)malloc(sizeof(LN));
        if(newNode == NULL)
            return false;
        else {
            newNode->data = newval;
            newNode->next = current->next;
            current->next = newNode;
            return true;
        }
    }
}

bool SinglyLinkedList::delete_first() {
    if(is_empty())
        return false;
    else {
        LN* current = head;
        head = head->next;
        free(current);
        return true;
    }
}

int main() {
    SinglyLinkedList A;
    A.print();
    A.insert_last(10);
    A.print();
    A.insert_last(20);
    A.print();
    A.insert_last(30);
    A.print();
    A.insert_last(40);
    A.print();

    A.delete_first();
    A.print();
    A.delete_first();
    A.print();
    A.delete_first();
    A.print();
    A.delete_first();
    A.print();

    return 0;
}
