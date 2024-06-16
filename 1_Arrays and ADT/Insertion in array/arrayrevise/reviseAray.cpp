#include <iostream>
using namespace std;


void displayArr(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
       cout<<arr[i]<<endl;
    }
    
};

// int insertElement(int*arr, int capacity, int size, int element, int index){
    
//     if (size>= capacity)
//     {
//         return -1;
//     }else if (size<=capacity || size<=index){

//         for (int i = size; i >= index; i--)
//         {
//             arr[i] = arr[i-1];
//         }
//         arr[index] = element;
//         return 1;
        
        
//     }
    
    
// };

// int deleteElement (int *arr, int size, int index){
//     for (int i = index; i < size; i++)
//     {
//         arr[i] = arr[i+1];
//     }
//     return 1;
// }


int linearSearch (int *arr, int size, int element){
   for (int i = 0; i < size; i++)
   {
    if (arr[i] == element)
    {
       return i;
    }
   }
   return -1;

}

int BinarySearch (int *arr, int size, int element){
    int mid, low, high;
    low = 0;
    high = size-1;
    while (low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == element){
            return mid;
        } else if (arr[mid] < element){
            low = mid+1;
        }else if (arr[mid] > element){
            high = mid-1;
        }
    }
    return -1;

}




int main(){
    
    int capacity = 100;
    int arr[capacity] = {1, 2, 7, 9, 10}; // reserved space 100 contiguous block
    int size = 5, element = 10, index = 7;
    displayArr(arr, size);
    // insertElement(arr, capacity, size, element, index);
    // size += 1;
    // displayArr(arr, size);

    // deleteElement(arr, size, index);
    // size -= 1;
    // displayArr(arr, size);


    // int searchIndex = linearSearch(arr, size, element);

    // if (searchIndex != -1)
    // {
    //     cout << "The element " << element << " found at index: " << searchIndex << endl;
    // }
    // else
    // {
    //     cout << "The element " << element << " not found in the array." << endl;
    // }

    
    int searchIndex = BinarySearch(arr, size, element);

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
