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
    ~DoublyLinkedList(); // complete this method
    bool is_empty();
    void forward_print();
    void backward_print();
    void print();
    bool insert_first(int item);
    bool insert_last(int item);
    bool insert_after(int oldval, int newval);
    bool insert_before(int oldval, int newval);
    bool remove_first();
    bool remove_last();
    LN* search(int key); // complete this method
    bool remove_item(int item); // complete this method
    bool remove_after(int item); // complete this method
    bool remove_before(int item); // complete this method
    bool remove_alternate(); // complete this method
    bool remove_highest(); // complete this method
    int length();
    double sum();
    bool reverse_linkedlist();
};

DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList() {
    LN* current = head;
    LN* temp = NULL;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    
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
    // from insert_first using symmetric property
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

// bool DoublyLinkedList::insert_after(int oldval, int newval) {
//     LN* current = head;
//     while(current != NULL) {
//         if(current->data == oldval)
//             break;
//         current = current->next;
//     }
//     if(current == NULL)
//         return false;
//     LN* X = current;
//     LN* Y = X->next;
//     LN* Z = (LN*)malloc(sizeof(LN));
//     if(Z == NULL)
//         return false;
//     Z->data = newval;
//     Z->prev = X;
//     Z->next = Y;
//     X->next = Z;
//     if(Y == NULL)
//         tail = Z;
//     else
//         Y->prev = Z;
//     return true;
// }


bool DoublyLinkedList::insert_after(int oldval, int newval) {
    LN* X = search(oldval);
    if(X == NULL)
        return false;
    LN* Y = X->next;
    LN* Z = (LN*)malloc(sizeof(LN));
    if(Z == NULL)
        return false;
    Z->data = newval;
    Z->prev = X;
    Z->next = Y;
    X->next = Z;
    if(Y == NULL)
        tail = Z;
    else
        Y->prev = Z;
    return true;
}

// bool DoublyLinkedList::insert_before(int oldval, int newval) {
//     // from insert_after using symmetric property
//     LN* current = tail;
//     while(current != NULL) {
//         if(current->data == oldval)
//             break;
//         current = current->prev;
//     }
//     if(current == NULL)
//         return false;
//     LN* X = current;
//     LN* Y = X->prev;
//     LN* Z = (LN*)malloc(sizeof(LN));
//     if(Z == NULL)
//         return false;
//     Z->data = newval;
//     Z->next = X;
//     Z->prev = Y;
//     X->prev = Z;
//     if(Y == NULL)
//         head = Z;
//     else
//         Y->next = Z;
//     return true;
// }


bool DoublyLinkedList::insert_before(int oldval, int newval) {
    LN* X = search(oldval);
    if(X == NULL)
        return false;
    LN* Y = X->prev;
    LN* Z = (LN*)malloc(sizeof(LN));
    if(Z == NULL)
        return false;
    Z->data = newval;
    Z->next = X;
    Z->prev = Y;
    X->prev = Z;
    if(Y == NULL)
        head = Z;
    else
        Y->next = Z;
    return true;
}

bool DoublyLinkedList::remove_first() {
    if(head == NULL)
        return false;
    LN* current = head;
    head = head->next;
    if(head == NULL)
        tail = NULL;
    else
        head->prev = NULL;
    free(current);
    return true;
}

bool DoublyLinkedList::remove_last() {
    // from remove_first using symmetric property
    if(tail == NULL)
        return false;
    LN* current = tail;
    tail = tail->prev;
    if(tail == NULL)
        head = NULL;
    else
        tail->next = NULL;
    free(current);
    return true;
}

LN* DoublyLinkedList::search(int key) {
    LN* current = head;
    while(current != NULL){
        if(current->data == key){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

bool DoublyLinkedList::remove_item(int item) {
    LN* Z = search(item);
    if(Z == NULL)
        return false;
    LN* X = Z->prev;
    LN* Y = Z->next;
    if(X == NULL)
        head = Y;
    else
        X->next = Y;
    if(Y == NULL)
        tail = X;
    else
        Y->prev = X;
    free(Z);
    return true;
}

bool DoublyLinkedList::remove_after(int item) {
    LN* X = search(item);
    if(X == NULL)
        return false;
    if(X->next == NULL)
        return false;
    LN* Z = X->next;
    LN* Y = Z->next;
    X->next = Y;
    if(Y == NULL)
        tail = X;
    else
        Y->prev = X;
    free(Z);
    return true;
}

bool DoublyLinkedList::remove_before(int item) {
    LN* X = search(item);
    if(X == NULL)
        return false;
    if(X->prev == NULL)
        return false;
    LN* Z = X->prev;
    LN* Y = Z->prev;
    X->prev = Y;
    if(Y == NULL)
        head = X;
    else
        Y->next = X;
    free(Z);
    return true;
}

bool DoublyLinkedList::remove_alternate() {
    if(head == NULL)
        return false;
    if(head->next == NULL)
        return false;
    LN* X;
    LN* Y;
    LN* current = head->next;
    while(current != NULL){
        X = current->prev;
        Y = current->next;
        free(current);
        X->next = Y;
        if(Y == NULL){
            tail = X;
            break;
        }
        else
            Y->prev = X;
        current = Y->next;
    }
    return true;
}

bool DoublyLinkedList::remove_highest() {
    if(head == NULL)
        return false;
    if(head->next == NULL)
        return remove_first();
    LN* current = head;
    int maximum = current->data;
    while (current != NULL){
        current = current->next;
        if(current != NULL && maximum < current->data){
            maximum = current->data;
        }
    }
    return remove_item(maximum);
}

int DoublyLinkedList::length() {
    int count = 0;
    LN* current = head;
    while(current != NULL){
        current = current->next;
        count++;
    }
    return count;
}
double DoublyLinkedList::sum() {
    int sum = 0;
    LN* current = head;
    while(current != NULL){
        sum += current->data;
        current = current->next;
    }
    return sum;
}
bool DoublyLinkedList::reverse_linkedlist() {
    LN* prev;
    LN* current;
    if(head != NULL){
        prev = head;
        current = head->next;
        head = head->next;
        prev->next = NULL;
        while (head != NULL){
            head = head->next;
            current->next = prev;
            prev = current;
            current = head;
        }
        head = prev;
        printf("Successfully Reversed\n");
    }
    return true;
}

int main() {
    DoublyLinkedList A;

    A.print();

    A.insert_last(10);
    A.insert_last(20);
    A.insert_last(30);
    A.insert_last(40);
    A.print();

    A.reverse_linkedlist();
    A.print();

    // A.insert_before(20, 25);
    // A.print();

    // A.insert_before(35, 45);
    // A.print();

    // A.insert_before(10, 45);
    // A.print();
    // printf("\n");

    // // Test case for Search
    // if(A.search(30) != NULL)
    //     printf("Search Successful\n");
    // else
    //     printf("Returns NULL\n");
    // if(A.search(35) != NULL)
    //     printf("Search Successful\n");
    // else
    //     printf("Returns NULL\n");
    // printf("\n");

    // // remove item 
    // A.remove_item(10);
    // A.print();
    // A.remove_item(50);
    // A.print();
    // A.remove_item(45);
    // A.print();
    // A.remove_item(40);
    // A.print();
    // printf("\n");

    // A.insert_last(55);

    // // remove after
    // A.remove_after(20);
    // A.print();
    // A.remove_after(60);
    // A.print();
    // A.remove_after(55);
    // A.print();
    // A.remove_after(20);
    // A.print();
    // printf("\n");

    // // insert some data
    // A.insert_last(10);
    // A.insert_last(15);
    // A.print();
    // printf("\n");

    // // remove before
    // A.remove_before(10);
    // A.print();
    // A.remove_before(18);
    // A.print();
    // A.remove_before(25);
    // A.print();
    // A.remove_before(10);
    // A.print();
    // printf("\n");

    // //insert some data
    // A.insert_last(20);
    // A.insert_last(30);
    // A.insert_last(40);
    // A.insert_last(50);
    // A.insert_last(60);
    // A.print();
    // printf("\n");

    // // remove alternate
    // A.remove_alternate();   // returns true
    // A.print();
    // A.remove_alternate();   // returns true
    // A.print();
    // A.remove_alternate();   // returns false , only one item
    // A.print();
    // A.remove_first();       // making the list empty to check another corner case
    // A.print(); 
    // A.remove_alternate();   // returns false , empty list
    // A.print(); 
    // printf("\n");

    // // insert some data 
    // A.insert_last(60);
    // A.insert_last(75);
    // A.insert_last(30);
    // A.print();
    // printf("\n");

    // // remove highest
    // A.remove_highest();   // returns true
    // A.print();
    // A.remove_highest();   // returns true
    // A.print();
    // A.remove_highest();   // returns true
    // A.print();
    // A.remove_highest();   // returns false , empty list
    // A.print();


    return 0;
}
