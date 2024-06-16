#include <stdio.h>
#include <stdlib.h>
 
struct myArray
{ 
    int total_size;
    int used_size;
    int *ptr;
};

     
void CreateArray(struct myArray*a,int tsize, int uSize)
    {
        // (*a).total_size = tsize;
        // (*a).used_size =  uSize;
        // (*a).ptr = new int[(tsize*sizeof(int))];
        a->total_size = tsize;
        a->used_size =  uSize;
        a->ptr = (int*)malloc(tsize*sizeof(int));
    

  
    };

 

void show(struct myArray *a){
    for (int i = 0; i <a->used_size; i++)
    {
    printf("%d\n",(a->ptr)[i]);
    }
    
}

 
void setValue(struct myArray *a){
    int n;
    for (int i = 0; i <a->used_size; i++)
    {
    printf("enter the element %d",i);
      scanf("%d", &n);
     (a->ptr[i]) = n;
    }
    
}


int main()
{

    struct myArray marks;
    CreateArray(&marks, 10, 2);
    printf("we are running set value now\n");
    setValue(&marks);
     printf("we are running print value now\n");
    show(&marks);

    return 0;
}