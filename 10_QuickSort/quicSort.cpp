#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {

        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] >= pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i<j);

 
        temp = A[low];
        A[low] = A[j];
        A[j] = temp;
        return j;
}


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


void QuickSort(int A[], int low, int high)
{
    int partionIndex;

    if (low < high)
    {
        partionIndex = partition(A, low, high);
        QuickSort(A, low, partionIndex - 1);
        QuickSort(A, partionIndex + 1, high);
    }
}

int main()
{

    int A[] = {23, 45, 67, 22, 35, 14};
    int n = 6;
    printArray(A, n); // Array before the insertion sort Algorithm
    cout << "Array after the Quick sorting" << endl;
    QuickSort(A, 0, n - 1);
    printArray(A, n);
    // i will look for big and j will look for the low

    // lets demonstrate this
    //  23pivot, 45, 67, 22, 35, 14

    // 23, 45i, 67, 22, 35, 14j
    //     i->              <-j

    // 23,  14i, 67, 22, 35, 45j - ist result
    //           i-><-j

    // 23,  14i, 22i,67j, 35, 45j
    //           i-><-j

    // 23,  14i, 22j,67i, 35, 45  -- 2nd result
    //           <-j i->
    // now swap pivot A[low] to A[j] coz the i and j cross

    //[22,  14i], 23pivot,[67, 35, 45]
    //    [67p,35, 45]
    // [22p, 14]                i-><-j
    // [67p,35, 45]
    //       ij                <-j i->
    // swap hoga pivot and j
    // [35,65, 45]
    // [65p, 45]
    // ij
    // swap
    //[14, 22]    [23]      [45, 65]
    // 23, 45, 67, 22, 35, 14

    return 0;
}