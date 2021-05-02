#include "Graph.h"
#include "HashTable.h"

void deleteUser(Graph G, int user) {
    PtrUserNode P = G->UserArray[user]; // P is the struct at the user index
    if(P->Isvalid) { // if User is present
        Table T = P->InVertices;
        for(int i = 0; i < T->size; i++) { // traverses thorugh the invertices table
            if(T->Bucket[i] == NULL) {
                continue;
            } else {
                NodePtr P = T->Bucket[i];
                while(P != NULL) {
                    deleteUserOut(G, P->Elem, user); // deletes user from the outvetex lis of P->Elem
                    P = P->Next;
                }
            }
        }
        DeleteTable(T);
        P->InVertices = NULL;

        // same but for outvertices
        T = P->OutVertices;
        for(int i = 0; i < T->size; i++) {
            if(T->Bucket[i] == NULL) {
                continue;
            } else {
                NodePtr P = T->Bucket[i];
                while(P != NULL) {
                    deleteUserIn(G, P->Elem, user);
                    P = P->Next;
                }
            }
        }

        DeleteTable(T);
        P->OutVertices = NULL;

        DeleteUserNode(P->User); // currently a dummy function
        P->Isvalid = false;
    }
}

// goes to the user u and deletes the user v from outvertices
void deleteUserOut(Graph G, int u, int v) {
    Table T = G->UserArray[u]->OutVertices;
    RemoveElement(T, v);
}

// goes to the user u and deletes the user v from invertices
void deleteUserIn(Graph G, int u, int v) {
    Table T = G->UserArray[u]->InVertices;
    RemoveElement(T, v);
}