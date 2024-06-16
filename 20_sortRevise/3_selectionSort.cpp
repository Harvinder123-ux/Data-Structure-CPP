#include <iostream>
using namespace std;

void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
    {
       cout<<A[i]<<endl;
    }
    
}

void selectionSort(int* A, int n){
    int indexOfmin;
    int temp;
    
    for (int i = 0; i < n-1; i++)
    {
        indexOfmin = i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j]< A[indexOfmin])
            {
               indexOfmin = j;
               j++;
            }
            
        }
        temp = A[i];
        A[i] = A[indexOfmin];
        A[indexOfmin] = temp;
    }
    
}
int main(){     
        //yaad rakhna hum A[i] loop mein har baar k pehle element ko minimum bta rahe hai or baad mein j loop mein find minimum index value ke saath swap 
        //kar rahe hai
    

       //idxofMin = 23 i=0; like in theory we suppose the first index of array is minimum then compare them
     //idxofMin = 15 j=1;


     //input array
     //        |00, 01, 02, 03, 04, 05
    //         |23, 15, 67, 43, 33, 87

    //after ist pass
     //        00,| 01, 02, 03, 04, 05
    //         15,| 23, 67, 43, 33, 87


    //after 2nd pass
     //        00, 01,| 02, 03, 04, 05
    //         15, 23,| 67, 43, 33, 87

    
    //after 3rd pass
     //        00, 01, 02,| 03, 04, 05
    //         15, 23, 33,| 43, 67, 87

    //array sorted btw it will compare until the n-1 passes


    int A[] = {23, 15, 67, 43, 33, 87};
    int n = 6;

    printArray(A, n); //array befor the sort
    cout<<"after selection sort"<<endl;
    selectionSort(A, n);
    printArray(A, n); //array after the sorting

    return 0;
}