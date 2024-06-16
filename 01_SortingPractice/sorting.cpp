#include <iostream>
#include <limits.h>
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
// void bubbleSort(int*A, int n){
//     int temp;
//     for (int i = 0; i < n-1; i++)
//     {
//         for (int j= 0; j < n-1-i; j++)
//         {   //agar Array ka first element bda hai 2nd element se
//             if(A[j]>A[j+1]){
//             temp = A[j]; //toh first element ki value store kro temporary variable mein and
//             A[j] = A[j+1];// usko ek kadam age le jao
//             A[j+1] = temp;// or firse usko uski value dedo -- for more check my bubble sort revise

//             }

//         }

//     }

// }

// void insrtionSort(int *A, int n){
//     int key, j;
//     for (int i = 0; i < n-1; i++)
//     {
//         key = A[i];
//         j = i - 1;
//        while (j>=0 && key> A[j])
//         {
//             if(key> A[j]){
//                 A[j+1] = A[j];
//                 j--;
//             }
//         }
//         key = A[j+1];

//     }

// }

// void selectionSort (int *A, int n){
//     int indexOfmin = 0;
//     int temp;
//     for (int i = 0; i < n-1; i++)
//     {
//         indexOfmin = i;
//         for (int j = i+1; j < n-1; j++)
//         {
//            if (A[j]<A[indexOfmin])
//            {
//            indexOfmin = j;
//            }

//         }
//         temp = A[i];
//         A[i] = A[indexOfmin];
//         A[indexOfmin]= temp;
//     }

// }

// int partition (int *A, int low, int high){
//     int pivot = A[low];
//     int i = low+1;
//     int j = high;
//     int temp;

//        do
//        {
//          while(A[i]<=pivot){
//             i++;
//            }
//         while(A[j]>=pivot){
//             j--;

//         }
//         if (i<j)
//         {
//             temp = A[i];
//             A[i] = A[j];
//             A[j] = temp;
//         }
//         /* code */
//        }while (i<j);

//             temp = A[low];
//             A[low] = A[j];
//             A[j] = temp;
//      return j;

// }

// void quickSort(int *A, int low, int high){
//     int partionIndex;
//     if (low<high){
//         partionIndex = partition(A, low, high);
//         quickSort(A, low, partionIndex-1);
//         quickSort(A, partionIndex+1, high);
//     }
// }

int maximum(int *A, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A, int n)
{
    int max = maximum(A, n);
    int i, j;
    int * count = new int[max + 1];

    for (i = 0; i < n; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0;
    j = 0;

    while (i <= max + 1)
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

    // // int A[] = {12, 45, 33, 66, 88};
    // int A[] = {12, 25, 33, 66, 88};
    // int n = 5;
    // printArray(A, n);
    // bubbleSort(A, n);
    // cout << "Array after the bubble sorting" << endl;
    // printArray(A, n);
    // return 0;

    // int A[] = {23, 45, 67, 22, 35, 14};
    // int n = 6;
    // printArray(A, n); //Array before the insertion sort Algorithm
    // cout<<"Array after the bubble sorting"<<endl;
    // insrtionSort(A, n);
    // printArray(A, n);

    // int A[] = {23, 15, 67, 43, 33, 87};
    // int n = 6;

    // printArray(A, n); //array befor the sort
    // selectionSort(A, n);
    //  printArray(A, n); //array after the sorting

    // int A[] = {23, 45, 67, 22, 35, 14};
    // int n = 6;
    // printArray(A, n); // Array before the insertion sort Algorithm
    // cout << "Array after the Quick sorting" << endl;
    // quickSort(A, 0, n - 1);
    // printArray(A, n);

    int A[] = {23, 15, 67, 43, 33, 87, 6, 9};
    int n = 8;

    printArray(A, n); // array befor the sort
    cout << "Array after the count sorting" << endl;
    countSort(A, n);
    printArray(A, n); // array after the sorting

    return 0;
}
