#include <stdio.h>
#include <stdlib.h>

#define INF 99999

void printarr(int A[], int n);
void mergesort(int A[], int p, int r);
void merge(int A[], int p, int q, int r);

int main()
{
    int arr[] = {23, 5, 11, 17, 74, 33, 61, 7, 21};
    int n = 9;
    printarr(arr, n);
    mergesort(arr, 0, n - 1);
    printarr(arr, n);
    return 0;
}

void printarr(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void mergesort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = (int *)malloc((n1 + 1) * sizeof(int));
    int *R = (int *)malloc((n2 + 1) * sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q + j + 1];
    }
    L[n1] = INF;
    R[n2] = INF;
    int i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] < R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
    free(L);
    free(R);
}
