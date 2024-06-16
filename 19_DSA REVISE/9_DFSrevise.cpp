#include <iostream>
using namespace std;

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int i = 0;
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
    cout << i << " ";
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && visited[j] == 0)
        {
            DFS(j);
        }
    }
}

int main()
{
    DFS(0);
    return 0;
}