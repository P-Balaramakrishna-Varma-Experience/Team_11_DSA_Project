#ifndef __MY_DEQUE__
#define __MY_DEQUE_

typedef struct Node *Deque;

struct Node
{
    struct Node *next;
    struct Node *prev;
    double val1;
    //double val2;
};
Deque front, rear;

void display(Deque front);
struct Node *New() ;
Deque push(double val1) ;
void pop() ;
void eject() ;

#endif