#include <stdio.h>
#include <stdlib.h>

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

class MaxHeap {
    int A[100];
    int heapsize;

public:
    MaxHeap();
    MaxHeap(int arr[], int len);
    ~MaxHeap();
    void print();
    void maxHeapify(int i);
    void buildHeap(int arr[], int len);
    int extractMax();
    int maximum();
    void insert(int key);
    void increaseKey(int oldkeyindex, int newkey);
    int heapsort(int arr2[]);
};

MaxHeap::MaxHeap() {
    heapsize = 0;
}

MaxHeap::MaxHeap(int arr[], int len) {
    buildHeap(arr, len);
}

MaxHeap::~MaxHeap() {
    // will write later
}

void MaxHeap::print() {
    for(int i=1; i<=heapsize; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void MaxHeap::maxHeapify(int i) {
    int l = 2*i;
    int r = 2*i+1;
    int largest = i;
    if(l<=heapsize && A[l]>A[i])
        largest = l;
    if(r<=heapsize && A[r]>A[largest])
        largest = r;
    if(largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

void MaxHeap::buildHeap(int arr[], int len) {
    for(int i=0; i<len; i++)
        A[i+1] = arr[i];
    heapsize = len;
    for(int i=len/2; i>0; i--)
        maxHeapify(i);
}

int MaxHeap::maximum() {
    return A[1];
}

int MaxHeap::extractMax() {
    if(heapsize < 1) {
        printf("Heap underflow\n");
        return -1;
    }
    int temp = A[1];
    A[1] = A[heapsize];
    heapsize--;
    maxHeapify(1);
    return temp;
}

int MaxHeap::heapsort(int arr2[]) {
    int len = heapsize;
    for(int i=len; i>=1; i--)
        arr2[i-1] = extractMax();
    return len;
}

void MaxHeap::increaseKey(int oldkeyindex, int newkey) {
    if(newkey < A[oldkeyindex]) {
        printf("new key is smaller than oldkey\n");
        return;
    }
    A[oldkeyindex] = newkey;
    while(oldkeyindex>1 && A[oldkeyindex/2]<A[oldkeyindex]) {
        swap(A[oldkeyindex/2], A[oldkeyindex]);
        oldkeyindex = oldkeyindex/2;
    }
}

void MaxHeap::insert(int key) {
    heapsize++;
    A[heapsize] = -99999;
    increaseKey(heapsize, key);
}

int main() {

    int arr[] = {15, 52, 11, 19, 17, 32, 15, 23, 42, 33};
    int len = sizeof(arr)/sizeof(int);
    int arr2[100];


    MaxHeap H(arr, len);
    H.print();

//    int len2 = H.heapsort(arr2);
//    for(int i=0; i<len2; i++)
//        printf("%d ", arr2[i]);
//    printf("\n");
//
//    H.print();


    int x;
    x = H.extractMax();
    printf("%d\n", x);

    x = H.extractMax();
    printf("%d\n", x);

    H.print();

    H.insert(29);
    H.print();

    return 0;
}
