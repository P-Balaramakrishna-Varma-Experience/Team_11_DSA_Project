#ifndef __MY_DEQUE__
#define __MY_DEQUE_

typedef double type;
typedef struct node *deque;
deque front,rear;

struct node
{
    type data1;
    struct node *next;
    struct node *prev;
};
deque push(type data1);
deque inject(type data1);
void pop();
void eject();
void print(deque front);
struct node * Newnode();

#endif