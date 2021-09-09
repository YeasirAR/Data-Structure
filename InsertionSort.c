#include <stdio.h>
 
void insertionsort(int A[], int n) {
    int i,j,key;
    for(i=1; i<=n-1; i++) {
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key) {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=key;
    }
}
 
void printarr(int A[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
 
int main() {
    int arr[] = {4, 7, 1, 5, 2};
    int n = 5;
 
    printarr(arr, n);
 
    insertionsort(arr, n);
 
    printarr(arr, n);
 
    return 0;
}
 


