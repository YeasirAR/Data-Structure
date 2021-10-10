#include <stdio.h>
#include <stdlib.h>

class Stack {
    int* A;
    int MAXSIZE;
    int top;

public:
    Stack(int maxsize);
    ~Stack();
    void print();
    bool push(int item);
    bool pop(int& retval);
    bool peek(int& retval);
    bool is_empty();
};

Stack::Stack(int maxsize) {
    A = (int*)malloc(maxsize*sizeof(int));
    MAXSIZE = maxsize;
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
    if(top<MAXSIZE) {
        A[top] = item;
        top++;
        return true;
    }
    else {
        return false;
    }
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

    Stack S(10);

    S.push(14);
    S.push(9);
    S.push(12);
    S.push(23);

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






