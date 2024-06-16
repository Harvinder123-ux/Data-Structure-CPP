#include <iostream>
#include <limits.h>
using namespace std;

void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout<<A[i]<<" ";
    }
    cout<<endl;
    
}

int maximum(int *A, int n){
    //find the maximum element in the array
    int max = INT_MIN;
     for (int i = 0; i < n; i++)
    {  
       if( max < A[i]){
       max = A[i];
       }
    }
    return max;

}

void countSort(int *A, int n){
   int i,  j;
   int max = maximum(A, n);

   //ceate the count array dynamically
   int * count = new int[max + 1];
   for (i = 0; i < n; i++)
    { 
        //initializ all the elements with the zero to entire all the arrray
        count[i] = 0; 
    }
     //increment the elements with the count array index correspondingly
    for ( i = 0; i < n; i++)
    { 
       
        count[A[i]]= count[A[i]]+1; //
    }

    i = 0; //counter for the count array
    j = 0; //counter for the given array (A)

    while (i<=max+1)
    {
        if(count[i] > 0){
            A[j] = i; //copy the index in main array
            count[i] = count[i] - 1;
            j++;
        }else {
          i++;
        }
       
    }
    
    
   
    

}

int main (){
     
    
    int A[] = {23, 15, 67, 43, 33, 87, 6, 9};
    int n = 8;

    printArray(A, n); // array befor the sort
    cout << "Array after the count sorting" << endl;
    countSort(A, n);
    printArray(A, n); // array after the sorting

    return 0;
}



