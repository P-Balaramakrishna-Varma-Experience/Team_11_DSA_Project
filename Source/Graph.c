#include "../Header/AllModule.h" 


Graph Init_Graph(int n)
{
    Graph G = (Graph)malloc(sizeof(GraphS)); // allocates memory for Graph
    G->MAX_Size = n;
    G->UserArray = (PtrUserNode *)calloc(n, sizeof(PtrUserNode));

    return G;
}

Graph ResizeGraph(Graph G)
{
    int fact = 5; // currently fact is set to 5 i.e resizes to 5 times the current size
    int n = G->MAX_Size;
    G->UserArray = (PtrUserNode *)realloc(G->UserArray, fact * n * sizeof(PtrUserNode)); // reallocs the memory of array of G
    assert(G->UserArray != NULL);
    G->MAX_Size = fact * n;                                                              // updates the size variable
    return G;
}

void DeleteGraph(Graph *GP)
{
    Graph G = *GP;
    for (int i = 0; i < G->MAX_Size; i++)
    {
        if (G->UserArray[i] != NULL)
        { // if the user exists
            PtrUserNode P = G->UserArray[i];
            DeleteTable(P->InVertices);  // deletes the invertex table
            DeleteTable(P->OutVertices); // deletes the otvertex table
            DeleteUserNode(&(P->User));  // deletes the profile struct
            free(P);
        }
    }
    free(G->UserArray);
    free(G);
    *GP = NULL;
}

void Print_Graph(Graph G)
{
    for (int i = 0; i < G->MAX_Size; i++)
    {
        if (G->UserArray[i] != NULL)
        {
            PtrUserNode P = G->UserArray[i];
            printf("\nFriend List of %dth user\n", P->ID);
            // PrintTable(P->OutVertices);
            Table T = P->OutVertices;
            for (int i = 0; i < T->size; i++)
            {
                if (T->Bucket[i] == NULL)
                {
                    continue;
                }
                else
                {
                    NodePtr P = T->Bucket[i];
                    // printf("%d: ", i);
                    while (P != NULL)
                    {
                        printf("%d ", P->Elem);
                        P = P->Next;
                    }
                    // printf("\n");
                }
            }
        }
    }
}

/* Utility Function */

void DeleteUserNode(PtrUser *U)
{
    free(*U);
    *U = NULL;
}