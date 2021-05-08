#ifndef MIN_HEAP
#define MIN_HEAP

#include "AllModule.h" 

#define InitalSize_Heap 10

typedef int *PtrInt;
typedef struct MinHeapS *MinHeap;

struct MinHeapS
{
    int MaxSize;
    int LastIndex;
    PtrInt Heap;
};

/*
    MinHeap: type is a pointer varible. (it stores the address of "minheap struct") 
    MinHeapS.MaxSize: current size of the array .. (for rellocting memory)
    MinHeapS.LastIndex: index of the last elemnt in the array. (start from 0) -1 if empty
    MinHeapS.Heap... pointer to the array.
*/

MinHeap Init_min_heap();
// Crates a minheap structure and returns its address.

void Delete_min_heap(MinHeap *A);
// free the memory of the minheap structure pointed by the value stored in parameter and make it point to null

void Print_min_heap(MinHeap A);
//Print the Heap

int LeastNum(MinHeap A);
// returns the value of the root of minheap (if empty exits the program).

void RmLeastNum(MinHeap A);
//removes the root of minheap

void AddNum(int a, MinHeap H);
// Add an number into the minheap

bool IsEmpty(MinHeap A);

#endif