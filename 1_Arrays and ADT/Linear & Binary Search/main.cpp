#include <iostream>
using namespace std;
//linear search use traversal method to visit the elements present in the array for find the specific element
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found, return -1
}

int main()
{  
    //unsorted array for the linear searh also can work for the sorted
    //its worst case is Bigoh O(n)
    int arr[] = {10, 15, 6, 8, 9, 6, 4, 33, 77};
    int size = 9, element = 9;
    
    int searchIndex = linearSearch(arr, size, element);

    if (searchIndex != -1)
    {
        cout << "The element " << element << " found at index: " << searchIndex << endl;
    }
    else
    {
        cout << "The element " << element << " not found in the array." << endl;
    }

    return 0;
}
