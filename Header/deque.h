#ifndef __MY_DEQUE__
#define __MY_DEQUE__

#include "AllModule.h"
typedef struct NodeDq *Deque;

struct NodeDq
{
    struct NodeDq *next;
    struct NodeDq *prev;
    GElementType val1;
    //GElementType val2;
};
Deque front, rear;

void display(Deque front);
struct NodeDq *New();
void push(GElementType val1);
void inject(GElementType val1);
GElementType pop();
GElementType eject();
void DeleteDeque();
void PrintGElemType(GElementType X);

#endif