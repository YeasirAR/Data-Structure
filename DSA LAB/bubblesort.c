#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a; // dereferencing a pointer
    *a = *b;
    *b = temp;
}

void bubblesort(int A[], int n)
{
    for(int i=0; i< n-1; i++)
    {
        for(int j=1; j<n-i; j++)
        {
            if(A[j-1] > A[j])
            {
                swap(&A[j-1], &A[j]);
            }
        }
    }
}

void selectionsort(int A[], int n)
{
    /*complete this function*/
}

void printarr(int A[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {4, 7, 1, 5, 2};
    int n = 5;

    printarr(arr, n);

    bubblesort(arr, n);

    printarr(arr, n);

    return 0;
}
