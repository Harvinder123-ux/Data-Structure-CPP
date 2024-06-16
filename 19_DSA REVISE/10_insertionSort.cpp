#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void insertionSort(int *A, int n)
{
    int key;
    int j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && key < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{

    int A[] = {3, 55, 26, 2, 8, 9};
    int n = 6;
    printArray(A, n);
    cout << "Array after the insertion Sort"<<endl;
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}