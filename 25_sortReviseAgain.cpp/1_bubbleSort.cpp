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

// //bubble Sort Program
// void bubbleSort(int *A, int n)
// {
//     int temp;
//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j < n - 1 - i; j++)
//         {
//             if (A[j] > A[j + 1])
//             {
//                 temp = A[j];
//                 A[j] = A[j + 1];
//                 A[j + 1] = temp;
//             }
//         }
//     }
// }

// //insertion Sort
// void insertionSort(int *A, int n){
//     int temp;
//     int key;
//     int j;
//     for (int i = 0; i < n; i++)
//     {
//         key = A[i];
//         j = i - 1;
//         while (j>= 0 && A[j] > key)
//         {
//             A[j+1] = A[j];
//             j--;
//         }
//         A[j+1] = key;

//     }

// }

// // selection sort
// void selectionSort(int *A, int n)
// {
//     int temp;
//     int indexOfmin;

//     for (int i = 0; i < n - 1; i++)
//     {
//         indexOfmin = i;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (A[j] < A[indexOfmin])
//             {
//                 indexOfmin = j;
//             }
//         }

//         temp = A[i];
//         A[i] = A[indexOfmin];
//         A[indexOfmin] = temp;
//     }
// }

///Quick Sort
// int partition(int *A, int low, int high)
// {
//     int temp;
//     int pivot = A[low];
//     int i = low + 1;
//     int j = high;

//     do
//     {
//         while (A[i] < pivot)
//         {
//             i++;
//         }
//         while (A[j] > pivot)
//         {
//             j--;
//         }
//         if (i < j)
//         {
//             temp = A[i];
//             A[i] = A[j];
//             A[j] = temp;
//         }

//     } while (i < j);
//     temp = A[low];
//     A[low] = A[j];
//     A[j] = temp;
//     return j;
// }

// void QuickSort(int *A, int low, int high)
// {
//     int partionIndex;
//     if (low < high)
//     {
//         partionIndex = partition(A, low, high);
//         QuickSort(A, low, partionIndex - 1);
//         QuickSort(A, partionIndex + 1, high);
//     }
// }


//mergeSort


int main()
{

    int A[] = {3, 25, 12, 8, 9, 5};
    int n = 6;
    printArray(A, n);
    cout << "Array after the quick sorting" << endl;
    // bubbleSort(A, n);
    // insertionSort(A, n);
    // selectionSort(A, n);
    QuickSort(A, 0, n-1);
    printArray(A, n);
    return 0;
}