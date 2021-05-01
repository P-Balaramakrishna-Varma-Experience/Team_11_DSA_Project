#include <stdio.h>
#include <stdlib.h>

#include "Minheap.h"

void main()
{
   /* 1  MinHeap H = Init_min_heap();
    Print_min_heap(H);
    Delete_min_heap(&H); */

    /* MinHeap H = Init_min_heap();
    for(int i = 20 ; i > 0 ; i--) // part 2b
    for(int i = 0 ; i < 20 ; i++) // part 2a
    {
        AddNum(i,H);
    }
    Print_min_heap(H);
    printf("%d--LastId %d --size\n",H->LastIndex,H->MaxSize);
    Delete_min_heap(&H);

 */    // 1 && 2 ==> Delete_min_heap()(no memory leak),Print_min_heap()(no branching etc), Init_min_heap()(sequential once coorect all correct); is correct.
    // 2a && 2b ==> AddNum is true.


    // verified 5/6 (is empty is trivial).

    /* 3 MinHeap H = Init_min_heap();
    for(int i = 0 ; i < 20 ; i++) // part 2a
    {
        AddNum(i,H);
    }
    Print_min_heap(H);
    printf("%d--LastId %d --size\n",H->LastIndex,H->MaxSize);
    for(int i = 0 ; i < 20 ; i++)
    {
        printf("%d--minvalue--iter %d--i\n",LeastNum(H),i);
        RmLeastNum(H);
        Print_min_heap(H);
    }
    Delete_min_heap(&H);
   */  
    // 3 ==> LeastNum(),RmLeastNum() are correct;

}