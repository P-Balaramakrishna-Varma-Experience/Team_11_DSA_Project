#include "graph_bst.h"
#include "Graph.h"

void deleteFriendOut(int a, int b); // dummy function for deleting a friend in the outvertices bst 
void deleteFriendIn(int a, int b); // dummy function for deleting a friend in the outvertices bst 

void deleteUser(Graph G, int id) {
    PtrUserNode P = G->UserArray[id];
    if(P->User != NULL) {
        PtrBST B = P->InVertices;
        deleteUserinBST(B, id, deleteFriendOut);
        
        B = P->OutVertices;
        deleteUserinBST(B, id, deleteFriendIn);
        
    }
    free(P->User);
    DeleteTree(&(P->InVertices));
    DeleteTree(&(P->OutVertices));
}

// uses a function pointer to do work for both type of vertices
deleteUserinBST(Tree B, int id, void func(int a, int b)) { 
    if(B != NULL) {
        deleteUserinBST(B->left, id, func); // goes as left as possible
        func(B->id, id); // does the actual work
        deleteUserinBST(B->right, id, func); // goes as right
    }
}