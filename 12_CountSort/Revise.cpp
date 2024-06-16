#include <iostream>
#include <limits.h>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << A[i] << " ";
    }
    cout << endl;
}
int maximum(int *A, int n)
{
    int max = INT_MIN; // Initialize max to the smallest possible integer value
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i]; // Update max if the current element is greater
        }
    }
    return max; // Return the maximum value found
}

void countSort(int *A, int n)
{
    int max = maximum(A, n);
    int *count = new int[max + 1];
    int i, j;

    for (i = 0; i < n; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    { // A hogi hamar Array ki value or i hogi hamare count ki index jahapar woh increment hoga
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0;
    j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{

    int A[] = {23, 15, 67, 43, 33, 87, 6, 9};
    int n = 8;

    printArray(A, n); // array befor the sort
    cout << "Array after the count sorting" << endl;
    countSort(A, n);
    printArray(A, n); // array after the sorting

    return 0;
}
