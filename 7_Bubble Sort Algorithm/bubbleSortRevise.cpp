// #include <iostream>
// using namespace std;

// void printArray(int *A, int n){
//    for (int i = 0; i < n; i++)
//    {
//     cout<<A[i]<<endl;
//    }

// }

// void bubbleSort(int * A, int n){
//     int temp;
//     int isSort = 0;
//     for (int i = 0; i < n-1; i++)
//     {
//        isSort = 1;
//        cout<<"taking the pass for number "<<i<<endl;
//        for (int j = 0; j < n-1-i; j++)
//        {
//         if(A[j]>A[j+1]){
//             temp = A[j];
//             A[j] = A[j+1];
//             A[j+1] = temp;
//             isSort = 0;
//         }
//        }
//       if(isSort){
//           return;

//       };

//     }

// }

// int main(){
//     int A[] = {12, 45, 33, 66, 88};
//     //  int A[] = {12, 25, 33, 66, 88};
//     int n = 5;
//     printArray(A, n);
//     bubbleSort(A, n);
//     cout<<"Array after the bubble sorting"<<endl;
//     printArray(A, n);
//     return 0;
// }

#include <iostream>
using namespace std;
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

void bubbleSort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        /* code */
        for (int j = 0; j < n - 1 - i; j++)
        {
            // its working like this
            //     A[j]>A[j+1]
            // 12, 45,   33, 66, 88

            if (A[j] > A[j + 1])
            {
                // 0         1     2   3   4
                // 12, temp = 45,   33, 66, 88 - pehle toh temp variable mein value(45)store kardo
                temp = A[j];

                // replace the value at j index with A[j+i] mean in this 33
                A[j] = A[j + 1];

                // 3 step mein next index(2) ko replace krdo store value in temp variable
                A[j + 1] = temp;

                // but if still cant understand check this

                // Assume A is an array, and j is an index within the bounds of the array.

                // Step 1: Store the value at index j in a temporary variable (temp).
                // temp = A[j];

                // // Step 2: Replace the value at index j with the value at the next index (j+1).
                // A[j] = A[j + 1];

                // // Step 3: Replace the value at the next index (j+1) with the stored value from Step 1.
                // A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {12, 45, 33, 66, 88};
    //     //  int A[] = {12, 25, 33, 66, 88};
    int n = 5;
    printArray(A, n);
    bubbleSort(A, n);
    cout << "Array after the bubble sorting" << endl;
    printArray(A, n);
    return 0;
}