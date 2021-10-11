#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    LN* current = head;
    LN* temp = NULL;
    while (current != NULL){
        temp = current->next;
        free(current);
        current = temp;
    }
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

int postfix_evaluator(char str[]) {
    int len = strlen(str);
    Stack S;
    int A,B;


    for(int i=0; i<len; i++) {
        char c = str[i];

        if('0'<=c && c<='9') {
            // write your code here
            S.push(c-48);
        }
        else if(c == '+') {
            // write your code here
            S.pop(A);
            S.pop(B);
            S.push(B+A);
        }
        else if(c == '-') {
            // write your code here
            S.pop(A);
            S.pop(B);
            S.push(B-A);
        }
        else if(c == '*') {
            // write your code here
            S.pop(A);
            S.pop(B);
            S.push(B*A);
        }
        else if(c == '/') {
            // write your code here
            S.pop(A);
            S.pop(B);
            S.push(B/A);
        }
    }
    int res;
    S.peek(res);
    return res;
}

int main() {

    char str[] = "123*+4-5+23*-";
    int x = postfix_evaluator(str);
    printf("%d\n", x);

    return 0;
}
