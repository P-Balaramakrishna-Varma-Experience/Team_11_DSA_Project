#ifndef __queue__
#define __queue__

typedef struct queues* que;

struct queues 
{
    int a;
    struct queues* next;

};

que init();
void push(que N,int s);
void eject(que N);
void print(que N);


#endif