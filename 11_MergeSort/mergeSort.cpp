#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

void mergeSortprocedure(int A[], int mid, int low, int high)
{
    int i, j, k, B[high + 1];
    i = low;
    j = mid + 1;
    k = low;
    //this loop - jabtak i scan karte hue mid tak nahi chala jata hai and j scan karte hue high tak tab tak scan karte raho
    while (i <= mid && j <= high)
    {   
        //compare - agar A[i] mein value small hai A[j] se then new array mein A[i] ki value dalo and i++ also k++;
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        // we can use else too
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    //     Base Case (Termination Condition):

    // As the algorithm progresses through recursive calls, the range of elements to be sorted becomes smaller. The condition if (low < high) acts as a termination condition or base case for the recursion.
    // When the range has only one element (i.e., low is equal to high), the condition becomes false, and the recursion stops. This is because a single element is already considered sorted.
    {
        mid = (low + high) / 2; // if low mean i = 0 index and high is to 3 mean mid is 1 in c
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        mergeSortprocedure(A, mid, low, high);
    }
}

int main()
{

    int A[] = {23, 15, 67, 43, 33, 87, 6, 9};
    int n = 8;

    printArray(A, n); // array befor the sort
    cout << "Array after the merge sorting" << endl;
    mergeSort(A, 0, n - 1);
    printArray(A, n); // array after the sorting

    return 0;
}

//reference - for understanding more
//check my dsa revise file in documents