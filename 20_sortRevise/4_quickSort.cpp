#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i]<<" ";
    }
    cout<<endl;
}



int partition(int *A, int low, int high)
{
    int temp;
    int pivot = A[low];
    int i = low + 1;
    int j = high;

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

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}



void QuickSort(int *A, int low, int high)
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

    return 0;
}