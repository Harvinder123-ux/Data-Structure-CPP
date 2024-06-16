#include <iostream>
using namespace std;

void printArray(int * A, int n){
    for (int i = 0; i < n; i++)
    {
      cout<<A[i]<<" ";
      cout<<endl;
    }
    
}

void insertionSort (int *A, int n){
    int key, j;
    //uska pehla element hum sort samj kar hi chalte hai
    for (int i = 1; i <= n-1; i++)
    {
       key = A[i];
       j = i-1;
       while (j>=0 && A[j]>key)
       {
        A[j+1] = A[j];
        j--;
       }
       A[j+1] = key;
       
    }
    
}

int main(){
     int A[] = {23, 45, 67, 22, 35, 14};
    int n = 6;
    printArray(A, n); // Array before the insertion sort Algorithm
    cout << "Array after the insertion sorting" << endl;
    insertionSort(A, n);
    printArray(A, n);

    return 0;
}