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
    bool insert_after(int newVal, int oldVal);
    bool delete_first();
    bool delete_last();
    bool delete_all();
    bool delete_after(int item);
    int calculate_length();

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
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
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
bool SinglyLinkedList::insert_after(int newVal, int oldVal) {
 
    LN* current = head;
    while( current != NULL && current->data != oldVal) {
        current = current->next;
    }
    if(current== NULL){
        return false;
    }
    else{
        LN* newNode = (LN*)malloc(sizeof(LN));
        newNode->data = newVal;
        newNode->next=current->next;
        current->next = newNode;
        return true;
    }
}
bool SinglyLinkedList::delete_first(){
    while(head !=NULL){
        if(head->next == NULL){
            free(head);
            return true;
        }
        LN* current = head;
        current = head;
        head = head-> next;
        free(current);
        current = current->next;
    }
    return true;
}
int SinglyLinkedList::calculate_length(){
    LN* current = head;
    int count = 0;
    while( current != NULL ) {
        count++;
        current = current->next;
    }
    return count;
    
}
bool SinglyLinkedList::delete_all(){
    while(head !=NULL){
        LN* current = head;
        current = head;
        head = head-> next;
        free(current);
        current = current->next;
    }
    return true;
}
 
int main() {
    SinglyLinkedList A;
    A.insert_last(10);
    A.insert_last(20);
    A.insert_last(30);
    A.insert_last(40);
    A.insert_last(50);
    A.insert_last(60);
    A.insert_last(70);
    A.print();
    printf("%d\n",A.calculate_length());
    A.delete_all();
    A.print();



    // A.insert_after(35,30);
    // A.print();
    // A.insert_after(55,50);

    // A.print();
    // A.delete_first();
    // A.print();
    // A.delete_first();
    // A.print();
    // A.delete_first();
    // A.print();
    // A.delete_first();
    // A.print();
    // A.delete_first();
    // A.print();
    // A.delete_first();
    // A.print();
    // A.delete_first();
    // A.print();
    // A.delete_first();
    // A.print();
    // A.delete_first();
    // A.print();

 
    return 0;
}