#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct ListNode {
    int data;
    struct ListNode* next;
};

typedef struct ListNode LN;

class Stack {
    LN* head;

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
    head = NULL;
}

Stack::~Stack() {
    // write your code here
}

void Stack::print() {
    LN* current = head;
    while(current != NULL) {
        printf("->%d", current->data);
        current = current->next;
    }
    printf("->\n");
}

bool Stack::push(int item) {
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

bool Stack::pop(int& retval) {
    if(head == NULL)
        return false;
    else {
        retval = head->data;
        LN* current = head;
        head = head->next;
        free(current);
        return true;
    }
}

bool Stack::peek(int& retval) {
    if(head == NULL)
        return false;
    else {
        retval = head->data;
        return true;
    }
}

bool Stack::is_empty() {
    if(head == NULL)
        return true;
    else
        return false;
}

int main() {

    Stack S;

    S.push(14);
    S.print();
    S.push(9);
    S.print();
    S.push(12);
    S.print();
    S.push(23);
    S.print();
    S.push(54);
    S.print();


    int x;
    S.pop(x);
    printf("%d\n", x);
    S.pop(x);
    printf("%d\n", x);
    S.pop(x);
    printf("%d\n", x);
    S.pop(x);
    printf("%d\n", x);

    return 0;
}
