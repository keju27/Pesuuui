#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    int size;  //size of the heap
};


MinHeap* init_minheap(int size) {
    MinHeap* minheap = (MinHeap*)calloc(1, sizeof(MinHeap));
    minheap->size = size;
    minheap->arr = (int*)calloc(size, sizeof(int));
    return minheap;
}
void swap(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}

void create_minheap(MinHeap *heap) 
{   
    //IMPLEMENT HERE
    //parent=(i-1)/2
    //node=i
    //leftchild =2i+1
    //rightchild=2i+2
    int ar[heap->size];
    for(int i=0;i<heap->size;i++)
    {
        ar[i]=heap->arr[i];
        if(ar[(i-1)/2]>ar[i])
        {
            swap(ar[(i-1)/2],ar[i]);
            for(int i=0;i<heap->size;i++)
    { 
        printf("%d ",ar[i]);
    }
        }
    }
    for(int i=0;i<heap->size;i++)
    { 
        heap->arr[i]=ar[i];
    }
}





void print_minheap(MinHeap* heap) {
    // IMPLEMENT HERE
    for(int i=0;i<heap->size;i++)
    { 
        printf("%d ",heap->arr[i]);
    }
}

void free_minheap(MinHeap* heap) {
    if (!heap)
        return;
    free(heap->arr);
    free(heap);
}

int main() {

    int capacity; 
    scanf("%d", &capacity);
    MinHeap* heap = init_minheap(capacity); //number of elements 
    int i=0;
    while(i < capacity){
        scanf("%d", &heap->arr[i++]);
    }
    create_minheap(heap);
    print_minheap(heap);
    free_minheap(heap);
    return 0;
}