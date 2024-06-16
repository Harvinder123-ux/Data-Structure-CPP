//Implementing array is an abstract data - there are two types of examples you can check the boths
//in this we are storing the value of array in heap using the pointer 
//we took the pointer as the *ptr
//where & is used for the address and *show value address in structure

#include <iostream>
using namespace std;
class myArray {
  public:
    int total_size;
    int used_size;
    int* ptr;

    void createMyArray(myArray*a, int tSize, int uSize){
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = new int[tSize];

  }

};


void setValue (myArray*a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        cout<<"enter the marks of"<<i<<": ";
        cin>>n;
        ((a->ptr)[i]) = n;
    }
    
}

void showValue (myArray*a){
    for (int i = 0; i < a->used_size; i++)
    {
        cout<<((a->ptr)[i])<<endl;
    }
    
}


int main (){
    myArray marks;
    marks.createMyArray(&marks, 10, 3);
    setValue(&marks);
    showValue(&marks);
    return 0;
}




//using the way of public class myArray without void function
// class myArray
// {
// public:
//     int total_size;
//     int used_size;
//     int *ptr;

// public:
//     myArray(myArray*a, int tsize, int uSize) 
//     // total_size(tsize), used_size(uSize)
//     {
//         a->total_size = tsize;
//         a->used_size =  uSize;
//         a->ptr = new int[tsize];
//         // ptr = new int[tsize]; // Using new to allocate memory in C++
                              
//     }
// };

// void show(myArray *a)
// {
//     for (int i = 0; i < a->used_size; i++)
//     {
//         cout << (a->ptr[i]) << endl;
//     }
// }

// void setValue(myArray *a)
// {
//     int n;
//     for (int i = 0; i < a->used_size; i++)
//     {
//         cout << "enter the element" << i << endl;
//         cin >> n;
//         (a->ptr[i]) = n;
//     }
// }

// int main()
// {

//     myArray marks(10, 2);
//     setValue(&marks);
//     show(&marks);

//     return 0;
// }
