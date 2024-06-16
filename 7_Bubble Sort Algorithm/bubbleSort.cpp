#include <iostream>
using namespace std;

//void printArray(int[] A, int n){
void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
       cout<<A[i]<<endl;
    }
    
}

void bubbleSort(int *A, int n){
    int temp;
    for (int i = 0; i < n-1; i++)//for number of pass
    {
        for ( int j = 0; j < n-1-i; j++)//used for compare the each element array in passes
        {
           if(A[j]>A[j+1]){
            temp = A[j];
            A[j] = A[j+1];
            A[j+1] = temp;
           }
        }
        
    }
    
}

// //how To make Adaptive
// void bubbleSort(int *A, int n){
//     int temp;
//     int isSorted = 0;
//     for (int i = 0; i < n-1; i++)//for number of pass
//     {   cout<<"working on pass numbers"<<i+1<<endl;
//         isSorted = 1; //hum jaha par isko bol rahe hai ki yeh already sorted hai agar yeh agli condition mein jaata hai toh yeh sorted nhi hai
//         for ( int j = 0; j < n-1-i; j++)//used for compare the each element array in passes
//         {
//         //    cout<<"working on pass comparing numbers"<<endl;
//            if(A[j]>A[j+1]){
//             temp = A[j];
//             A[j] = A[j+1];
//             A[j+1] = temp;
//             isSorted =0;//return 0 if is not sorted
//            }
//         }
//         if(isSorted){
//             return;//function band hojayega agar hamara array already sorted hua without any pass of compare k mean j loop k
//         }
        
//     }
    
// }

int main(){

    // int A[] = {14, 43, 15, 22, 77, 33};

    //how to make this adaptive - look at this 
    int A[] = {5, 34, 7, 6, 9, 10};
    int n=6;
    // printArray(A, n);//array before the sorting
    bubbleSort(A, n);//function for sort array
    // cout<<"Array After The bubble Sorting"<<endl;
    printArray(A, n);//array before the sorting



    return 0;
}