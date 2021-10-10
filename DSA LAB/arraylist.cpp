#include <stdio.h>
#include <stdlib.h>

class Arraylist {
    int* A;
    int MAXSIZE;
    int len;
    bool move_forward(int start, int by);

    // no return type for constructors, name of the constructor will be name of the class
    // and constructors need to be declared public
    public:
    Arraylist(int maxsize);
    ~Arraylist();
    int getlength();
    bool empty();
    void print();
    bool add(int val);
    bool getbyindex(int index, int& retval);
    bool searchindex(int key, int& index);
    bool change(int index, int newval);
    bool insertatindex(int index, int val);
};

Arraylist::Arraylist(int maxsize) {
    A = (int*)malloc(maxsize*sizeof(int));
    MAXSIZE = maxsize;
    len = 0;
}

Arraylist::~Arraylist() {
    free(A);
}

void Arraylist::print() {
    for(int i=0; i<len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

bool Arraylist::add(int val) {
    if(len<MAXSIZE) {
        A[len] = val;
        len++;
        return true;
    }
    else {
        return false;
    }
}

bool Arraylist::getbyindex(int index, int& retval) {
    if(index<0 || index>=len)
        return false;
    else {
        retval = A[index];
        return true;
    }
}

bool Arraylist::searchindex(int key, int& index) {
    for(int i=0; i<len; i++) {
        if(A[i] == key) {
            index = i;
            return true;
        }
    }
    return false;
}

bool Arraylist::change(int index, int newval) {
    if(index<0 || index>=len)
        return false;
    else {
        A[index] = newval;
        return true;
    }
}

bool Arraylist::move_forward(int start, int by) {
    if(by <= 0 || len+by > MAXSIZE) {
        return false;
    }
    else {
        for(int i=len-1; i>=start; i--) {
            A[i+by] = A[i];
        }
        len = len+by;
        return true;
    }
}

bool Arraylist::insertatindex(int index, int val) {
    if(index>0 && index<=len && move_forward(index, 1)) {
        A[index] = val;
        return true;
    }
    else
        return false;
}

int main() {
    Arraylist A(8);
    A.add(5);
    A.add(10);
    A.add(20);
    A.add(30);
    A.add(40);
    A.add(50);
    A.add(60);
    A.print();

    int x;
    if(A.getbyindex(5, x)) {
        printf("At index %d: %d\n", 5, x);
    }
    else {
        printf("Index out of bound\n");
    }

    if(A.searchindex(40, x)) {
        printf("Index of %d: %d\n", 40, x);
    }
    else {
        printf("Not found\n");
    }

    if(A.change(x, 140)) {
        printf("New value of index %d: %d\n", x, 140);
    }
    else {
        printf("Index out of bound\n");
    }
    A.print();

    A.insertatindex(7, 25);
    A.print();

    return 0;
}
