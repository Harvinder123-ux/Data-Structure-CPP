#include <iostream>
using namespace std;
//function alrerady in built stack ka use karte hei toh new stack implementation ki jarurat nhi h
// maked it global variable
// DFS Implementation
int node;
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int i = 0;

//  //now abb - 7*7 ki ek adjency matrix banao - accordig to our bfs graph is solve kijiye
int a[7][7] = {
    //   0 1 2 3 4 5 6
    {0, 1, 1, 1, 0, 0, 0}, // 0
    {1, 0, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 0}, // 2
    {1, 0, 1, 0, 1, 0, 0}, // 3
    {0, 0, 1, 1, 0, 1, 1}, // 4
    {0, 0, 0, 0, 1, 0, 0}, // 5
    {0, 0, 0, 0, 1, 0, 0}  // 6

};

void DFS(int i)
{
    int j;
    visited[i] = 1;
    cout << i << endl;
    for (int j = 0; j < 7; j++)
    {   //a[i] hamari pehli node hai har array ki usse agar koi bhi next values 1, 1, 1, 0, 0, 0 (in loop term a[j]) == 1 && visited[j] = 0 hot toh
        if (a[i][j] == 1 && visited[j] == 0)
        {
            //agar condion match toh DFS ko firse call karo
            //but iss baaar yeh next j values ke liye chlega
            DFS(j);
        }
        
    }
}
int main()
{
     DFS(0);
      return 0;
}