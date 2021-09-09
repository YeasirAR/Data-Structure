#include <stdio.h>

int LinearSearch(int A[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            return i;
        }
    }
    printf("Not Found");
    return -1;
}

int main()
{
    int arr[] = {4, 7, 1, 5, 2};
    int n = 5;

    int ans = LinearSearch(arr, n, 1);
    if (ans != -1)
    {
        printf("Found in index %d", ans);
    }

    return 0;
}
