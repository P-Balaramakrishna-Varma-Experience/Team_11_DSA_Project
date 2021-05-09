#include "../Header/AllModule.h" 

void ResizeHeap(MinHeap H);
int MIN(int a, int b, int c);
bool Is25Full(MinHeap H);
bool IsFull(MinHeap H);
void AdjustTop(MinHeap H);
//return very large number in case does not exits
int lchildH(int n, MinHeap H);
int RchildH(int n, MinHeap H);
int ParentH(int n, MinHeap H);

MinHeap Init_min_heap()
{
    MinHeap H;

    H = malloc(sizeof(struct MinHeapS));
    if (H == NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }

    H->LastIndex = -1;
    H->MaxSize = InitalSize_Heap;
    H->Heap = malloc(InitalSize_Heap * sizeof(int));

    if (H->Heap == NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }

    return H;
}

// Dobules or halves appropriately.
void ResizeHeap(MinHeap H)
{
    int New_Size;

    if (IsFull(H))
        New_Size = H->MaxSize * 2;
    else if (Is25Full(H))
        New_Size = H->MaxSize / 2 + 1;
    else //called by mistake
        return;

    H->Heap = realloc(H->Heap, New_Size * sizeof(int));
    if (H->Heap == NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }

    H->MaxSize = New_Size;
}

bool IsFull(MinHeap H)
{
    return (H->LastIndex == H->MaxSize - 1);
}

bool Is25Full(MinHeap H)
{
    return (H->LastIndex <= H->MaxSize / 4);
}

void Delete_min_heap(MinHeap *A) // do not send a null//test by valgrind.
{
    if (*A == NULL)
    {
        printf("Passing null to Deleteminheap\n");
        exit(0);
    }

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
    {
        printf("You are asking least element of a empty min heap\n");
        exit(0);
    }

    return A->Heap[0];
}

bool IsEmpty(MinHeap A)
{
    return (A->LastIndex == -1);
}

void RmLeastNum(MinHeap A)
{
    if (IsEmpty(A))
    {
        printf("You trying to remove least element of a empty min heap\n");
        exit(0);
    }
    //A is not empty

    if (A->LastIndex == 0)
    {
        A->LastIndex = -1;
        return;
    }
    // A is not empty and contains more than one element

    A->Heap[0] = A->Heap[A->LastIndex];
    A->LastIndex--;
    AdjustTop(A);
}

//heapify but only on top. all elements are distinct assumes.
void AdjustTop(MinHeap H)
{
    int pNode = 0;
    // current local 3 tree.

    while (pNode <= H->LastIndex)
    {
        int left, right;
        left = (lchildH(pNode, H) != INT_MAX) ? H->Heap[lchildH(pNode, H)] : INT_MAX;
        right = (RchildH(pNode, H) != INT_MAX) ? H->Heap[RchildH(pNode, H)] : INT_MAX;

        int min = MIN(H->Heap[pNode], left, right);

        if (min == H->Heap[pNode]) // termination case
            break;

        //swaping
        int Next;

        if (min == left)
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

void AddNum(int a, MinHeap H)
{
    if (IsFull(H) || Is25Full(H))
        ResizeHeap(H);

    // Heap array no change
    H->LastIndex++;
    H->Heap[H->LastIndex] = a;
    //Heap array conatins a at lst element

    int Pnode = H->LastIndex;

    while (Pnode > 0)
    {
        if (H->Heap[Pnode] > H->Heap[ParentH(Pnode, H)]) // min heap property is satisfied.
            break;

        // paretn larger than child i must swap to hold min heap propery locally.
        int tem = H->Heap[Pnode];
        H->Heap[Pnode] = H->Heap[ParentH(Pnode, H)];
        H->Heap[ParentH(Pnode, H)] = tem;

        Pnode = ParentH(Pnode, H); // index for next iteration.
    }
}

//when indexed lchild /rchild / Parent may cause segmentation fault./test for valididty.
int lchildH(int n, MinHeap H)
{
    int estimate = 2 * n + 1;

    if (estimate <= H->LastIndex && estimate >= 0)
        return estimate;
    else
        return INT_MAX;
}

int RchildH(int n, MinHeap H)
{
    int estimate = 2 * n + 2;

    if (estimate <= H->LastIndex && estimate >= 0)
        return estimate;
    else
        return INT_MAX;
}

int ParentH(int n, MinHeap H)
{
    int estimate = (n - 1) / 2;

    if (estimate >= 0 && estimate <= H->LastIndex)
        return estimate;
    else
        return INT_MAX;
}

int MIN(int a, int b, int c)
{
    //a and b and c are distinct
    if (a < b && a < c)
        return a;
    if (b < c && b < a)
        return b;
    if (c < b && c < a)
        return c;

    // eror
    //this propogates to cause a segmentation fault.
    return -10;
}
