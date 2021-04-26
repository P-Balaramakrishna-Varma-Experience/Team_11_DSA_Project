#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Queues.h"
#include <assert.h>
#include "graph_bst.h"

#define WHITE 0
//not visited not in que
#define GRAY 1
//in que not visited
#define BLACK 2
//visited

int *Friends_Recomandation_old_user(Graph G, int Start, int K);
void BFS(Graph G, int start, int *Array, int K);
void Randomize(int A[], int K);
void Work(Tree T, QUE Q, int color[]);
void ForAll(Tree T, QUE Q, int pColor[], void operation(Tree, QUE, int *));
void Randomizeij(int A[],int K , int i , int j);

int *Friends_Recomandation_old_user(Graph G, int Start, int K)
{
    //intializing A
    int *A = malloc(sizeof(int) * K);

    // Storing the nodes in preference of distance.
    BFS(G, Start, A, K);

    return A;
    // It is the user resposibility to free the memory of the array.
}

void BFS(Graph G, int start, int *Array, int K)
{
    //creating the Array to store the colours.
    int N = G->LastId + 1;
    int *pColour = (int *)malloc(N * sizeof(int));
    assert(pColour != NULL);

    // Initialize all nodes to white/not visited
    for (int i = 0; i <= G->LastId; i++)
        pColour[i] = WHITE;

    //starting the breath first search with the first node.
    QUE Q;
    pColour[start] = GRAY; // Gray nodes are added to the queue
    Q = CreateEmptyQueue();
    Enqueue(Q, start);

    //Progressing the BFS
    int u, v;
    int L = -1; // index of last element strored in Array (size K)

    while (!IsQueueEmpty(Q))
    {
        u = Dequeue(Q); 

        ForAll(G->UserArray[u],Q,pColour,Work);

        pColour[u] = BLACK;

        if (L == K - 1) // the list is full.
            break;

        if (L != K - 1 && !Friend(start, u)) // check friendship.
        {
            L++;
            Array[L] = u;
        }
    }

    free(pColour);
    deleteQUE(&Q);
    // que is empty // or found K friends
    //either case the BFS work is over.
    return;
}

void ForAll(Tree T, QUE Q, int pColor[], void operation(Tree, QUE, int *))
{
    if (T != NULL)
    {
        ForAll(T->left, Q, pColor, operation);
        operation(T, Q, pColor);
        ForAll(T->right, Q, pColor, operation);
    }
}

void Work(Tree T, QUE Q, int color[])
{
    int p = T->id;
    if (color[p] == WHITE)
    {
        color[p] = GRAY; // Gray nodes are added to the queue
        Enqueue(Q, p);
    }
}