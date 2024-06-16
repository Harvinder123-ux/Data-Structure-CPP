#include <iostream>
using namespace std;

class heap
{
public:
    int Arr[100];
    int size;

    // constructer
    heap()
    {
        Arr[0] = -1;
        int size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        Arr[index] = val;

        while (index > 1) // jabtak hamari index 1 se badi hai yeh loop chalta jayega
        {
            int parent = index / 2; // parent formula hota hai index divided by two - matlab index ka parent waha par hoga
            if (Arr[index] > Arr[parent])
            {
                swap(Arr[parent], Arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteElement()
    {
        Arr[1] = Arr[size];
        size--;

        int i = 1;
        int leftIdx = 2 * i;
        int rightIdx = 2 * i + 1;

        while (i < size)
        {
            if (leftIdx < size && Arr[leftIdx] > Arr[i])
            {
                swap(Arr[leftIdx], Arr[i]);
                i = leftIdx;
            }
            if (rightIdx < size && Arr[i] < Arr[rightIdx])
            {
                swap(Arr[leftIdx], Arr[i]);
                i = rightIdx;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << Arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int *Arr, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && Arr[largest] < Arr[left])
    {
        largest = left;
    }
    if (right <= n && Arr[largest] < Arr[right])
    {
          largest = right;
    }

    if (largest != i)
    {
        swap(Arr[largest], Arr[i]);
        heapify(Arr, n, largest);
    }
}

void printArray(int *Arr, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << Arr[i] << " ";
    }

    cout << endl;
}

void heapSort(int *Arr, int n)
{
    int size = n;
    while (size> 1)
    {
        swap(Arr[1], Arr[size]);
        size--;
        heapify(Arr, size, 1);
       
    }
}

int main()
{
    heap h;
    h.insert(5);
    h.insert(3);
    h.insert(2);
    h.insert(10);

    h.print();

    h.deleteElement();
    h.print();

    // Max Heap
    int Arr[6] = {-1, 54, 55, 53, 52, 50};
    /// jaisa ki bola theory mein ki leaf nodes mean n/2 se lekr n tak leaf hoti hai toh woh already heap hoti hai toh unhe process mean correct position par laane ki jarurat nahi woh already correct posisiton par hai
    // but for the other nodes hum loop chalaenge i = n/2 se lekar 0 tak alse heap ki time complexity hoti hai bigoh(logn)
    // ulta loop
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(Arr, n, i);
    }
    cout << "printing the before the heap sort " << endl;
    printArray(Arr, n);

    // calling the heap sort algo
    heapSort(Arr, n);

    // printing again
    cout << "printing the after the heap sort " << endl;
    printArray(Arr, n);

    return 0;
}