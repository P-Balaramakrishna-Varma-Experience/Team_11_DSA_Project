#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"
#include"graph_bst.h"

void AddEdge(int A, int B, Graph G)
{

    void*FOUND=FindID(G->UserArray[A]->OutVertices,B);

    if (FOUND==NULL)
    {
        InsertNode(G->UserArray[A]->OutVertices, B);
        InsertNode(G->UserArray[B]->InVertices, A);
    }

    return;
}

void DeleteEdge(int A, int B, Graph G)
{
    void*FOUND=FindID(G->UserArray[A]->OutVertices,B);

    if (FOUND!=NULL)
    {
        DeleteNode(G->UserArray[A]->OutVertices, B);
        DeleteNode(G->UserArray[B]->InVertices, A);
    }

    return;
}

