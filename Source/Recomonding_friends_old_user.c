#include "../Header/AllModule.h"

#define WHITE 0
//not visited not in que
#define GRAY 1
//in que not visited
#define BLACK 2
//visited

void Friends_Recomandation_old_user(Graph G, int Start, int K);
int BFS(Graph G, int start, recommondation Array[], int K);
void Randomize(recommondation A[], int K, int Ans[]);
void Randomizeij(recommondation A[], int i, int j, int Ans[]);
void DeleteRecommondationArray(recommondation a[], int K);
void PrintAnsArray(Graph G,int Array[], int N);

void Friends_Recomandation_old_user(Graph G, int Start, int K)
{
    //is start valid?

    if (G->UserArray[Start] == NULL)
    {
        printf("Your recommemding friends to a user who is not there is %d(ID)\n\n", Start);
        Print_Graph(G);
        exit(0);
    }

    recommondation A[K];
    if (A == NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }

    // Storing the nodes in preference of distance.
    int No_of_friends = BFS(G, Start, A, K);
    //printf("\n\n%d\n\n\n",No_of_friends);
    
    /* int *AnsArray = malloc(sizeof(int) * No_of_friends);
    //int *AnsArray = calloc(No_of_friends,sizeof(int));
    if (AnsArray == NULL)
    {
        printf("Out of memory\n");
        exit(0);
    } */
    int AnsArray[No_of_friends];
    for(int i = 0 ; i < No_of_friends; i++)
        AnsArray[i] = 0;

    Randomize(A, No_of_friends, AnsArray);
    PrintAnsArray(G,AnsArray, No_of_friends);
    DeleteRecommondationArray(A, No_of_friends);
    
    //free(AnsArray);
}

int BFS(Graph G, int start, recommondation Array[], int K)
{
    //creating the Array to store the colours.
    int N = G->MAX_Size;
    int *pColour = (int *)malloc(N * sizeof(int));
    assert(pColour != NULL);

    // Initialize all nodes to white/not visited
    for (int i = 0; i < G->MAX_Size; i++)
        pColour[i] = WHITE;

    //starting the breath first search with the first node.
    pColour[start] = GRAY; // Gray nodes are added to the queue

    front = rear = NULL;

    recommondation Start = malloc(sizeof(struct recommondation));
    Start->id = start;
    Start->level = 0;
    inject(Start); //pushing into que
    
    //Progressing the BFS
    recommondation u;
    int Last_index = -1; // index of last element strored in Array (size K)

    while (front != NULL)
    {
        u = pop();
        assert(u->id < 1001);
        Table Neighbours = G->UserArray[u->id]->OutVertices;

        for (int i = 0; i < Neighbours->size; i++) //iterating to all buckets
        {
            NodePtr Pnode = Neighbours->Bucket[i]; // first value in bucket i;
            while (Pnode != NULL)
            {
                if (pColour[Pnode->Elem] == WHITE)
                {
                    pColour[Pnode->Elem] = GRAY;
                    //printf("%d ",Pnode->Elem);
                    recommondation P = malloc(sizeof(struct recommondation));
                    P->id = Pnode->Elem;
                    P->level = u->level + 1;
                    inject(P); //push into a que
                }

                Pnode = Pnode->Next;
            }
        }
        pColour[u->id] = BLACK;

        if (Last_index == K - 1) // the list is full.
            break;

        if (!checkfriendship(G,u->id,start) && u->id != start) // check friendship.
        {
            Last_index++;
            Array[Last_index] = u;
        }
        else
            DeleteGElemType(u);
    }

    free(pColour);
    DeleteDeque();
    return Last_index + 1;
}

 void DeleteRecommondationArray(recommondation a[], int K)
{
    for (int i = 0; i < K; i++)
    {
        free(a[i]);
    }
    // not using double pointers due to over confusio.
} 

void Randomizeij(recommondation A[], int i, int j, int Ans[]) //int k is reduntand
{
    //asume srand is intialized;
    int ranNum;

    for (int loop = i; loop <= j; loop++)
    {
        ranNum = (rand() % (j - i + 1)) + i;

        //swap items at loctions loop and ranNUM
        recommondation temp = A[loop];
        A[loop] = A[ranNum];
        A[ranNum] = temp;
    }

    for (int loop = i; loop <= j; loop++)
    {
        Ans[loop] = A[loop]->id;
    }
}

void Randomize(recommondation A[], int length_of_recomArray, int Ans[])
{
    int plevel = 2;
    int startlevel_index = 0;

    for (int i = 0; i < length_of_recomArray; i++)
    {
        if (plevel == A[i]->level)
            continue;
        else
        {
            plevel = A[i]->level;
            assert(startlevel_index <= i - 1);   //i-
            Randomizeij(A, startlevel_index, i - 1, Ans);
            startlevel_index = i; //next time
        }
    }

    Randomizeij(A,startlevel_index,length_of_recomArray-1,Ans);
}

void PrintAnsArray(Graph G,int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%s %d\n", G->UserArray[A[i]]->User->Name,A[i]);
    }
    printf("\n\n");
}