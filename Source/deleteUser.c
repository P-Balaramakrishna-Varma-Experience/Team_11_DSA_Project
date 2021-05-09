#include "../Header/AllModule.h"

/* ************************************************************* *
 * Deletes a user completely from our database                   * 
 * Deletes the user from the friend lists of the concerned users *
 * Deletes the node itself                                       *
 * Updates the heap keeping track of unused ids                  *
 * Takes arguments as the Graph of user, the user to be deleted  *
 * and the heap taking care of the ids                           *
 * ************************************************************* */

void deleteUserOut(Graph G, int u, int v);
void deleteUserIn(Graph G, int u, int v);

void deleteUser(Graph G, int user, MinHeap H)
{
    PtrUserNode P = G->UserArray[user]; // P is the struct at the user index
    if (P != NULL)
    { // if User is present
        Table T = P->InVertices;
        if (T != NULL)
        {
            for (int i = 0; i < T->size; i++)
            { // traverses thorugh the invertices table
                if (T->Bucket[i] == NULL)
                {
                    continue;
                }
                else
                {
                    NodePtr P = T->Bucket[i];
                    while (P != NULL)
                    {
                        deleteUserOut(G, P->Elem, user); // deletes user from the outvetex lis of P->Elem
                        P = P->Next;
                    }
                }
            }
            DeleteTable(T);
        }
        P->InVertices = NULL;

        // same but for outvertices
        T = P->OutVertices;
        if (T != NULL)
        {
            for (int i = 0; i < T->size; i++)
            {
                if (T->Bucket[i] == NULL)
                {
                    continue;
                }
                else
                {
                    NodePtr P = T->Bucket[i];
                    while (P != NULL)
                    {
                        deleteUserIn(G, P->Elem, user);
                        P = P->Next;
                    }
                }
            }

            DeleteTable(T);
        }
        P->OutVertices = NULL;

        DeleteUserNode(&(P->User));
        P->Isvalid = false;

        AddNum(user, H); // updates the heap of ids

        free(P);
        G->UserArray[user] = NULL;
    }
}

/* **************** *
 * Helper functions *
 * **************** */

// goes to the user u and deletes the user v from outvertices
void deleteUserOut(Graph G, int u, int v)
{
    Table T = G->UserArray[u]->OutVertices;
    RemoveElement(T, v);
}

// goes to the user u and deletes the user v from invertices
void deleteUserIn(Graph G, int u, int v)
{
    Table T = G->UserArray[u]->InVertices;
    RemoveElement(T, v);
}