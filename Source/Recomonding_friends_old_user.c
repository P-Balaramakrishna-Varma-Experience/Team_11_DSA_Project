#include <stdio.h>
#include <stdlib.h>
#include "../Header/Graph.h"
#include "../deque.h"
#include <assert.h>
#include "../Header/HashTable.h"

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
int BFS(Graph G, int start, recommondation *Array, int K);
void Randomize(recommondation *A, int K, int *Ans);
void Randomizeij(recommondation A[], int i, int j, int *Ans);
void DeleteRecommondationArray(recommondation *a, int K);
void PrintAnsArray(int* Array,int N);

void Friends_Recomandation_old_user(Graph G, int Start, int K)
{
    //is start valid?
    if (G->UserArray[Start] == NULL)
    {
        printf("Your recommemding friends to a user who is not there is %d(ID)\n\n", Start);
        Print_Graph(G);
        exit(0);
    }



    recommondation *A = malloc(sizeof(recommondation) * K);

    // Storing the nodes in preference of distance.
    int No_of_friends = BFS(G, Start, A, K);

    int *AnsArray = malloc(sizeof(int) * No_of_friends);
    Randomize(A, No_of_friends, AnsArray);

    DeleteRecommondationArray(A, K);

    PrintAnsArray(AnsArray,No_of_friends);

    free(AnsArray);
    return;
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
    pColour[start] = GRAY; // Gray nodes are added to the queue
    front = rear = NULL;  ////  Q = makeQUE();

    recommondation Start = {start, 0};
    inject(Start);      //pushing into que

    //Progressing the BFS
    recommondation u, v;
    int Last_index = -1; // index of last element strored in Array (size K)

    while (!IsQueueEmpty(Q))
    {
        u = pop();
        Table Neighbours = G->UserArray[u->id]->OutVertices;

        for (int i = 0; i < Neighbours->NumElems; i++) //iterating to all buckets
        {
            NodePtr Pnode = Neighbours->Bucket[i]->Next; // first value in bucket i;
            while (Pnode != NULL)
            {
                if (pColour[Pnode->Elem] == WHITE)
                {
                    pColour[Pnode->Elem] = GRAY;
                    recommondation P = malloc(sizeof(recommondation));
                    P->id = Pnode->Elem;
                    P->level = u->level + 1;
                    inject(P);    //push into a que
                }

                Pnode = Pnode->Next;
            }
        }

        pColour[u->id] = BLACK;

        if (Last_index == K - 1) // the list is full.
            break;

        if (Last_index != K - 1 && !checkfriendship(G,start, u->id) && u->id != start) // check friendship.
        {
            Last_index++;
            Array[Last_index] = u;
        }
    }

    free(pColour);
    DeleteDeque();
    return Last_index + 1;
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

void PrintAnsArray(int* A,int N)
{
    for(int i = 0 ; i < N ; i++)
    {
        printf("%d ",A[i]);
    }
}