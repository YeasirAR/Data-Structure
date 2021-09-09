#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int A[], int n)
{
    int i,j,max,index;
    for(i=1; i<=n-1; i++)
    {
        max = -99999;
        for(j=0; j<=n-i; j++)
        {
            if(A[j] > max)
            {
                max = A[j];
                index = j;
            }
        }
        swap(&A[index], &A[n-i]);
    }
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
    selectionsort(arr, n);
    printarr(arr, n);
    return 0;
}
