#include <iostream>
using namespace std;

void displayArr(int arr[], int n)
{ // Traversal
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int idxInsertion(int arr[], int size, int element, int capacity, int index)
{
    // INSERTION
    if (size >= capacity || index > capacity)
    {
        return -1;
    }
    else if (index < size || size < capacity)
    {
        for (int i = size; i >= index; i--) // Fixed the loop condition
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        return 1;
    }
}

int main()
{
    const int capacity = 100;
    int arr[capacity] = {1, 2, 7, 9, 10}; // reserved space 100 contiguous block
    int size = 5, element = 15, index = 5;
    idxInsertion(arr, size, element, capacity, index);
    int InsertionResult = idxInsertion(arr, size, element, capacity, index);
    // INSERTION RESULTS - Modified
    if (InsertionResult == -1)
    {
        cout << "Array is Full! fail to insert the element ";
    }
    else if (InsertionResult == 1) // Fixed the loop condition
    {
        cout << "Inserted the element Sucessfully" << endl;
        cout << "Array before the insertion:" << endl;
        displayArr(arr, size);
        size += 1;

        cout << "Array after the insertion:" << endl;
        displayArr(arr, size);
    }

    return 0;
}
