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
    ~SinglyLinkedList(); // complete this method
    bool is_empty();
    void print();
    bool insert_first(int item);
    bool insert_last(int item);
    bool insert_after(int oldval, int newval);
    bool insert_before(int oldval, int newval); // complete this method
    bool remove_first();
    bool remove_last(); // complete this method
    bool remove_item(int item); // complete this method
    bool remove_after(int item); // complete this method
    bool remove_before(int item); // complete this method
    bool remove_alternate(); // complete this method
    bool remove_highest(); // complete this method
};

SinglyLinkedList::SinglyLinkedList() {
    head = NULL;
}

SinglyLinkedList::~SinglyLinkedList() {
    // completed
    LN* current = head;
    LN* temp = NULL;
    while (current != NULL){
        temp = current->next;
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

bool SinglyLinkedList::insert_last(int item) {
    if(head == NULL)
        return insert_first(item);
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

bool SinglyLinkedList::insert_after(int oldval, int newval) {
    LN* current = head;
    while(current != NULL) {
        if(current->data == oldval)
            break;
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

bool SinglyLinkedList::insert_before(int oldval, int newval) {
    // completed
    LN* current = head;
    LN* prev = NULL;
    while(current != NULL){
        if(current->data == oldval)
            break;
        prev = current;
        current = current->next;
    }
    if(current == NULL)
        return false;
    if(current == head)
        return insert_first(newval);
    LN* newNode = (LN*)malloc(sizeof(LN));
    newNode->data = newval;
    newNode->next = current;
    prev->next = newNode;
    return true;
}

bool SinglyLinkedList::remove_first() {
    if(head == NULL)
        return false;
    else {
        LN* current = head;
        head = head->next;
        free(current);
        return true;
    }
}

bool SinglyLinkedList::remove_last() {
    // completed
    if(head == NULL)
        return false;
    if(head->next == NULL)
        return remove_first();
    LN* current = head;
    LN* prev = NULL;
    while(current->next != NULL){
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
    return true;
}

bool SinglyLinkedList::remove_item(int item) {
    // completed
    LN* current = head;
    LN* prev = NULL;
    while ( current != NULL){
        if(current->data == item)
            break;
        prev = current;
        current = current->next;
    }
    if(current==NULL)
        return false;
    if(current == head)
        return remove_first();
    prev->next = current->next;
    free(current);
    return true;
}

bool SinglyLinkedList::remove_after(int item) {
    // completed
    LN* current = head;
    while(current != NULL){
        if(current->data == item)
            break;
        current = current->next;
    }
    if(current == NULL)
        return false;
    if(current->next == NULL)
        return false;
    LN* temp = current->next;
    current->next = temp->next;
    free(temp);
    return true;
}

bool SinglyLinkedList::remove_before(int item) {
    // completed
    LN* current = head;
    LN* prev = NULL;
    LN* prevprev = NULL;
    while( current != NULL){
        if(current->data == item)
            break;
        prevprev = prev;
        prev = current;
        current = current->next;
    }
    if(current == NULL)
        return false;
    if(current == head)
        return false;
    if(prev == head)
        return remove_first();
    prevprev->next = current;
    free(prev);
    return true;
}

bool SinglyLinkedList::remove_alternate() {
    LN* previous = head;
    LN* current = head->next;
    if(head == NULL){
        return false;
    }
    if(head->next == NULL){
        return false;
    }
    while(current != NULL){
        previous->next = current->next;
        free(current);
        previous = previous->next;
        if(previous != NULL){
            current = previous->next;
        }
        else{
            return true;
        }
    }
    return true;
}

bool SinglyLinkedList::remove_highest() {
    int maximum = -9999;
    LN* current = head;
    while (current != NULL) {
        if (maximum < current->data)
            maximum = current->data;
        current = current->next;
    }
    if (head == NULL)
        return false;
    return remove_item(maximum);
}
//     // completed
//     if(head == NULL)
//         return false;
//     if(head->next == NULL)
//         return remove_first();
//     LN* current = head;
//     int maximum = current->data;
//     while (current != NULL){
//         current = current->next;
//         if(current != NULL && maximum < current->data){
//             maximum = current->data;
//         }
//     }
//     return remove_item(maximum);
    
// }

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
    printf("\n");

    //insert before 
    A.insert_before(20,15);
    A.print();
    A.insert_before(10,5); 
    A.print();
    A.insert_before(45,50); 
    A.print();
    printf("\n");

    // remove last
    A.remove_last();
    A.print();
    A.remove_last();
    A.print();
    A.remove_last();
    A.print();
    A.remove_last();
    A.print();
    A.remove_last();
    A.print(); 
    A.remove_last(); 
    A.print(); //Empty LinkedList

    // Adding some value to LinkedList
    A.insert_last(10);
    A.insert_last(20);
    A.insert_last(30);
    A.insert_last(40);
    A.insert_last(50);
    A.insert_last(60);
    A.insert_last(70);
    A.insert_last(80);
    A.print();
    printf("\n");

    // remove item
    A.remove_item(10);
    A.print();
    A.remove_item(60);
    A.print();
    A.remove_item(15);
    A.print();
    printf("\n");
    

    // remove after
    A.remove_after(40);
    A.print();
    A.remove_after(45);
    A.print();
    A.remove_after(80);
    A.print();
    printf("\n");

    // remove before
    A.remove_before(40);
    A.print();
    A.remove_before(50);
    A.print();
    A.remove_before(10);
    A.print();
    printf("\n");

    // Adding some value to LinkedList
    A.insert_last(30);
    A.insert_last(10);
    A.insert_last(50);
    A.print();
    printf("\n");

    //remove alternate
    A.remove_alternate(); // returns true
    A.print();
    A.remove_alternate(); // returns true
    A.print();
    A.remove_alternate(); // returns true
    A.print();
    A.remove_alternate(); // returns false because only one item left
    A.print();
    A.remove_first();     // making the list empty 
    A.print();
    A.remove_alternate(); // returns false because of empty list
    A.print();
    printf("\n");


    // Adding some value to LinkedList
    A.insert_last(30);
    A.insert_last(10);
    A.insert_last(50);
    A.insert_last(70);
    A.insert_last(90);
    A.insert_last(20);
    A.insert_last(30);
    A.insert_last(60);
    A.insert_last(80);
    A.print();
    printf("\n");



    // remove highest
    A.remove_highest(); // returns true
    A.print();
    A.remove_highest(); // returns true
    A.print();
    // remove some item so that I can test the corner cases 
    A.remove_last();
    A.remove_last();
    A.remove_last();
    A.remove_last();
    A.remove_last();
    A.remove_last();
    A.print(); // only one item available at the list

    A.remove_highest(); // returns true
    A.print();
    A.remove_highest(); //returns false here ! Empty list
    A.print();
    

    return 0;
}
