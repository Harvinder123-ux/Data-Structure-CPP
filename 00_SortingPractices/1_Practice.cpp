#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<< A[i] << endl;
    }
}

// void bubbleSort(int *A, int n){
//     int temp;
//     for (int i = 0; i <= n-1; i++)
//     {
//         for (int j = 0; j < n-1-i; j++)
//         {
//            if(A[j]>A[j+1]){
//             temp = A[j];
//             A[j] = A[j+1];
//             A[j+1] = temp;
//            }
//         }

//     }

// }

// void insertionSort(int *A, int n)
// {
//     int key, j;
//     for (int i = 1; i <= n - 1; i++)
//     {
//         key = A[i];
//         j = i - 1;
//         while (j >= 0 && A[j] > key)
//         {
//             A[j + 1] = A[j];
//             j--;
//         }
//         A[j + 1] = key;
//     }
// }

// void selectionSort(int *A, int n)
// {
//     int indexOfmin, temp;
//     for (int i = 0; i <= n - 1; i++)
//     {
//         indexOfmin = i;
//         for (int j = i + 1; j <n-1; j++)
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

// int partition(int A[], int low, int high){
//     int pivot = A[low];
//     int i = low+1;
//     int j = high;
//     int temp;

//     do// while (A[i]<= pivot)
//     {
//         while (A[i]<=pivot)
//         {
//            i++;
//         }
//         while (A[j]>=pivot)
//         {
//            j--;
//         }
//         if (i<j)
//         {
//            temp = A[i];
//            A[i] = A[j];
//            A[j] = temp;
//         }
        
//     }while (i<j);
//            temp = A[low];
//            A[low] = A[j];
//            A[j] = temp;
//            return j;

// }

// void QuickSort (int A[], int low, int high){
//     int partionIndex;
//      if (low < high)
//     {
//     partionIndex = partition(A, low, high);
//     QuickSort(A, low, partionIndex-1);
//     QuickSort(A, partionIndex+1, high);

//     }

// }


// void merge (int A[], int mid, int low, int high){
//     int i, j, k, B[high+1];
//     i = low;
//     j = mid+1;
//     k = low;

//     while (i<=mid && j<=high)
//     {
//         if (A[i]<=A[j])
//         {
//             B[k] = A[i];
//             i++; k++;
//         } 
//         else 
//         {
//               B[k] = A[j];
//               j++; k++;

//         }   
//     }
//     while (i<=mid)
//     {
//         B[k] = A[i];
//         i++; k++;
//     }
//     while (j<=high)
//     {
//         B[k] = A[j];
//         j++; k++;
//     }
    
//     for (int i = low; i <= high; i++)
//     {
//         A[i] = B[i];
//     }
    
    
// }

// void mergeSort (int A[], int low, int high){
//     int mid;
//     if (low<high)
//     {
//       mid = (low + high)/2;
//       mergeSort(A, low, mid);
//       mergeSort(A, mid+1, high);
//       merge(A, mid, low, high);
//     }
    
// }


int main()
{
    // int A[] = {5, 55, 7, 64, 9, 19};
    // int n=6;
    // // printArray(A, n);//array before the sorting
    // bubbleSort(A, n);//function for sort array
    // // cout<<"Array After The bubble Sorting"<<endl;
    // printArray(A, n);//array before the sorting

    // int A[] = {23, 45, 67, 22, 35, 14};
    // int n = 6;
    // printArray(A, n); //Array before the insertion sort Algorithm
    // cout<<"Array after the Insertion sorting"<<endl;
    // insertionSort(A, n);
    // printArray(A, n);

    // int A[] = {23, 15, 67, 43, 33, 87};
    // int n = 6;

    // printArray(A, n); // array befor the sort
    // cout << "Array after the selection sorting" << endl;
    // selectionSort(A, n);
    // printArray(A, n); // array after the sorting
    


    

    // int A[] = {23, 45, 67, 22, 35, 14};
    // int n = 6;
    // printArray(A, n); // Array before the insertion sort Algorithm
    // cout << "Array after the Quick sorting" << endl;
    // QuickSort(A, 0, n - 1);
    // printArray(A, n);

    
    int A[] = {23, 15, 67, 43, 33, 87, 6, 9};
    int n = 8;

    printArray(A, n); // array befor the sort
    cout << "Array after the merge sorting" << endl;
    mergeSort(A, 0, n-1);
    printArray(A, n); // array after the sorting



    return 0;
}

