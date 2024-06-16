#include <iostream>
using namespace std;

void Display(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
       cout<<arr[i]<<endl;
    }
}

  
  void indDeletion(int arr[],int size, int index){
    // if (size>= capacity){
    //     cout<<"invalid";
    // }else if (size<=capacity || index <= capacity)
    // {
       for (int i = index; i < size; i++)
       {
       arr[i] = arr[i + 1];
       }
  
};



int main (){
    // 5 size - idx 0  1  2  3   4  -- loop for deletion -- index - 1 => size -1(4)
    int arr[100] = {1, 3, 7, 8, 14};
    int size = 5, element = 15, index = 2;
    cout<<"array before the deletion"<<endl;
    Display(arr, size);
    indDeletion(arr, size, index);
    cout<<"array after the deletion"<<endl;
    size -=1;
    Display(arr, size);

}