#include <stdio.h>
#include <stdlib.h>

class Arraylist {
    int* A;
    int MAXSIZE;
    int len;
    bool move_forward(int start, int by);
    bool move_backward(int start, int by); //complete this method

    public:
    Arraylist(int maxsize);
    ~Arraylist();
    int get_length();
    bool is_full();
    bool is_empty();
    void print();
    bool add(int val);
    bool get_by_index(int index, int& retval);
    bool search_index(int key, int& index);
    bool change(int index, int newval);
    bool insert_at_index(int index, int val);

    bool remove_at_index(int index); //complete this method
    bool remove_item_first(int item); //complete this method
    bool search_index_backward(int key, int& index); //complete this method
    bool remove_item_last(int item); //complete this method
    bool remove_item_all(int item); //complete this method
    bool replace(int oldval, int newval); //complete this method
    void clear(); //complete this method
    bool remove_index_range(int from, int to); //complete this method
};

Arraylist::Arraylist(int maxsize) {
    A = (int*)malloc(maxsize*sizeof(int));
    MAXSIZE = maxsize;
    len = 0;
}

Arraylist::~Arraylist() {
    free(A);
}

int Arraylist::get_length() {
    return len;
}

bool Arraylist::is_empty() {
    if(len == 0)
        return true;
    else
        return false;
}

bool Arraylist::is_full() {
    if(len == MAXSIZE)
        return true;
    else
        return false;
}

void Arraylist::print() {
    printf("Arraylist: ");
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

bool Arraylist::get_by_index(int index, int& retval) {
    if(index<0 || index>=len)
        return false;
    else {
        retval = A[index];
        return true;
    }
}

bool Arraylist::search_index(int key, int& index) {
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
    if(by<=0 || len+by > MAXSIZE) {
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

bool Arraylist::insert_at_index(int index, int val) {
    if(index>=0 && index<=len && move_forward(index, 1)) {
        A[index] = val;
        return true;
    }
    else
        return false;
}

bool Arraylist::move_backward(int start, int by) {
    if (by<=0 || start-by<0)
        return false;
    else{
        for (int i=start; i<=len-1; i++)
            A[i-by]=A[i];
        len-=by;
        return true;
    }
}

bool Arraylist::remove_at_index(int index) {
    if (index>=0 && index<len && move_backward(index+1,1))
        return true;
    else
        return false;
}

bool Arraylist::remove_item_first(int item) {
    int index;
    if (search_index(item,index)){
        remove_at_index(index);
        return true;
    }
    else
        return false;
}

bool Arraylist::search_index_backward(int key, int& index) {
    for (int i=len-1; i>=0; i--){
        if (A[i]==key){
            index=i;
            return true;
        }
    }
    return false;
}

bool Arraylist::remove_item_last(int item) {
    int index;
    if(search_index_backward(item,index)){
        remove_at_index(index);
        return true;
    }
    else
        return false;
}

bool Arraylist::remove_item_all(int item) {
    int index;
    bool flag=false;
    while(search_index(item, index)){
        remove_at_index(index);
        flag = true;
    }
    return flag;
}

bool Arraylist::replace(int oldval, int newval) {
    bool flag=false;
    for(int i=0; i<=len-1; i++){
        if (A[i]==oldval){
            A[i]=newval;
            flag=true;
        }
    }
    return flag;
}

void Arraylist::clear() {
    len=0;
}

bool Arraylist::remove_index_range(int from, int to) {
    if(from>=0 && from<=to && to<len){
        move_backward(to+1, to-from+1);
        return true;
    }
    else
        return false;
}

int main() {
    Arraylist A(10);
    A.add(5);
    A.add(10);
    A.add(20);
    A.add(30);
    A.add(40);
    A.add(50);
    A.add(60);
    A.add(70);
    A.print();

    int x;
    if(A.get_by_index(5, x)) {
        printf("At index %d: %d\n", 5, x);
    }
    else {
        printf("Index out of bound\n");
    }

    if(A.search_index(40, x)) {
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

    A.insert_at_index(7, 25);
    A.print();

    A.remove_at_index(2);
    A.print();
    A.remove_at_index(-1);
    A.print();

    A.remove_item_first(140);
    A.print();
    A.remove_item_first(40);
    A.print();

    if(A.search_index_backward(50, x))
        printf("index: %d\n", x);
    if(A.search_index_backward(55, x))
        printf("index: %d\n", x);
    if(A.search_index_backward(70, x))
        printf("index: %d\n", x);

    A.remove_item_last(25);
    A.print();
    A.remove_item_last(15);
    A.print();

    A.remove_item_all(60);
    A.print();
    A.remove_item_all(65);
    A.print();

    A.replace(30, 40);
    A.print();
    A.replace(35, 45);
    A.print();
    A.replace(40, 60);
    A.print();
    
    A.clear();
    A.print();

    A.add(10);
    A.add(20);
    A.add(30);
    A.add(40);
    A.add(50);
    A.add(60);
    A.add(70);
    A.add(80);

    A.remove_index_range(-1, 3);
    A.print();
    A.remove_index_range(1, -3);
    A.print();
    A.remove_index_range(1, 3);
    A.print();
    A.remove_index_range(0, 10);
    A.print();
    A.remove_index_range(3, 2);
    A.print();
    A.remove_index_range(0, 4);
    A.print();
    
    return 0;
}
