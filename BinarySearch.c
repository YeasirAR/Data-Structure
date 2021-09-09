#include <stdio.h>

int BinarySearch(int A[], int n, int key)
{
    int start = 0;
    int end = n-1;
    while ( start <=end){
        int mid = (start+end)/2;
        if(A[mid] == key){
            return mid;
        }
        else if(A[mid]>key){ // Search LEFT
            end = mid-1;
        }
        else{     //A[mid]<key  Search RIGHT
            start = mid+1;
        }
    }
    printf("Not Found");
    return -1;
}

int main()
{
    int arr[] = {3, 5, 6, 8, 12, 15, 20};
    int n = 7;

    int ans = BinarySearch(arr, n, 15);
    if (ans != -1)
    {
        printf("Found in index %d", ans);
    }

    return 0;
}
