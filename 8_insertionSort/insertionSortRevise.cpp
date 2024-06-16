#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

void insertionSort(int *A, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        
        {  //khiska rahe hai j element ko aage agar woh key sey bada hua
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }

    // its working
    // for (let i = 1; i < A.length; i++)
    // {
    //     // Step 1: Store the value at the current index i in a variable named key.
    //     key = A[i];

    //     // Step 2: Initialize a variable j to the index just before the current index i.
    //     j = i - 1;

    //     // The following loop compares the key with the elements before it and moves
    //     // elements to the right until the correct position for the key is found.
    //     while (j >= 0 && A[j] > key)
    //     {
    //         // Move the element at index j to the right.
    //         A[j + 1] = A[j];

    //         // Move one position to the left in the array.
    //         j--;
    //     }

    //     // Place the key in its correct position.
    //     A[j + 1] = key;
    // }
}

int main()
{

    int A[] = {23, 45, 67, 22, 35, 14};
    int n = 6;
    printArray(A, n); // Array before the insertion sort Algorithm
    cout << "Array after the insertion sorting" << endl;
    insertionSort(A, n);
    printArray(A, n);

    return 0;
}