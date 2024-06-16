#include <iostream>
using namespace std;

// void loopSFunction (int n){
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//            cout<<"*";
//         }
//         cout<<endl;
//     }

// }

// multipication table
//  void multipicationTable (){
//      int n = 10;
//  for (int i = 1; i <= 10; i++)
//  {
//      for (int j = 1; j <= 10; j++)
//      {
//         cout<<i*j<<'\t';
//      }
//      cout<<endl;
//  }

// }

// multipication table with the single loop
void singleLoop(int UserInput)
{   
    int val = 0;
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        val  = val + UserInput;
        cout<<val<<endl;
    }
   
}

int main()
{
    // loopSFunction(6);
    // multipicationTable();
    singleLoop(7);
   
   
    return 0;
}