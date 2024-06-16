#include <iostream>
#include <limits.h>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << A[i] << " ";
    }
    cout << endl;
}
// void bubbleSort(int*A, int n){
//     int temp;
//     for (int i = 0; i < n-1; i++)
//     {
//         for (int j= 0; j < n-1-i; j++)
//         {   //agar Array ka first element bda hai 2nd element se
//             if(A[j]>A[j+1]){
//             temp = A[j]; //toh first element ki value store kro temporary variable mein and 
//             A[j] = A[j+1];// usko ek kadam age le jao
//             A[j+1] = temp;// or firse usko uski value dedo -- for more check my bubble sort revise

//             }
           
//         }
        
//     }
    
// }

void insrtionSort(int *A, int n){
    //key is our first element of A[i]
    //j hamare key ke piche hoga
    //jabtak hamara j zero se bada hai our key agar chotti hai j se toh yeh compare honge or swap bhi piche jaa ja kr
    //lekin last element ko compare karte index j = i-1 jayega tabhi last one par set karne ke liye //A[j+1] = key likhe hai
    int key, j;
    for (int i = 1; i <= n-1; i++)
    {   
        key = A[i];
        j = i - 1;
       while (j>=0 && key> A[j])
        {
                A[j+1] = A[j];
                j--;
        }
        A[j+1] = key;
        
    }
    
}



int main()
{
    
    // // int A[] = {12, 45, 33, 66, 88};
    // int A[] = {12, 25, 33, 66, 88};
    // int n = 5;
    // printArray(A, n);
    // bubbleSort(A, n);
    // cout << "Array after the bubble sorting" << endl;
    // printArray(A, n);
    // return 0;

    
    int A[] = {23, 45, 67, 22, 35, 14};
    int n = 6;
    printArray(A, n); //Array before the insertion sort Algorithm
    cout<<"Array after the bubble sorting"<<endl;
    insrtionSort(A, n);
    printArray(A, n);
    // int A[] = {23, 15, 67, 43, 33, 87, 6, 9};
    // int n = 8;

    // printArray(A, n); // array befor the sort
    // cout << "Array after the count sorting" << endl;
    // countSort(A, n);
    // printArray(A, n); // array after the sorting

    return 0;
}
