#include <iostream>
using namespace std;

class myArray
{
public:
    int total_size;
    int used_size;
    int *ptr;

public:
    void createArray(myArray *a, int tsize, int uSize)
    {
        // (*a).total_size = tsize;
        // (*a).used_size =  uSize;
        // (*a).ptr = new int[(tsize*sizeof(int))];
        a->total_size = tsize;
        a->used_size = uSize;
        a->ptr = new int[tsize];
    }
};

void show(myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        cout << (a->ptr[i]) << endl;
    }
}

void setValue(myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        cout << "enter the element " << i << endl;
        cin >> n;
        (a->ptr[i]) = n;
    }
}

int main()
{

    myArray marks;
    marks.createArray(&marks, 10, 2);
    setValue(&marks);
    show(&marks);

    return 0;
}
