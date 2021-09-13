#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct list {
    int data;
    struct list* next;
    struct list* back;
};

typedef struct list node;

class DoublyLinkedList {
    node* start;
    node* temp;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void print();
    node* insert_ascending(int item);
};

DoublyLinkedList::DoublyLinkedList() {
    start = NULL;
    temp = NULL;
}

DoublyLinkedList::~DoublyLinkedList() {
    node* current = start;
    node* temp = NULL;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
}
void DoublyLinkedList::print() {
    node* current = start;
    while(current != NULL) {
        printf("->%d", current->data);
        current = current->next;
    }
    printf("->\n");
}
node* DoublyLinkedList::insert_ascending(int item) {
    node* newNode = (node*)malloc(sizeof(node));
    if(start == NULL){
        newNode->data = item;
        newNode->next = NULL;
        newNode->back = NULL;
        start = newNode;
    }
    else if (start->data > item) { 
        newNode->data = item;
        newNode->next = start; 
        newNode->next->back = newNode; 
        start = newNode; 
    }
    else {
        node* current = start; 
        while (current->next != NULL && current->next->data < item)
        {
            current = current->next;
        }
        newNode->data = item;
        newNode->next = current->next;
        if(current->next != NULL && (current->next->data == item || current->data == item)){
            return start;
        } 

        if (current->next != NULL) 
            newNode->next->back = newNode; 
  
        current->next = newNode; 
        newNode->back = current; 
    }
    return start;
}


int main() {
    DoublyLinkedList A;

    A.insert_ascending(0);
    A.insert_ascending(1);
    A.insert_ascending(1);
    A.insert_ascending(2);
    A.insert_ascending(0);
    A.insert_ascending(1);
    A.insert_ascending(0);
    A.insert_ascending(3);
    A.insert_ascending(5);
    
    A.print();

    return 0;
}
