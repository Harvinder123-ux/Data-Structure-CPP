#include <iostream>
using namespace std;

void traverse(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "<<endl;
    }
}

void bubbleSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        //cout << "working on pass numbers" << i + 1 << endl;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


// void bubbleSort(int *A, int n){
//     int temp;
//     for (int i = 0; i < n-1; i++)//for number of pass
//     {
//         for ( int j = 0; j < n-1-i; j++)//used for compare the each element array in passes
//         {
//            if(A[j]>A[j+1]){
//             temp = A[j];
//             A[j] = A[j+1];
//             A[j+1] = temp;
//            }
//         }
        
//     }
    
// }

int main()
{
    int arr[] = {34, 56, 33, 22, 10, 7};
    int n = 6;

    traverse(arr, n);
    bubbleSort(arr, n);
    cout << "array after the bubble sort"<<endl;
    traverse(arr, n);

    return 0;
}