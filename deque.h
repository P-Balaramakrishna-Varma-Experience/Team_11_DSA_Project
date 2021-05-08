#ifndef __MY_DEQUE__
#define __MY_DEQUE_

typedef double GElementType;
typedef struct Node *Deque;

struct Node
{
    struct Node *next;
    struct Node *prev;
    GElementType val1;
    //GElementType val2;
};
Deque front, rear;

void display(Deque front);
struct Node *New() ;
Deque push(GElementType val1) ;
Deque inject(GElementType val1);
GElementType pop() ;
GElementType eject() ;
void DeleteDeque();
void PrintGElemType(GElementType X);

#endif