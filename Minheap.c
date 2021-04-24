#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

#include "Minheap.h"

void ResizeHeap(MinHeap H);
bool IsFull(MinHeap H);
void AdjustTop(MinHeap(H));
//return very large number in case does not exits
int lchildH(int n, MinHeap H);
int RchildH(int n, MinHeap H);
int ParentH(int n, MinHeap H);

MinHeap Init_min_heap()
{
    MinHeap H;

    H = malloc(sizeof(struct MinHeapS));
    H->LastIndex = -1;
    H->MaxSize = InitalSize_Heap;
    H->Heap = malloc(InitalSize_Heap * sizeof(int));

    return H;
}

void ResizeHeap(MinHeap H)
{
    int New_Size = H->MaxSize * 2;

    H->Heap = realloc(H->Heap, 2 * New_Size);
    assert(H->Heap != NULL);

    H->MaxSize = New_Size;
}

bool IsFull(MinHeap H)
{
    return H->LastIndex == H->MaxSize - 1;
}

void Delete_min_heap(MinHeap *A)
{
    MinHeap H = *A;

    free(H->Heap);
    free(H);

    *A = NULL;
}

void Print_min_heap(MinHeap A)
{
    printf("\n");
    for (int i = 0; i <= A->LastIndex; i++)
        printf("%d  ", A->Heap[i]);
    printf("\n");
}

int LeastNum(MinHeap A)
{
    if (IsEmpty(A))
        return -11111;

    return A->Heap[0];
}

void RmLeastNum(MinHeap A)
{
    assert(!IsEmpty(A));
    //A is not empty

    if (A->LastIndex = 0)
    {
        A->LastIndex = -1;
        return;
    }
    // A is not empty and contains more than one element
    A->Heap[0] = A->Heap[A->LastIndex];
    A->LastIndex--;
    AdjustTop(A);
}

void AdustTop(MinHeap H)
{
    int pNode = 0;

    while (pNode <= H->LastIndex)
    {
        int min = MIN(H->Heap[pNode], H->Heap[lchildH(pNode, H)], H->Heap[RchildH(pNode, H)]);

        if (min == H->Heap[pNode]) // termination case
            break;

        //swaping
        int Next;

        if (min == H->Heap[lchildH(pNode, H)])
            Next = lchildH(pNode, H);
        else
            Next = RchildH(pNode, H);

        int temp = H->Heap[Next];
        H->Heap[Next] = H->Heap[pNode];
        H->Heap[pNode] = temp;

        //next iter .
        pNode = Next;
    }
}

bool IsEmpty(MinHeap A)
{
    return A->LastIndex == -1;
}

void AddNum(int a, MinHeap H)
{
    if (IsFull(H))
        ResizeHeap(H);

    H->LastIndex++;
    H->Heap[H->LastIndex] = a;

    int Pnode = H->LastIndex;

    while (Pnode > 0)
    {
        if (H->Heap[Pnode] > H->Heap[ParentH(Pnode, H)])
            break;

        // paretn larger than child i must swap to hold min heap propery
        int tem = H->Heap[Pnode];
        H->Heap[Pnode] = H->Heap[ParentH(Pnode, H)];
        H->Heap[ParentH(Pnode, H)] = H->Heap[Pnode];
    }
}

int lchildH(int n, MinHeap H)
{
    int estimate = 2 * n + 1;

    if (estimate <= H->LastIndex)
        return estimate;
    else
        return INT_MAX;
}

int RchildH(int n, MinHeap H)
{
    int estimate = 2 * n + 2;

    if (estimate <= H->LastIndex)
        return estimate;
    else
        return INT_MAX;
}

int ParentH(int n, MinHeap H)
{
    int estimate = (n - 1) / 2;

    if (estimate >= 0)
        return estimate;
    else
        return INT_MAX;
}