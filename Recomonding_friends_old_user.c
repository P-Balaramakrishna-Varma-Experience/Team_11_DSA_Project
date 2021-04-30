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

struct recommondation
{
    int id;
    int level;
};
typedef struct recommondation *recommondation;

int *Friends_Recomandation_old_user(Graph G, int Start, int K);
void BFS(Graph G, int start, recommondation *Array, int K);
void Randomize(recommondation *A, int K, int *Ans);
void Work(Tree T, ptrQUE Q, int color[], int level);
void ForAll(Tree T, ptrQUE Q, int pColor[], void operation(Tree, ptrQUE, int *, int), int level);
void Randomizeij(recommondation A[], int i, int j, int *Ans);
void DeleteRecommondationArray(recommondation *a, int K);

int *Friends_Recomandation_old_user(Graph G, int Start, int K)
{
    //intializing A
    recommondation *A = malloc(sizeof(recommondation) * K);

    // Storing the nodes in preference of distance.
    BFS(G, Start, A, K);

    int *Ans = malloc(sizeof(int) * K);

    Randomize(A, K, Ans);

    DeleteRecommondationArray(A, K);
    return Ans;
    // It is the user resposibility to free the memory of the array.
}

void BFS(Graph G, int start, recommondation *Array, int K)
{
    //creating the Array to store the colours.
    int N = G->LastId + 1;
    int *pColour = (int *)malloc(N * sizeof(int));
    assert(pColour != NULL);

    // Initialize all nodes to white/not visited
    for (int i = 0; i <= G->LastId; i++)
        pColour[i] = WHITE;

    //starting the breath first search with the first node.
    ptrQUE Q;
    pColour[start] = GRAY; // Gray nodes are added to the queue
    Q = makeQUE();

    recommondation Start = {start, 0};
    Enqueue(Q, Start);

    //Progressing the BFS
    recommondation u, v;
    int Last_index = -1; // index of last element strored in Array (size K)

    while (!IsQueueEmpty(Q))
    {
        u = Dequeue(Q);

        ForAll(G->UserArray[u->id]->OutVertices, Q, pColour, Work, u->level + 1);

        pColour[u->id] = BLACK;

        if (Last_index == K - 1) // the list is full.
            break;

        if (Last_index != K - 1 && !Friend(start, u->id) && u->id != start) // check friendship.
        {
            Last_index++;
            Array[Last_index] = u;
        }
    }

    free(pColour);
    deleteQUE(Q);
    // que is empty // or found K friends
    //either case the BFS work is over.
    return;
}

void ForAll(Tree T, ptrQUE Q, int pColor[], void operation(Tree, ptrQUE, int *, int), int level)
{
    if (T != NULL)
    {
        ForAll(T->left, Q, pColor, operation, level);
        operation(T, Q, pColor, level);
        ForAll(T->right, Q, pColor, operation, level);
    }
}

void Work(Tree T, ptrQUE Q, int color[], int level)
{
    //T != Null.
    int p = T->id;
    if (color[p] == WHITE)
    {
        color[p] = GRAY; // Gray nodes are added to the queue

        recommondation P = malloc(sizeof(recommondation));
        P->id = p;
        P->level = level;

        Enqueue(Q, P);
    }
}

void DeleteRecommondationArray(recommondation *a, int K)
{
    for (int i = 0; i < K; i++)
    {
        free(a[i]);
    }
    free(a);
    // not using double pointers due to over confusio.
}

void Randomizeij(recommondation *A, int i, int j, int *Ans) //int k is reduntand
{
    //asume srand is intialized;
    int ranNum;

    for (int loop = i; loop <= j; loop++)
    {
        ranNum = rand() % (j - i + 1) + i;

        recommondation temp = A[loop];
        A[loop] = A[ranNum];
        A[ranNum] = temp;
    }

    for (int loop = i; loop <= j; loop++)
    {
        Ans[loop] = A[loop]->id;
    }
}

void Randomize(recommondation *A, int K, int *Ans)
{
    int plevel = 2;
    int startlevel_index = 0;

    for (int i = 0; i < K; i++)
    {
        if (plevel == A[i]->level)
            continue;
        else
        {
            plevel = A[i]->level;
            Randomizeij(A, startlevel_index, i - 1, Ans);
            startlevel_index = i;
        }
    }
}