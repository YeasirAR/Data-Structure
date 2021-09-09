#include <stdio.h>
#include <stdlib.h>

class Stack {
    int* A;
    int MAXSIZE;
    int top;

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
    MAXSIZE = 2;
    A = (int*)malloc(MAXSIZE*sizeof(int));
    top = 0;
}

Stack::~Stack() {
    free(A);
}

void Stack::print() {
    for(int i=0; i<top; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

bool Stack::push(int item) {
    if(top == MAXSIZE) {
        int* temp = (int*)malloc(2*MAXSIZE*sizeof(int));
        printf("Copying...\n");
        for(int i=0; i<MAXSIZE; i++)
            temp[i] = A[i];
        free(A);
        A = temp;
        MAXSIZE = 2*MAXSIZE;
    }
    A[top] = item;
    top++;
    return true;
}

bool Stack::pop(int& retval) {
    if(top > 0) {
        retval = A[top-1];
        top--;
        return true;
    }
    else
        return false;
}

bool Stack::peek(int& retval) {
    if(top > 0) {
        retval = A[top-1];
        return true;
    }
    else
        return false;
}

bool Stack::is_empty() {
    if(top == 0)
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