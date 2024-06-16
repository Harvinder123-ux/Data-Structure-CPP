#include <iostream>
using namespace std;

void arrTraverse(int arr[], int size)
{
    for (int i = 0; i <= size - 1; i++)
    {
        cout << arr[i] << " ";
    }
}

// int idxInsertion(int arr[], int size, int element, int capacity, int index)
// {
//     if (size > capacity || index > size)
//     {
//         return -1;
//     }
//     else if (size < capacity || index < size)
//     {
//         for (int i = size; i >= index; i--)
//         {
//             arr[i] = arr[i - 1];
//         }
//         arr[index] = element;
//         return 1;
//     }
// }

int idxdeletion(int arr[], int size, int index)
{

    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
    }
    return 1;
}

int main()
{
    const int capacity = 100;
    int arr[capacity] = {1, 2, 7, 9, 10}; // reserved space 100 contiguous block
    int size = 5, element = 7, index = 3;
    // idxInsertion(arr, size, element, capacity, index);
    // int InsertionResult = idxInsertion(arr, size, element, capacity, index);

    // if (InsertionResult == -1)
    // {
    //     cout << "Array is Full! fail to insert the element ";
    // }
    // else if (InsertionResult == 1) // Fixed the loop condition
    // {
    //     cout << "Inserted the element Sucessfully" << endl;
    //     cout << "Array before the insertion:" << endl;
    //     arrTraverse(arr, size);
    //     size += 1;

    //     cout << "Array after the insertion:" << endl;
    //     arrTraverse(arr, size);
    // }

    // deletion
    //  cout<<"array before the deletion"<<endl;
    //  arrTraverse(arr, size);
    //  idxdeletion(arr, size, index);
    //  cout<<"array after the deletion"<<endl;
    //  size -=1;
    arrTraverse(arr, size);

    // binary search
    int searchIndex = binarySearch(arr, size, element);

    if (searchIndex != 1)
    {
        cout << "The element " << element << " found at index: " << searchIndex << endl;
    }
    else
    {
        cout << "The element " << element << " not found in the array." << endl;
    }

    return 0;
}