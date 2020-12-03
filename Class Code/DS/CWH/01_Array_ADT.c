#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size, used_size,*ptr; 
}
array;

void creatArray(struct myArray *a,int tsize,int usize)
{
    // (*a).total_size=tsize;
    // (*a).used_size=usize;
    // (*a).ptr = (int *)malloc(tsize * sizeof(int));

    a -> total_size=tsize;
    a -> used_size=usize;
    a -> ptr = (int *)malloc(tsize * sizeof(int));
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Entered element %d: \n",(a->ptr)[i]);
    }
    
};

void value(struct myArray *a)
{   
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
    
};


void main ()
{
    struct myArray marks;
    creatArray(&marks,10, 2);
    value(&marks);
    show(&marks);    
}