#include "dequeue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node *Newnode()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    assert(newnode != NULL);

    return newnode;
}
deque push(type data1)
{
    deque nn = Newnode();

    nn->data1 = data1;
    //nn->data2 = data2;
    if (front == NULL)
    {
        rear = front = nn;
    }
    else
    {
        nn->next = front;
        front->prev = nn;
        front = nn;
    }
}
deque inject(type data1)
{
    deque nn = Newnode();

    nn->data1 = data1;
    //nn->data2 = data2;
    if (rear == NULL)
    {
        front = rear = nn;
    }
    else
    {
        nn->prev = rear;
        rear->next = nn;
        rear = nn;
    }
}
void pop()
{
    // deque temp=front;
    if (front == NULL)
    {
        printf("empty list");
    }
    else
    {
        deque temp=front;
        //temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        else
        {
            front->prev = NULL;
        }
        free(temp);
    }
}
void eject()
{
    //deque temp=rear;
    if (front == NULL)
    {
        printf("empty list");
    }
    else
    {
        deque temp = rear;
        rear = rear->prev;
        if (rear == NULL)
        {
            front = NULL;
        }
        else
        {
            rear->next = NULL;
        }
        free(temp);
    }
    //free(temp);
}
void print(deque front)
{
    deque temp=front;
    while (temp != NULL)
    {
        printf("%.2lf\n",temp->data1);
        temp=temp->next;
    }
}
