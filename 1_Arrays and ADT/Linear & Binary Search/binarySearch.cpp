#include <iostream>
using namespace std;

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
//Binary search is the one of the most efficent way to find the element in big arrays the only condition is there the array must be sorted.
//Also binary search Use log for dividing the array elements from low to high then find mid
//its worst case is the bigoh O(logn)
int BinarySearch(int arr[], int size, int element)
{ 
    int mid, low, high;
    low = 0;
    high = size-1;

    //Searhing Start -- and keep searchin until the low<=high.
    while (low<=high){
         mid = (low + high)/2;
          if (arr[mid] == element){
        return mid;
    } else if (arr[mid] < element){
        low = mid+1;
    }else if (arr[mid] > element){
        high = mid-1;
    }
    }
    //Search End
return -1;
}

int main()
{   //Sorted array For binary Search
    int arr[] = {6, 8, 9, 10, 15, 33, 77};
    int size = 9, element = 15;
    
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
