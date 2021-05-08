#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"
#include"HashTable.h"

void AddEdge(int A, int B, Graph G)
{

    void*FOUND=FindID(G->UserArray[A]->OutVertices,B);

    if (FOUND==NULL)
    {
        AddElement(G->UserArray[A]->OutVertices, B);
        AddElement(G->UserArray[B]->InVertices, A);
    }

    return;
}

void DeleteEdge(int A, int B, Graph G)
{
    void*FOUND=FindID(G->UserArray[A]->OutVertices,B);

    if (FOUND!=NULL)
    {
        RemoveElement(G->UserArray[A]->OutVertices, B);
        RemoveElement(G->UserArray[B]->InVertices, A);
    }

    return;
}

