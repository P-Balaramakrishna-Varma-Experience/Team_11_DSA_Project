#include<stdio.h>
#include<stdlib.h>
#include"QUEUES.h"

que init()
{
    que x=(que)malloc(sizeof(struct queues));
    x->a=999;
    x->next=NULL;
    return x;
}

void push(que N,int s)
{
    que h;
    h=init();
    h->a=s;
    h->next=N->next;
    N->next=h;
}

void eject(que N)
{
    que p;
    while(N->next->next!=NULL)
    {
        N=N->next;
    }
    free(N->next);
    N->next=NULL;
}

void print(que N)
{
    N=N->next;
    while(N->next!=NULL)
    {
        printf("%d->",N->a);
        N=N->next;
    }
    printf("%d ",N->a);
    printf("\n");
}