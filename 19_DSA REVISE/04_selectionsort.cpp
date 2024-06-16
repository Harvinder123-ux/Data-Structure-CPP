#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void selectionSort(int *arr, int n)
{
    int indexOfmin;
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        indexOfmin = i;
        for (int j = i + 1; j< n ; j++)
        {
            if (arr[j] < arr[indexOfmin])
            {
                indexOfmin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexOfmin];
        arr[indexOfmin] = temp;
    }
}

int main()
{
    int arr[] = {45, 2, 57, 22, 10};
    int n = 5;

    printArray(arr, n); // array befor the sort
    selectionSort(arr, n);
    cout<<endl<<"array after the seletion sort"<<endl;
    printArray(arr, n); // array after the sorting

    return 0;
}